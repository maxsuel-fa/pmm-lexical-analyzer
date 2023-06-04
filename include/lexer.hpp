#pragma once

#include <map>
#include <string>
#include <unordered_map>

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
    std::map<std::string, std::string> keyword_table_;
    std::map<std::string, std::string> separator_table_;
    std::map<std::string, std::string> operator_table_;
    std::unordered_map<State,
        std::unordered_map<bool, std::string>>
        token_table_;
    std::string format_label(const std::string&, const std::string&);
};
