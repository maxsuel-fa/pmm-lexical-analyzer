#include "../include/scanner.hpp"
#include<iostream>
/**
 * @brief Given a imput file stream to a pmm source code,
 * constructs a scanner to read lexemes from such source code
 * @param file_stream file stream to a pmm source code 
 **/
Scanner::Scanner(std::ifstream& file_stream) 
    : file_stream_ {file_stream} {}

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
    if (Scanner::is_separator(file_stream_.peek()))
    {    
        lexeme.push_back(file_stream_.get());
        return lexeme;
    }

    // Consume comment
    if(Scanner::is_comment(file_stream_.peek()))
    {
        Scanner::consume_comment();
    }

    // Read a lexeme that is not a separator
    while(!file_stream_.eof() 
          && !Scanner::is_separator(file_stream_.peek())
          && !Scanner::is_comment(file_stream_.peek()))
    {
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
    return ch == ' ' 
           || ch == ','
           || ch == '.' 
           || ch == ';'
           || ch == ':'
           || ch == '('
           || ch == ')';
}

bool Scanner::is_comment(const char& ch)
{
    return ch == '{';
}

/**
 **/
void Scanner::consume_whitespace()
{
    char temp;
    while((temp = file_stream_.peek()) == ' ' 
           || temp == '\t' 
           || temp == '\n')
    {
        file_stream_.get();
    }
}

/**
 **/
void Scanner::consume_comment()
{
    char temp;
    while((temp = file_stream_.get()) != '}');
}
