#include <stdio.h>
#include <stdlib.h>

#include "list.h"

int main() {
    t_list* list = create_list();

    insert_front(list, "string");
    insert_front(list, "new string!");

    remove_head(list);
    remove_head(list);
    // remove_head(list);

    // clear(list);
    // printf("%p\n", list->head);
    // insert_front(list, "new string!");


    free(list);

    return 0;
}
