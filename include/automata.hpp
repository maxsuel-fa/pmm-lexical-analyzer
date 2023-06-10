#pragma once

#include <fstream>
#include <set>
#include <string>
#include <unordered_map>
#include <vector>

#include "../include/utils.hpp"

/*
 * @brief The alphabet of the automata
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
 * @brief The set of states of the automata
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
 * @brief Defines an automata especific to the P-- language
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
