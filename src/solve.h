#pragma once

#include "nodes.h"

#include <string>

class Solve {
public:
    int evaluate(Node* node);

    bool get_error() const;
    void set_error(bool error_obj);

    void set_error_name(std::string error_name);
    std::string get_error_name() const;

private: 
    bool error;
    std::string error_name;

    Node* node;
};