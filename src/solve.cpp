#include "solve.h"
#include "nodes.h"

bool Solve::get_error() const {
    return error;
}
void Solve::set_error(bool error_obj) {
    error = error_obj;
    return;
}

void Solve::set_error_name(std::string error_name_obj) {
    error_name = error_name_obj;
    return;
}
    
std::string Solve::get_error_name() const {
    return error_name;
}

int Solve::evaluate(Node* node) {
    if (node->left_node == NULL and node->right_node == NULL) {
        return std::stoi(node->token_object.get_token_value());
    }

    else if (node->left_node and node->right_node) {
        int temp1 = evaluate(node->left_node);

        if(node->left_node->get_error()) {
            this->set_error(true);
            this->set_error_name("!!! Incorrect Expression");
            return -1;
        }

        int temp2 = evaluate(node->right_node);
        if(node->right_node->get_error()) {
            this->set_error(true);
            this->set_error_name("!!! Incorrect Expression");
            return -1;
        }

        std::string operand = node->token_object.get_token_value();
        if (operand == "+") {
            return temp1 + temp2;
        }
        if (operand == "-") {
            return temp1 - temp2;
        }
        if (operand == "*") {
            return temp1 * temp2;
        }
        if (operand == "/") {
            if(temp2 == 0) {
                this->set_error(true);
                this->set_error_name("!!! Division by 0 error");
                return -1;
            }
            return temp1 / temp2;
        }

        node->set_error(true);
        return -1;
    }
}