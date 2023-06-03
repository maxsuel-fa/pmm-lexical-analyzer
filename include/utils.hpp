#pragma once

#include <fstream>


namespace utils {
char after_next(std::ifstream&);
bool is_separator(std::ifstream&);
bool is_operator(std::ifstream&);
bool is_whitespace(std::ifstream&);
bool is_start_comment(std::ifstream&);
bool is_end_comment(std::ifstream&);
bool is_dot(std::ifstream&);
bool is_letter(std::ifstream&);
bool is_digit(std::ifstream&);
}
