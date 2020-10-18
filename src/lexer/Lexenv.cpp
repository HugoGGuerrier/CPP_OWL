#include "Lexenv.h"

const char *Lexenv::nameArray[42] = {"BLANK", "SEMICOLON", "DOUBLE_DOT", "COMMA", "DOT", "EQ", "PLUS", "MINUS", "TIMES", "DIVIDE", "LESS", "MORE", "LCURLY", "RCURLY", "LBRACKET", "RBRACKET", "LPAREN", "RPAREN", "CLASS", "PRIVATE", "PROTECTED", "PUBLIC", "PRINT_FUNC", "VOID_TYPE", "BOOL_TYPE", "SHORT_TYPE", "INT_TYPE", "LONG_TYPE", "FLOAT_TYPE", "DOUBLE_TYPE", "CHAR_TYPE", "STRING_TYPE", "ARRAY_TYPE", "NODE_TYPE", "INTERN_TYPE", "TRUE_VAL", "FALSE_VAL", "NULL_VAL", "NUMBER_VAL", "IDENTIFIER", "CHAR_VAL", "STRING_VAL"};

const char Lexenv::stopCharArray[22] = {' ', '\t', '\0', '\n', '\r', ';', ':', ',', '.', '=', '+', '-', '*', '/', '<', '>', '{', '}', '[', ']', '(', ')'};
const int Lexenv::stopCharCode[22] = {Lexenv::BLANK, Lexenv::BLANK, Lexenv::BLANK, Lexenv::BLANK, Lexenv::BLANK, Lexenv::SEMICOLON, Lexenv::DOUBLE_DOT, Lexenv::COMMA, Lexenv::DOT, Lexenv::EQ, Lexenv::PLUS, Lexenv::MINUS, Lexenv::TIMES, Lexenv::DIVIDE, Lexenv::LESS, Lexenv::MORE, Lexenv::LCURLY, Lexenv::RCURLY, Lexenv::LBRACKET, Lexenv::RBRACKET, Lexenv::LPAREN, Lexenv::RPAREN};

const char *Lexenv::regexArray[24] = {R"(class)", R"(private)", R"(protected)", R"(public)", R"(print)", R"(void)", R"(bool)", R"(short)", R"(int)", R"(long)", R"(float)", R"(double)", R"(char)", R"(string)", R"(array)", R"(node)", R"(intern)", R"(true)", R"(false)", R"(null|NULL)", R"(\-?[0-9]+(\.?[0-9])?[0-9]*)", R"([a-zA-Z_][a-zA-Z0-9_]*)", R"(\'.\')", R"(\".*\")"};
const int Lexenv::regexCode[24] = {Lexenv::CLASS, Lexenv::PRIVATE, Lexenv::PROTECTED, Lexenv::PUBLIC, Lexenv::PRINT_FUNC, Lexenv::VOID_TYPE, Lexenv::BOOL_TYPE, Lexenv::SHORT_TYPE, Lexenv::INT_TYPE, Lexenv::LONG_TYPE, Lexenv::FLOAT_TYPE, Lexenv::DOUBLE_TYPE, Lexenv::CHAR_TYPE, Lexenv::STRING_TYPE, Lexenv::ARRAY_TYPE, Lexenv::NODE_TYPE, Lexenv::INTERN_TYPE, Lexenv::TRUE_VAL, Lexenv::FALSE_VAL, Lexenv::NULL_VAL, Lexenv::NUMBER_VAL, Lexenv::IDENTIFIER, Lexenv::CHAR_VAL, Lexenv::STRING_VAL};
regex_t Lexenv::regexTArray[24];
