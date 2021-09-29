#include "output.h"

#include <string>

Output::Output() {
    error = false;
    answer = 0;
}

void Output::set_answer(int answer_value) {
    answer = answer_value;
}

void Output::set_error(bool error_value) {
    error = error_value;
}

void Output::set_error_name(std::string error_name_str) {
    error_name = error_name_str;
}

int Output::get_answer() const {
    return answer;
}

bool Output::get_error() const {
    return error;
}

std::string Output::get_error_name() const {
    return error_name;
}