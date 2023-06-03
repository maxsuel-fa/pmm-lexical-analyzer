#include "../include/lexer.hpp"
#include <fstream>
#include <iostream>

int main(void)
{
    std::ifstream f;
    f.open("./p2.txt", std::ios::in);
    Lexer a;
    std::pair<std::string, std::string> s;
    int i = 0;
    while (!f.eof()) {
        s = a.next_token(f);
        std::cout << i++ << ": "
                  << s.first
                  << " "
                  << s.second
                  <<std::endl;
    }
    f.close();
    return 0;
}
