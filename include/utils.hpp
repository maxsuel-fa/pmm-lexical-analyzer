#pragma once

namespace utils {
bool is_separator(const char&);
bool is_operator(const char&);
bool is_whitespace(const char&);
bool is_start_comment(const char&);
bool is_end_comment(const char&);
bool is_dot(const char&);
bool is_letter(const char&);
bool is_digit(const char&);
}
