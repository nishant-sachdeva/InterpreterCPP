#pragma once

#include "output.h"

#include <string>

class Interpreter {
public:
    void set_command(std::string command_string);
    Output run_command();

private:
    std::string command;
};

