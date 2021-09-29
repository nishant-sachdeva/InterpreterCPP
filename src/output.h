#pragma once

#include <string>

class Output {
public:
    Output();
    void set_error(bool error_value);
    void set_answer(int answer_value);
    void set_error_name(std::string error_name_str);
    bool get_error() const;
    int get_answer() const;
    std::string get_error_name() const;

private:
    bool error;
    int answer;
    std::string error_name;
};