/**
 **/
#pragma once
#include <fstream>

class Scanner
{
public:
    Scanner(void) = default;
    Scanner(std::ifstream&);
    std::string next_lexeme(void);

private:
    std::ifstream& file_stream_;
    bool is_separator(const char&);
    bool is_comment(const char&);
    void consume_whitespace(void);
    void consume_comment(void);
};
