#pragma once

#include <fstream>
#include <set>
#include <string>
#include <unordered_map>
#include <vector>

#include "../include/utils.hpp"

/*
 * TODO
 */
enum class Symbol {
    DIGIT,
    LETTER,
    OPERATOR,
    SEPARATOR,
    START_COMMENT,
    END_COMMENT,
    WHITESPACE,
    DOT,
    STRAY
};

/*
 * TODO
 */
enum class State {
    Q0,
    Q1,
    Q2,
    Q3,
    Q4,
    Q5,
    Q6,
    Q7,
    Q8,
    Q9,
    Q10,
    Q11,
    Q12,
    Q13
};

/*
 * TODO
 */
class Automata {
public:
    Automata(void);
    const State& transition_function(const State&, const Symbol&);
    std::pair<std::string,
        State>
    extended_transition_function(const State&,
        std::ifstream&);
    std::pair<std::string, std::string> output_function(const State&);

private:
    std::unordered_map<State, std::unordered_map<Symbol, State>>
        transition_table_;
    std::set<State> final_states_;
    Symbol read_symbol(std::ifstream&);
};
