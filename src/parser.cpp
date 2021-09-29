#include "parser.h"
#include "tokens.h"
#include "constants.h"
#include "nodes.h"

#include <vector>
#include <tuple>
#include <utility>

Parser::Parser(std::vector<Token> token_list) {
    v_tokens = token_list;
    token_id = -1;
    std::ignore = advance();
}

Token Parser::advance() {
    token_id += 1;
    if(token_id < v_tokens.size())
        current_token.deep_copy(v_tokens[token_id]);
    else
        current_token = Token(TT_EOF, "");
    return current_token;
}

void Parser::parse_tokens(Node* node) {
    expression(node);
    if(!node->get_error() && current_token.get_token_type() != TT_EOF) {
        node->set_error(true);
    }
    return;
}

void Parser::factor(Node* node) {
    Token tok;
    tok.deep_copy(current_token);

    if (tok.get_token_type() == TT_PLUS || tok.get_token_type() == TT_MINUS) {
        std::ignore = advance();
        Node* recur_factor = new Node();
        factor(recur_factor);

        if(recur_factor->get_error()) {
            node->deep_copy(recur_factor);
            return;
        }
        Token zero_tok = Token(TT_INT, "0");
        Node* zero_node = new Node(zero_tok);

        recur_factor = new Node(zero_node, tok, recur_factor);
        node->deep_copy(recur_factor);

        return;
    }
    else if (tok.get_token_type() == TT_INT) {
        node->token_object.deep_copy(tok);
        std::ignore = advance();
        return;
    }
    else if (tok.get_token_type() == TT_LPAREN) {

        std::ignore = advance();

        Node* left = new Node();

        expression(left);

        if(left->get_error()) {
            node->deep_copy(left);
            return;
        }

        if(current_token.get_token_type() == TT_RPAREN) {
            std::ignore = advance();
            node->deep_copy(left);
            return;
        }
        else {
            node->set_error(true);
            return;
        }
    }
    else {
        node->set_error(true);
        return;
    }
}

void Parser::term(Node* node) {
    Node *left = new Node();
    factor(left);

    if (left->get_error()) {
        node->deep_copy(left);
        return;
    }

    while (current_token.get_token_type() == TT_MUL || current_token.get_token_type() == TT_DIV) {
        Token op_tok = current_token;
        Token cur = advance();
        
        if (cur.get_token_type() == TT_EOF) {
            left->set_error(true);
            node->deep_copy(left);
            return;
        }

        Node *right = new Node();
        factor(right);

        if (right->get_error()) {
            node->deep_copy(right);
            return;
        }
        
        left = new Node(left, op_tok, right);
    }
    node->deep_copy(left);
    return;
}

void Parser::expression(Node* node) {
    Node *left = new Node();
    term(left);

    if (left->get_error()) {
        node->deep_copy(left);
        return;
    }

    while (current_token.get_token_type() == TT_PLUS || current_token.get_token_type() == TT_MINUS) {
        Token op_tok = current_token;

        Token cur = advance();

        if (cur.get_token_type() == TT_EOF) {
            left->set_error(true);
            node->deep_copy(left);
            return;
        }

        Node *right = new Node();
        term(right);

        if (right->get_error()) {
            node->deep_copy(right);
            return;
        }

        left = new Node(left, op_tok, right);
    }
    node->deep_copy(left);
    return;
}
