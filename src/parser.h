#pragma once

#include "tokens.h"
#include "nodes.h"

#include <vector>
#include <functional>


class Parser {
public:
    Parser();
    Parser(std::vector<Token> token_list);
    void parse_tokens(Node* node);
    Token advance();
    void factor(Node* node);
    void term(Node* node);
    void expression(Node* node);


private:
    std::vector<Token> v_tokens;
    Token current_token;
    int token_id;

};
