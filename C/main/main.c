#include <stdio.h>
#include "calculator.h"

int main() {

    char expression[] = "3-1*(8+3.5)/1.2";
    char* result;

    calculate(expression, &result);

    printf("%s\n", expression);

    printf(" = %s\n", result);
    printf("\n -- EU AINDA NÃO FUNCIONO --\n");

    free(result);

    return 0;
}
