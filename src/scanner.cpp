#include "../include/scanner.hpp"
#include <iostream>
/**
 * @brief Given a imput file stream to a pmm source code,
 * constructs a scanner to read lexemes from such source code
 * @param file_stream file stream to a pmm source code
 **/
Scanner::Scanner(std::ifstream& file_stream)
    : file_stream_ { file_stream } {}

/**
 * @brief Gets the next lexeme in the source file
 * @return std::string the next lexeme in the source file
 **/
std::string Scanner::next_lexeme()
{
    // Ignore initial white spaces
    Scanner::consume_whitespace();

    std::string lexeme;

    // If the lexeme is compoused only of a separator, returns it
    if (Scanner::is_separator(file_stream_.peek())) {
        lexeme.push_back(file_stream_.get());
        return lexeme;
    }

    // If the lexeme is compoused only of a operator, returns it
    if (Scanner::is_operator(file_stream_.peek())) {
        while(Scanner::is_operator(file_stream_.peek())) {
            lexeme.push_back(file_stream_.get());
        }
        return lexeme;
    }

    // Consume comment
    if (Scanner::is_comment(file_stream_.peek())) {
        Scanner::consume_comment();
    }

    // Read a lexeme that is neither a separator nor a operator
    while (!file_stream_.eof()
        && !Scanner::is_separator(file_stream_.peek())
        && !Scanner::is_operator(file_stream_.peek())
        && !Scanner::is_whitespace(file_stream_.peek())
        && !Scanner::is_comment(file_stream_.peek())) {
        lexeme.push_back(file_stream_.get());
    }

    return lexeme;
}

/**
 * @brief Verifies if a given character is a separator
 * in the pmm programming language
 * @param ch the character to be verified
 * @return bool true in case ch is a separator or false otherwise
 **/
bool Scanner::is_separator(const char& ch)
{
    if (ch == ':') {
        file_stream_.get();
        const char& temp = file_stream_.peek();
        file_stream_.unget();

        return temp != '=';
    }

    return ch == ','
        || ch == '.'
        || ch == ';'
        || ch == ':'
        || ch == '('
        || ch == ')';
}

/**
 **/
bool Scanner::is_whitespace(const char& ch)
{
    return ch == ' ' || ch == '\n' || ch == '\t';
}

/**
 **/
bool Scanner::is_operator(const char& ch)
{
    if (ch == ':') {
        file_stream_.get();
        const char& temp = file_stream_.peek();
        file_stream_.unget();

        return temp == '=';
    }

    return ch == '+'
        || ch == '-'
        || ch == '*'
        || ch == '/'
        || ch == '>'
        || ch == '<'
        || ch == '=';
}

/**
 **/
bool Scanner::is_comment(const char& ch)
{
    return ch == '{';
}

/**
 **/
void Scanner::consume_whitespace()
{
    while (Scanner::is_whitespace(file_stream_.peek())) {
        file_stream_.get();
    }
}

/**
 **/
void Scanner::consume_comment()
{
    char temp;
    while ((temp = file_stream_.get()) != '}')
        ;
    Scanner::consume_whitespace();
}
