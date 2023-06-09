#include "../include/utils.hpp"


/**
 * @brief Verifies if the next character of a stream is a separator
 * of the pmm programming language
 * @param file_stream the file stream for the source program
 * @return bool true in case the next character is a separator or false
 * otherwise
 **/
bool utils::is_separator(const char& ch)
{
    return ch == ','
        || ch == ';'
        || ch == '('
        || ch == ')';
}

/**
 * @brief Verifies if the next character of a stream is an operator
 * of the pmm programming language.
 * @param ch the character to be checked
 * @return bool true if the character is an operator, false otherwise
 **/
bool utils::is_operator(const char& ch)
{
    return ch == '+'
        || ch == '-'
        || ch == '*'
        || ch == '/'
        || ch == '>'
        || ch == '<'
        || ch == '='
        || ch == ':';
}

/**
 * @brief Verifies if the next character of a stream is a whitespace character,
 * which includes spaces, newlines, and tabs.
 * @param ch the character to be checked
 * @return bool true if the character is a whitespace character, false otherwise
 **/
bool utils::is_whitespace(const char& ch)
{
    return ch == ' ' || ch == '\n' || ch == '\t';
}

/**
 * @brief Verifies if the next character of a stream is the start of a comment block
 * in the pmm programming language, denoted by '{'.
 * @param ch the character to be checked
 * @return bool true if the character is the start of a comment block, false otherwise
 **/
bool utils::is_start_comment(const char& ch)
{
    return ch == '{';
}

/**
 * @brief Verifies if the next character of a stream is the end of a comment block
 * in the pmm programming language, denoted by '}'.
 * @param ch the character to be checked
 * @return bool true if the character is the end of a comment block, false otherwise
 **/
bool utils::is_end_comment(const char& ch)
{
    return ch == '}';
}

/**
 * @brief Verifies if the next character of a stream is a dot '.'.
 * @param ch the character to be checked
 * @return bool true if the character is a dot, false otherwise
 **/
bool utils::is_dot(const char& ch)
{
    return ch == '.';
}

/**
 * @brief Verifies if the next character of a stream is a digit between 0 and 9,
 * inclusive.
 * @param ch the character to be checked
 * @return bool true if the character is a digit, false otherwise
 **/
bool utils::is_digit(const char& ch)
{
    // 0 is 48 and 9 is 57 in ASCII
    return ch >= 48 && ch <= 57;
}

/**
 * @brief Verifies if the next character of a stream is a letter, either uppercase
 * or lowercase.
 * @param ch the character to be checked
 * @return bool true if the character is a letter, false otherwise
 **/
bool utils::is_letter(const char& ch)
{
    return (ch >= 65 && ch <= 90)  // Uppercase letters (A-Z)
        || (ch >= 97 && ch <= 122);  // Lowercase letters (a-z)
}
