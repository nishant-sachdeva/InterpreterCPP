#include "lexer.h"
#include "tokens.h"
#include "constants.h"

#include <cctype>
#include <iostream>
#include <algorithm>
#include <vector>
#include <string>
#include <exception>

Lexer::Lexer() : error(false) ,answer(0) {}

void Lexer::list_tokens() const {
    for(const Token& tok_object : tokens)
        tok_object.disp();
    return;
}
std::vector<Token>Lexer::get_tokens() const {
    return tokens;
}

bool Lexer::get_error() const {
    return error;
}

void Lexer::set_answer(int answer_obj) {
    answer = answer_obj;
    return;
}

int Lexer::get_answer() const {
    return answer;
}

std::string Lexer::get_error_name() const {
    return error_name;
}

void Lexer::set_error_name(std::string error_name_obj) {
    error_name = error_name_obj;
    return;
}

void Lexer::lex_command(std::string command) {

    for(int pos = 0; pos<command.size(); pos++){

        if(command[pos] == ' ')
            continue;
        
        switch(command[pos]){
            case '+' : tokens.push_back(Token(TT_PLUS, "+")); break;
            case '-' : tokens.push_back(Token(TT_MINUS, "-")); break;
            case '*' : tokens.push_back(Token(TT_MUL, "*")); break;
            case '/' : tokens.push_back(Token(TT_DIV, "/")); break;
            case '(' : tokens.push_back(Token(TT_LPAREN, "(")); break;
            case ')' : tokens.push_back(Token(TT_RPAREN, ")")); break;
            default:
                std::size_t num_end;
                try {
                    int number = std::stoi(&command.c_str()[pos], &num_end);
                    tokens.push_back(Token(TT_INT, std::to_string(number)));
                    pos += num_end-1;
                }
                catch (...) {
                    error_name = "Syntax Error : Expected +, -, *, /, (, ) or a number ";
                    error = true;
                    return;
                }
        }
    }
    tokens.push_back(Token(TT_EOF, ""));
    return;
}
