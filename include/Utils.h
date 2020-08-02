#ifndef CPP_WOL_UTILS_H
#define CPP_WOL_UTILS_H

#include <iostream>

/**
 * Get the string representation of a boolean
 *
 * @param b The boolean
 * @return The string representing the boolean
 */
std::string btos(bool b);

/**
 * Get if a file exists and is readable
 *
 * @param file The file to verify
 * @return True if the file is readable
 */
bool fileExists(const std::string& file);

#endif //CPP_WOL_UTILS_H
