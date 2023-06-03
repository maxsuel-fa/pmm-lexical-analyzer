#include "../include/lexer.hpp"

Lexer::Lexer(void)
{
    keyword_table_.insert("program");
    keyword_table_.insert("begin");
    keyword_table_.insert("end");
    keyword_table_.insert("const");
    keyword_table_.insert("var");
    keyword_table_.insert("real");
    keyword_table_.insert("integer");
    keyword_table_.insert("procedure");
    keyword_table_.insert("if");
    keyword_table_.insert("else");
    keyword_table_.insert("read");
    keyword_table_.insert("write");
    keyword_table_.insert("do");
    keyword_table_.insert("then");

    operator_table_.insert("=");
    operator_table_.insert("<>");
    operator_table_.insert(">=");
    operator_table_.insert("<=");
    operator_table_.insert(">");
    operator_table_.insert("<");
    operator_table_.insert("+");
    operator_table_.insert("-");
    operator_table_.insert("*");
    operator_table_.insert("/");
    operator_table_.insert(":=");

    token_table_[State::Q2][false] = "SEPARATOR_";
    token_table_[State::Q6][false] = "NOT_ALLOWED_SYMBOL";
    token_table_[State::Q7][true] = "KEYWORD_";
    token_table_[State::Q7][false] = "IDENTIFIER";
    token_table_[State::Q8][false] = "INTEGER_LITERAL";
    token_table_[State::Q10][false] = "INVALID_NUMBER";
    token_table_[State::Q12][false] = "FLOAT_LITERAL";
    token_table_[State::Q13][true] = "OPERATOR_";
    token_table_[State::Q13][false] = "SEPARATOR_";
}

/*
 * TODO
 */
std::pair<std::string, std::string> Lexer::next_token(std::ifstream& file_stream)
{
    std::string chain;
    std::pair<std::string, State>
        temp { automata_.extended_transition_function(State::Q0, file_stream) };

    if (temp.second != State::Q2
            && temp.second != State::Q6
            && !operator_table_.count(temp.first)) {
        temp.first.pop_back();
        file_stream.unget();
    }

    bool token_key { keyword_table_.count(temp.first)
        || operator_table_.count(temp.first) };

    return std::pair<std::string, std::string> { temp.first,
        token_table_[temp.second][token_key] };
}
