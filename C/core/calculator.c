#include "calculator.h"


int is_balanced(char expression[]) {
    int i = 0, expr_lentgh = 0;
    t_stack* char_stack = create_stack("char");
    /*
    t_list* char_stack = create_list("char");
    */

    printf("%d, %d\n", i, expr_lentgh);

    clear(char_stack);
    free(char_stack);

    return 0;
}
