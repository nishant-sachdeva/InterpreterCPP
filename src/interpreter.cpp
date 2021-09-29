#include "lexer.h"
#include "output.h"
#include "interpreter.h"
#include "parser.h"
#include "nodes.h"
#include "solve.h"

#include <string>


void Interpreter::set_command(std::string command_string) {
    command = command_string;
}

Output Interpreter::run_command() {
    Output output_object;
    Lexer lexer_object;

    lexer_object.lex_command(command);
    
    if(lexer_object.get_error()) {
        output_object.set_error_name(lexer_object.get_error_name());
        output_object.set_error(lexer_object.get_error());
        return output_object;
    }
    
    Parser parse_object = Parser(lexer_object.get_tokens());

    Node *ast = new Node();
    parse_object.parse_tokens(ast);

    if(ast->get_error()) {
        output_object.set_error(ast->get_error());
        output_object.set_error_name("Error Occurred during Parsing");
        return output_object;
    }

    Solve *answer = new Solve();

    int result = answer->evaluate(ast);

    if(answer->get_error()) {
        output_object.set_error(answer->get_error());
        output_object.set_error_name(answer->get_error_name());
        return output_object;
    }

    output_object.set_answer(result);
    return output_object;
}