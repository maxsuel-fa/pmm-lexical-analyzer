#include <iostream>
#include <fstream>
#include "../include/scanner.hpp"


int main(void)
{
    std::ifstream f;
    f.open("place the path for file here", std::ios::in);
    Scanner s(f);
    
    int i = 0;
    while(!f.eof()) 
        std::cout << i++ << ": "<< s.next_lexeme() << std::endl;
    f.close();
    return 0;
}
