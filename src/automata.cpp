#include "../include/automata.hpp"

/*
 * TODO
 */
Automata::Automata(void)
{
    // Transition table of the automata
    transition_table_[State::Q0][Symbol::WHITESPACE] = State::Q0;
    transition_table_[State::Q0][Symbol::START_COMMENT] = State::Q1;
    transition_table_[State::Q0][Symbol::SEPARATOR] = State::Q2;
    transition_table_[State::Q0][Symbol::OPERATOR] = State::Q3;
    transition_table_[State::Q0][Symbol::LETTER] = State::Q4;
    transition_table_[State::Q0][Symbol::DIGIT] = State::Q5;
    transition_table_[State::Q0][Symbol::STRAY] = State::Q6;

    transition_table_[State::Q1][Symbol::END_COMMENT] = State::Q0;

    transition_table_[State::Q4][Symbol::LETTER] = State::Q4;
    transition_table_[State::Q4][Symbol::DIGIT] = State::Q4;
    transition_table_[State::Q4][Symbol::WHITESPACE] = State::Q7;
    transition_table_[State::Q4][Symbol::START_COMMENT] = State::Q7;
    transition_table_[State::Q4][Symbol::END_COMMENT] = State::Q7;
    transition_table_[State::Q4][Symbol::SEPARATOR] = State::Q7;
    transition_table_[State::Q4][Symbol::OPERATOR] = State::Q7;
    transition_table_[State::Q4][Symbol::STRAY] = State::Q7;

    transition_table_[State::Q5][Symbol::DIGIT] = State::Q5;
    transition_table_[State::Q5][Symbol::LETTER] = State::Q8;
    transition_table_[State::Q5][Symbol::OPERATOR] = State::Q8;
    transition_table_[State::Q5][Symbol::SEPARATOR] = State::Q8;
    transition_table_[State::Q5][Symbol::START_COMMENT] = State::Q8;
    transition_table_[State::Q5][Symbol::END_COMMENT] = State::Q8;
    transition_table_[State::Q5][Symbol::WHITESPACE] = State::Q8;
    transition_table_[State::Q5][Symbol::STRAY] = State::Q8;
    transition_table_[State::Q5][Symbol::DOT] = State::Q9;

    transition_table_[State::Q9][Symbol::DIGIT] = State::Q11;
    transition_table_[State::Q9][Symbol::LETTER] = State::Q10;
    transition_table_[State::Q9][Symbol::OPERATOR] = State::Q10;
    transition_table_[State::Q9][Symbol::SEPARATOR] = State::Q10;
    transition_table_[State::Q9][Symbol::START_COMMENT] = State::Q10;
    transition_table_[State::Q9][Symbol::END_COMMENT] = State::Q10;
    transition_table_[State::Q9][Symbol::WHITESPACE] = State::Q10;
    transition_table_[State::Q9][Symbol::DOT] = State::Q10;
    transition_table_[State::Q9][Symbol::STRAY] = State::Q10;

    transition_table_[State::Q11][Symbol::DIGIT] = State::Q11;
    transition_table_[State::Q11][Symbol::LETTER] = State::Q12;
    transition_table_[State::Q11][Symbol::OPERATOR] = State::Q12;
    transition_table_[State::Q11][Symbol::SEPARATOR] = State::Q12;
    transition_table_[State::Q11][Symbol::START_COMMENT] = State::Q12;
    transition_table_[State::Q11][Symbol::END_COMMENT] = State::Q12;
    transition_table_[State::Q11][Symbol::WHITESPACE] = State::Q12;
    transition_table_[State::Q11][Symbol::STRAY] = State::Q12;
    transition_table_[State::Q11][Symbol::DOT] = State::Q12;

    // Final states of the automata
    final_states_[State::Q2] = "separator_";
    final_states_[State::Q3] = "operator_";
    final_states_[State::Q6] = "stray_";
}

/*
 * TODO
 */
const State& Automata::transition_function(const State& state,
    const Symbol& symbol)
{
    return transition_table_[state][symbol];
}

std::pair<std::string, State> Automata::extended_transition_function(
    const State& state,
    std::ifstream& file_stream)
{
    Symbol next_symbol;
    State next_state = state;
    std::string lexeme;

    while (!file_stream.eof()
        && !final_states_.count(next_state)) {
        next_symbol = utils::next_symbol(file_stream);
        next_state = Automata::transition_function(state,
            next_symbol);
        lexeme.push_back(file_stream.get());
    }

    return std::pair<std::string, State> { lexeme,
        next_state };
}
