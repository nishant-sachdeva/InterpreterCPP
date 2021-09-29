#pragma once

#include "tokens.h"

class Node {
public:
    Node();
    Node(Token token_obj);
    Node(Node *left, Token token_obj, Node *right);
    bool get_error() const;
    void set_error(bool error_val);
    void print_tree() const;
    Token get_token() const;
    void deep_copy(Node* node);
    
    // these variables need to be accessed away from functions
    Token token_object;
    Node *left_node = NULL;
    Node *right_node = NULL;

private:
    bool error = false;
    
};


