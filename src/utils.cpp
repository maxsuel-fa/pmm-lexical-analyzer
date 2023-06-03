#include "../include/utils.hpp"


/**
 * TODO
 **/
char utils::after_next(std::ifstream& file_stream)
{
    file_stream.get();
    char af_next = file_stream.peek();
    file_stream.unget();

    return af_next;
}

/**
 * @brief Verifies if the next character of a stream is a separator
 * of the pmm programming language
 * @param file_stream the file stream for the source program
 * @return bool true in case the next character is a separator or false
 * otherwise
 **/
bool utils::is_separator(std::ifstream& file_stream)
{
    const char& ch = file_stream.peek();
    if (ch == ':') {
        return after_next(file_stream) != '=';
    }

    return ch == ','
        || ch == ';'
        || ch == ':'
        || ch == '('
        || ch == ')';
}

/**
 * TODO
 **/
bool utils::is_operator(std::ifstream& file_stream)
{
    const char& ch = file_stream.peek();

    return ch == '+'
        || ch == '-'
        || ch == '*'
        || ch == '/'
        || ch == '>'
        || ch == '<'
        || ch == '='
        || (ch == ':' && !is_separator(file_stream));
}

/**
 * TODO
 **/
bool utils::is_whitespace(std::ifstream& file_stream)
{
    const char& ch = file_stream.peek();
    return ch == ' ' || ch == '\n' || ch == '\t';
}

/**
 * TODO
 **/
bool utils::is_start_comment(std::ifstream& file_stream)
{
    const char& ch = file_stream.peek();
    return ch == '{';
}

/**
 * TODO
 **/
bool utils::is_end_comment(std::ifstream& file_stream)
{
    const char& ch = file_stream.peek();
    return ch == '}';
}

/**
 * TODO
 **/
bool utils::is_dot(std::ifstream& file_stream)
{
    const char& ch = file_stream.peek();
    return ch == '.';
}

/**
 * TODO
 **/
bool utils::is_digit(std::ifstream& file_stream)
{
    const char& ch = file_stream.peek();
    // 0 is 48 and 9 is 57 in ascii
    return ch >= 48 && ch <= 57;
}

/**
 * TODO
 **/
bool utils::is_letter(std::ifstream& file_stream)
{
    const char& ch = file_stream.peek();
    return (ch >= 65 && ch <= 90)
        || (ch >= 97 && ch <= 122);
}
