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
 * TODO
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
 * TODO
 **/
bool utils::is_whitespace(const char& ch)
{
    return ch == ' ' || ch == '\n' || ch == '\t';
}

/**
 * TODO
 **/
bool utils::is_start_comment(const char& ch)
{
    return ch == '{';
}

/**
 * TODO
 **/
bool utils::is_end_comment(const char& ch)
{
    return ch == '}';
}

/**
 * TODO
 **/
bool utils::is_dot(const char& ch)
{
    return ch == '.';
}

/**
 * TODO
 **/
bool utils::is_digit(const char& ch)
{
    // 0 is 48 and 9 is 57 in ascii
    return ch >= 48 && ch <= 57;
}

/**
 * TODO
 **/
bool utils::is_letter(const char& ch)
{
    return (ch >= 65 && ch <= 90)
        || (ch >= 97 && ch <= 122);
}
