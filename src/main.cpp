#include <iostream>
#include <fstream>
#include <string>
#include <cstdlib>
#include "../include/lexer.hpp"

int main(int argc, char** argv)
{ 
    Lexer lexer;
    std::ifstream input_file_stream(argv[1], std::ios::in);
    std::ofstream output_file_stream(argv[2], std::ios::out);
    std::pair<std::string, std::string> token;

    if (argc < 3) {
        std::cout << "ERROR: one file path is missing..."
            << std::endl;
        exit(EXIT_FAILURE);
    }

    if (!input_file_stream.is_open()
            || !output_file_stream.is_open()) {
        std::cout << "ERROR in opening the files..."
            << std::endl;
        exit(EXIT_FAILURE);
    }

    std::cout << "Running the lexical analysis..." << std::endl;
    while (input_file_stream.peek() != EOF) {
        token = lexer.next_token(input_file_stream);
        output_file_stream << token.first 
            << ", " 
            << token.second
            << std::endl;
    }
    std::cout << "Done!" << std::endl
        << "You can find the output file in" << argv[2]
        << std::endl;

    input_file_stream.close();
    output_file_stream.close();
    return 0;
}
