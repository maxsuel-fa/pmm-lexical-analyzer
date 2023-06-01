/**
 **/
#pragma once
#include <fstream>
#include <functional>

class Scanner {
public:
    // Constructors
    Scanner(void) = default;
    Scanner(std::ifstream&);

    // Common methods
    std::string tokenize(void);

    // Setters and Getters
    void file_stream(const std::ifstream&);

private:
    std::ifstream& file_stream_;
    void consume_whitespace(void);
    void consume_comment(void);
    std::string process_chain(std::function<bool(std::ifstream&)>);
};


