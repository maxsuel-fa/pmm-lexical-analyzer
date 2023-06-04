#include "../include/automata.hpp"
#include "../include/utils.hpp"

/*
 * TODO
 */
Automata::Automata(void)
{
    // Transition table of the automata
    transition_table_[State::Q0][Symbol::WHITESPACE] = State::Q0;
    transition_table_[State::Q0][Symbol::START_COMMENT] = State::Q1;
    transition_table_[State::Q0][Symbol::SEPARATOR] = State::Q2;
    transition_table_[State::Q0][Symbol::DOT] = State::Q2;
    transition_table_[State::Q0][Symbol::OPERATOR] = State::Q3;
    transition_table_[State::Q0][Symbol::LETTER] = State::Q4;
    transition_table_[State::Q0][Symbol::DIGIT] = State::Q5;
    transition_table_[State::Q0][Symbol::STRAY] = State::Q6;

    transition_table_[State::Q1][Symbol::END_COMMENT] = State::Q0;
    transition_table_[State::Q1][Symbol::LETTER] = State::Q1;
    transition_table_[State::Q1][Symbol::DIGIT] = State::Q1;
    transition_table_[State::Q1][Symbol::WHITESPACE] = State::Q1;
    transition_table_[State::Q1][Symbol::START_COMMENT] = State::Q1;
    transition_table_[State::Q1][Symbol::SEPARATOR] = State::Q1;
    transition_table_[State::Q1][Symbol::OPERATOR] = State::Q1;
    transition_table_[State::Q1][Symbol::STRAY] = State::Q1;


    transition_table_[State::Q3][Symbol::LETTER] = State::Q13;
    transition_table_[State::Q3][Symbol::DIGIT] = State::Q13;
    transition_table_[State::Q3][Symbol::WHITESPACE] = State::Q13;
    transition_table_[State::Q3][Symbol::START_COMMENT] = State::Q13;
    transition_table_[State::Q3][Symbol::END_COMMENT] = State::Q13;
    transition_table_[State::Q3][Symbol::SEPARATOR] = State::Q13;
    transition_table_[State::Q3][Symbol::OPERATOR] = State::Q13;
    transition_table_[State::Q3][Symbol::STRAY] = State::Q13;
    
    transition_table_[State::Q4][Symbol::LETTER] = State::Q4;
    transition_table_[State::Q4][Symbol::DIGIT] = State::Q4;
    transition_table_[State::Q4][Symbol::WHITESPACE] = State::Q7;
    transition_table_[State::Q4][Symbol::START_COMMENT] = State::Q7;
    transition_table_[State::Q4][Symbol::END_COMMENT] = State::Q7;
    transition_table_[State::Q4][Symbol::SEPARATOR] = State::Q7;
    transition_table_[State::Q4][Symbol::DOT] = State::Q7;
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
    final_states_.insert(State::Q2);
    final_states_.insert(State::Q6);
    final_states_.insert(State::Q7);
    final_states_.insert(State::Q8);
    final_states_.insert(State::Q10);
    final_states_.insert(State::Q12);
    final_states_.insert(State::Q13);
    
}

/*
 * TODO
 */
const State& Automata::transition_function(const State& state,
    const Symbol& symbol)
{
    return transition_table_[state][symbol];
}

/*
 * TODO
 */
std::pair<std::string, State> Automata::extended_transition_function(
    const State& state,
    std::ifstream& file_stream)
{
    Symbol symbol {read_symbol(file_stream)};
    State next_state { state };
    std::string lexeme;
    
    while (!final_states_.count(next_state)) {
        lexeme.push_back(file_stream.get());
        next_state = transition_function(next_state, symbol);
        symbol = read_symbol(file_stream);
        if (next_state == State::Q0) {
            lexeme.clear(); 
        }
    }

    return std::pair<std::string, State> { lexeme,
        next_state };
}


/*
 * TODO
 */
Symbol Automata::read_symbol(std::ifstream& file_stream)
{
    if (utils::is_digit(file_stream)) {
        return Symbol::DIGIT;
    }
    if (utils::is_letter(file_stream)) {
        return Symbol::LETTER;
    }
    if (utils::is_operator(file_stream)) {
        return Symbol::OPERATOR;
    }
    if (utils::is_separator(file_stream)) {
        return Symbol::SEPARATOR;
    }
    if (utils::is_start_comment(file_stream)) {
        return Symbol::START_COMMENT;
    }
    if (utils::is_end_comment(file_stream)) {
        return Symbol::END_COMMENT;
    }
    if (utils::is_dot(file_stream)) {
        return Symbol::DOT;
    }
    if (utils::is_whitespace(file_stream)) {
        return Symbol::WHITESPACE;
    }
    return Symbol::STRAY;
}
