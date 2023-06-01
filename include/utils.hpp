#pragma once

#include <fstream>

namespace utils 
{
char after_next(std::ifstream&);
bool is_separator(std::ifstream&);
bool is_operator(std::ifstream&);
bool is_whitespace(const char&);
bool is_comment(const char&);
bool is_letter(std::ifstream&);
bool is_alphanumeric(std::ifstream&);
bool is_digit(std::ifstream&);
}
