#include "../include/lexer.hpp"

Lexer::Lexer(void)
{
    keyword_table_["program"] = "PROGRAM";
    keyword_table_["begin"] = "BEGIN";
    keyword_table_["end"] = "END";
    keyword_table_["const"] = "CONST";
    keyword_table_["var"] = "VAR";
    keyword_table_["real"] = "REAL";
    keyword_table_["integer"] = "INTEGER";
    keyword_table_["procedure"] = "PROCEDURE";
    keyword_table_["if"] = "IF";
    keyword_table_["else"] = "ELSE";
    keyword_table_["read"] = "READ";
    keyword_table_["write"] = "WRITE";
    keyword_table_["while"] = "WHILE";
    keyword_table_["for"] = "FOR";
    keyword_table_["do"] = "DO";
    keyword_table_["then"] = "THEN";
    keyword_table_["to"] = "TO";
    
    separator_table_[","] = "COMMA";
    separator_table_["."] = "DOT";
    separator_table_[";"] = "SEMICOLON";
    separator_table_[":"] = "COLON";
    separator_table_["("] = "LEFT_PARETHESES";
    separator_table_[")"] = "RIGHT_PARETHESES";

    operator_table_["="] = "EQUAL_TO";
    operator_table_["<>"] = "NOT_EQUAL_TO";
    operator_table_[">="] = "GREATER_THAN_OR_EQUAL_TO";
    operator_table_["<="] = "LESS_THAN_OR_EQUAL_TO";
    operator_table_[">"] = "GREATER_THAN";
    operator_table_["<"] = "LESS_THAN";
    operator_table_["+"] = "ADD";
    operator_table_["-"] = "SUBTRACT";
    operator_table_["*"] = "MULTIPLY";
    operator_table_["/"] = "DIVIDE";
    operator_table_[":="] = "ASSIGN";

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
        && !operator_table_.count(temp.first)
        && !temp.first.empty()) {
        temp.first.pop_back();
        file_stream.unget();
    }

    bool token_key { keyword_table_.count(temp.first)
        || operator_table_.count(temp.first) };

    return std::pair<std::string, std::string> { temp.first,
        format_label(temp.first, token_table_[temp.second][token_key]) };
}

/*
 * TODO
 */
std::string Lexer::format_label(const std::string& lexeme,
    const std::string& label)
{
    std::string formated_label { label };
    if (keyword_table_.count(lexeme)) {
        return formated_label.append(keyword_table_[lexeme]);
    }
    if (separator_table_.count(lexeme)) {
        return formated_label.append(separator_table_[lexeme]);
    }
    if (operator_table_.count(lexeme)) {
        return formated_label.append(operator_table_[lexeme]);
    }
    return formated_label;
}
