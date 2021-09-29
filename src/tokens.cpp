#include "tokens.h"
#include "constants.h"

#include <iostream>
#include <vector>


Token::Token(std::string token_type,  std::string token_value) {
    tok_type = token_type;
    tok_value = token_value;    
}

void Token::set_values(const std::string token_type, const std::string token_value) {
    this->tok_type = token_type;
    this->tok_value = token_value;
    return;
}

std::string Token::get_token_type() const {
    return this->tok_type;
}

std::string Token::get_token_value() const {
    return this->tok_value;
}

void Token::disp() const {
    std::cout << "[" + tok_type  << "]" << "(" << tok_value << ")";
    return;
}

void Token::deep_copy(const Token& tok) {
    tok_value = tok.tok_value;
    tok_type = tok.tok_type;
    return;
}
