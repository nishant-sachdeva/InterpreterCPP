#include "lexer.h"
#include "output.h"
#include "interpreter.h"

#include <iostream>
#include <string>


int main(){
    std::string command;
    
    while(true) {
        std::cout << "[command]> ";
        std::getline(std::cin, command);
        
        if(command == "exit")
            break;

        Interpreter interpreter_object;
        interpreter_object.set_command(command);
        Output result = interpreter_object.run_command();
        
        if(result.get_error()){
            std::cout << result.get_error_name() << std::endl;
        }
        else {
            std::cout << result.get_answer() << std::endl;
        }
    }
    return 0;
}