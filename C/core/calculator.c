#include <stdio.h>
#include "calculator.h"

void calculate(char expression[], char** result) {
    const int RESULT_SIZE = 10;
    int i_dummy_result = 5;

    sanitize(expression);
    /*
    double d_dummy_result = 5.4;
    if valid expression
        extract numbers and operations from expression and
          pass them to a list
        evaluate

    else
        return error

        */
    *result = (char*) calloc(RESULT_SIZE, sizeof(char));
    snprintf(*result, RESULT_SIZE, "%d", i_dummy_result);
}

void sanitize(char expression[]) {
    remove_whitespace(expression);
    remove_illegalchars(expression);
    /*
    remove double points
    remove double operations?
    remove illegal chars
    */
}


int is_valid(char expression[]) {
    /*
    int expr_lentgh = strlen(expression);
    int balanced = is_balanced(expression);
    balanceada
    não tem mais de dois pontos seguidos
    não tem virgulas?
    tem operações/funções conhecidas
    */
    return 1;
}


int is_bracket(char c) {
    if(c == '(' || c == '[' || c == '{')
		return -1;
	if(c == ')' || c == ']' || c == '}')
		return 1;
	return 0;
}


int match(char c1, char c2) {
	if(c1 == '(' && c2 == ')')
		return 1;
	if(c1 == '[' && c2 == ']')
		return 1;
	if(c1 == '{' && c2 == '}')
		return 1;
	return 0;
}


int is_balanced(char expression[]) {
    int i, expr_lentgh = strlen(expression);
    t_stack* brackets_stack = create_stack("char");

    for(i = 0; i < expr_lentgh; i++) {
        if(is_bracket(expression[i]) < 0)
            push(brackets_stack, &expression[i]);
        if(is_bracket(expression[i]) > 0) {
            if(!is_empty(brackets_stack)) {
                if(match(expression[i], *((char*) peek(brackets_stack))))
                    remove_head(brackets_stack);
                else {
                    soft_clear(brackets_stack);
                    free(brackets_stack);
                    return 0;
                }
            }
            else {
                soft_clear(brackets_stack);
                free(brackets_stack);
                return 0;
            }
        }
    }

    if (is_empty(brackets_stack)) {
        free(brackets_stack);
        return 1;
    }

    soft_clear(brackets_stack);
    free(brackets_stack);
    return 0;
}
