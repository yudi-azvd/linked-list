#include <stdio.h>

#include "calculator.h"
#include "user_interface.h"

#define EXPRESSION_MAX_SIZE 50


int main() {
    // char expression[] = "3-1*(8+3.5)/1.2";
    // char expression[] = "3-1*5+9";
    char expression[EXPRESSION_MAX_SIZE];
    char* result;

    while (1) {
        printf("> ");
        // tem que virar comando no final
        // getusrinput(expression, 0);
        get_expression(expression);

        if(is_quit(expression))
            return 0;

        calculate(expression, &result);

        printf("%s\n", result);


        free(result);
    }

    return 0;
}
