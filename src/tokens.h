#pragma once

#include "constants.h"

#include <string>
#include <iostream>

class Token {
public:
    Token(std::string token_type=TT_EOF, std::string token_value="");
    void set_values(const std::string token_type=TT_EOF, const std::string token_value="");
    
    void disp() const;
    
    void deep_copy(const Token& tok);

    std::string get_token_type() const;
    std::string get_token_value() const;
private:
    std::string tok_type;
    std::string tok_value;

};
