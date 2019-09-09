#include <stdio.h>
#
#include "calculator.h"
#include "terminal_functions.h"

#define EXPRESSION_MAX_SIZE 50

int quit_command(char* input) {
    int i;
    for (i = 0; input[i] != '\0'; i++)
        if (input[i] == 'q')
            return 1;
    return 0;
}


int main() {

    // char expression[] = "3-1*(8+3.5)/1.2";
    // char expression[] = "3-1*5+9";
    char expression[EXPRESSION_MAX_SIZE];
    char* result;

    while (1) {
        printf("> ");
        // tem que virar comando no final
        getusrinput(expression, 0);

        if(quit_command(expression))
            return 0;

        calculate(expression, &result);

        printf("%s\n", expression);
        printf(" = %s\n", result);

        free(result);
    }

    return 0;
}
