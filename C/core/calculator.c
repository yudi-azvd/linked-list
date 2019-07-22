#include "calculator.h"

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

    /* TESTAR TENTADO REDUZIR O CLEAR() E O FREE()
    mas acho qeu um break; ainda não daria certo */

    soft_clear(brackets_stack);
    free(brackets_stack);
    return 0;
}
