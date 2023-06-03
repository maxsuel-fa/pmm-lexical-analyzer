#pragma once

#include <string>
#include <unordered_map>
#include <set>

#include "automata.hpp"

/*
 * TODO
 */
class Lexer {
public:
    Lexer(void);
    std::pair<std::string, std::string> next_token(std::ifstream&);

private:
    Automata automata_;
    std::set<std::string> keyword_table_;
    std::set<std::string> operator_table_;
    std::unordered_map<State, 
        std::unordered_map<bool, std::string>> token_table_;
};
