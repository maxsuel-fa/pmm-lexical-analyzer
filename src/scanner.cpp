#include <iostream>

#include "../include/scanner.hpp"
#include "../include/utils.hpp"

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
std::string Scanner::tokenize()
{
    // Ignore initial white spaces
    Scanner::consume_whitespace();

    // Consume comment
    if (utils::is_comment(file_stream_.peek())) {
        Scanner::consume_comment();
    }

    std::string lexeme;

    // If the lexeme is a separator, returns it
    if (utils::is_separator(file_stream_)) {
        return Scanner::process_chain(utils::is_separator);
    }

    // If the lexeme is a operator, returns it
    if (utils::is_operator(file_stream_)) {
        return Scanner::process_chain(utils::is_operator);
    }

    // If the lexeme is a literal, integer or float, returns it
    if (utils::is_digit(file_stream_)) {
        lexeme = Scanner::process_chain(utils::is_digit);
        if(file_stream_.peek() != '.')  {
            return lexeme;
        }
        lexeme.push_back(file_stream_.get());
        if (utils::is_digit(file_stream_)) {
            lexeme.append(Scanner::process_chain(utils::is_digit));
            return lexeme;
        }
        return lexeme;
    }

    // If the lexeme is an identifier or a keyword
    if (utils::is_letter(file_stream_)) {
        return Scanner::process_chain(utils::is_alphanumeric);
    }

    lexeme.push_back(file_stream_.get());
    return lexeme;
}

/**
 * TODO
 **/
void Scanner::consume_whitespace()
{
    while (utils::is_whitespace(file_stream_.peek())) {
        file_stream_.get();
    }
}

/**
 * TODO
 **/
void Scanner::consume_comment()
{
    char temp;
    while ((temp = file_stream_.get()) != '}')
        ;
    Scanner::consume_whitespace();
}

/**
 * TODO
 **/ 
std::string Scanner::process_chain(std::function<bool(std::ifstream&)> f)
{
    std::string lexeme;
    while(!file_stream_.eof()
            && f(file_stream_)) {
        lexeme.push_back(file_stream_.get());
    }
    return lexeme;
}
