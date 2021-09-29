#include "nodes.h"
#include "tokens.h"
#include "constants.h"

#include <iostream>

Node::Node() {
    bool error = false;
    token_object = Token(TT_EOF, "");
}

Node::Node(Token token_obj) {
    error = false;
    token_object.deep_copy(token_obj);
}

Node::Node(Node *left, Token token_obj, Node *right) {
    error = false;
    left_node = left;
    token_object.deep_copy(token_obj);
    right_node = right;
}

void Node::print_tree() const {

    if (left_node){
        std::cout << "[";
        left_node->print_tree();
        std::cout << "]";
    }

    std::cout << (token_object).get_token_value();

    if (right_node){
        std::cout << "[";
        right_node->print_tree();
        std::cout << "]";
    }
    return;
}

bool Node::get_error() const {
    return error;
}

Token Node::get_token() const {
    return token_object;
}

void Node::set_error(bool error_val) {
    error = error_val;
    return;
}

void Node::deep_copy(Node* node) {
    token_object.deep_copy(node->token_object);
    left_node = node->left_node;
    right_node = node->right_node;
    error = node->get_error();
    return;
}