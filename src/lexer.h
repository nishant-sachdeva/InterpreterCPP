#pragma once

#include "constants.h"
#include "tokens.h"

#include <string>
#include <vector>

class Lexer {
public:
    Lexer();
    void list_tokens() const;
    std::vector<Token> get_tokens() const;
    void lex_command(std::string);
    bool get_error() const;
    std::string get_error_name() const;
    void set_error_name(std::string error_name);
    int get_answer() const;
    void set_answer(int answer);

private:
    bool error;
    int answer;
    std::string error_name;
    std::vector<Token> tokens;
};

