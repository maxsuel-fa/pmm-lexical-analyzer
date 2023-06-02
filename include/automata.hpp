#pragma once

#include <set>
#include <string>
#include <unordered_map>
#include <vector>

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

private:
    std::unordered_map<State, std::unordered_map<Symbol, State>>
        transition_table_;
    std::unordered_map<State, std::string> final_states_;
};
