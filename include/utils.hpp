#pragma once

/*
 * TODO
 */
enum class Symbol {
    DIGIT,
    LETTER,
    OPERATOR,
    SEPARATOR,
    START_COMMENT,
    END_COMMENT,
    WHITESPACE,
    DOT,
    STRAY
};

namespace utils {
Symbol next_symbol(std::ifstream&);
char after_next(std::ifstream&);
bool is_separator(std::ifstream&);
bool is_operator(std::ifstream&);
bool is_whitespace(const char&);
bool is_comment(const char&);
bool is_letter(std::ifstream&);
bool is_alphanumeric(std::ifstream&);
bool is_digit(std::ifstream&);
}
