#include <stdio.h>
#include "calculator.h"
#include "list.h"

int main() {
    t_list* list = create_list("int");

    printf("%s\n", "oi, mundo!");

    clear(list);
    free(list);

    return 0;
}
