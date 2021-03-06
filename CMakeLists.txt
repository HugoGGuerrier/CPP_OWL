# Init the project and the CMake version
project(cpp_wol)
cmake_minimum_required(VERSION 3.16)

# Set the compile common variable
set(CMAKE_CXX_STANDARD 17)
set(LEXER_DIR ${CMAKE_SOURCE_DIR}/src/lexer)
set(LEXENV_CREATOR_DIR ${LEXER_DIR}/lexenv_creator)

# Set the cmake configuration between prod and dev
if(${CMAKE_BUILD_TYPE} STREQUAL "Debug")
    set(BUILD_FOR_DEV TRUE)
    set(EXECUTABLE_OUTPUT_PATH bin/dev)
else()
    set(BUILD_FOR_DEV FALSE)
    set(EXECUTABLE_OUTPUT_PATH bin/prod)
    set(CMAKE_CXX_FLAGS_RELEASE "-O3")
endif()

# Set the include directory
include_directories(include)

# Compile the lexical environment creator
add_executable(lexenv_creator ${LEXENV_CREATOR_DIR}/LexenvCreator.cpp)
set_target_properties(lexenv_creator PROPERTIES RUNTIME_OUTPUT_DIRECTORY ${LEXENV_CREATOR_DIR})

# Add the custom command to generate the lexical environment
add_custom_command(OUTPUT ${CMAKE_SOURCE_DIR}/src/lexer/Lexenv.cpp ${CMAKE_SOURCE_DIR}/src/lexer/Lexenv.h
        COMMAND "${LEXENV_CREATOR_DIR}/lexenv_creator" ${LEXENV_CREATOR_DIR}/Lexenv.lex ${LEXER_DIR}
        DEPENDS ${LEXENV_CREATOR_DIR}/LexenvCreator.cpp ${LEXENV_CREATOR_DIR}/Lexenv.lex
        COMMENT "Generating the lexical environment...")

# Create the final executable, the WOL interpreter in dev or prod mode
if(${BUILD_FOR_DEV})
    # Set the test directory in the config file
    get_filename_component(BASE_PATH ./ ABSOLUTE)
    configure_file(include/tools/Config.h.temp ${CMAKE_SOURCE_DIR}/include/tools/Config.h)

    # Create the dev executable
    add_executable(cpp_wol src/Main_dev.cpp
            src/Main_common.cpp include/Main_common.h
            src/tools/Config.cpp include/tools/Config.h
            src/tools/Logger.cpp include/tools/Logger.h
            src/tools/Utils.cpp include/tools/Utils.h
            src/tools/Encodings.cpp include/tools/Encodings.h
            src/lexer/Lexenv.cpp src/lexer/Lexenv.h
            src/lexer/Lexer.cpp include/lexer/Lexer.h
            src/lexer/Token.cpp include/lexer/Token.h
            src/vm/VirtualMachine.cpp include/vm/VirtualMachine.h
            src/ast/Program.cpp include/ast/Program.h
            src/vm/FilePool.cpp include/vm/FilePool.h

            include/exceptions/CustomBaseException.h
            include/exceptions/FileException.h
            include/exceptions/LexingException.h

            include/tests/TestBase.h src/tests/TestBase.cpp
            src/tests/TestEngine.cpp include/tests/TestEngine.h
            src/tests/LexerTests.cpp src/tests/LexerTests.h
            src/tests/UtilsTests.cpp src/tests/UtilsTests.h
            include/exceptions/BootstrapException.h)
else()
    # Set the test dir to void
    set(BASE_PATH "void")
    configure_file(include/tools/Config.h.temp ${CMAKE_SOURCE_DIR}/include/tools/Config.h)

    # Create the prod executable
    add_executable(cpp_wol src/Main_prod.cpp
            src/Main_common.cpp include/Main_common.h
            src/tools/Config.cpp include/tools/Config.h
            src/tools/Logger.cpp include/tools/Logger.h
            src/tools/Utils.cpp include/tools/Utils.h
            src/tools/Encodings.cpp include/tools/Encodings.h
            src/lexer/Lexenv.cpp src/lexer/Lexenv.h
            src/lexer/Lexer.cpp include/lexer/Lexer.h
            src/lexer/Token.cpp include/lexer/Token.h
            src/vm/VirtualMachine.cpp include/vm/VirtualMachine.h
            src/ast/Program.cpp include/ast/Program.h
            src/vm/FilePool.cpp include/vm/FilePool.h

            include/exceptions/FileException.h
            include/exceptions/CustomBaseException.h
            include/exceptions/LexingException.h
            include/exceptions/BootstrapException.h)
endif()

# Add the dependency to the lexenv creator
add_dependencies(cpp_wol lexenv_creator)

# Add unit tests to make CI
enable_testing()
add_test(NAME wol_test COMMAND ${EXECUTABLE_OUTPUT_PATH}/cpp_wol -tm -d)
