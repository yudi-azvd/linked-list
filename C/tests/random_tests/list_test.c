#include <stdio.h>
#include <stdlib.h>

#include "list.h"

int main() {
    // t_list* list = create_list(&print_str_list);
    t_list* list = create_list(&print_int_list);
    char str1[] = "string";
    char str2[] = "new string";

    printf("empty: %d\n", is_empty(list));
    int a = 5;

    // insert_front(list, str1);
    // insert_front(list, str2);
    // insert_front(list, str2);
    // insert_front(list, str1);

    // insert_front(list, "string");
    // insert_front(list, "new string");

    insert_front(list, &a);
    int b = 2;
    insert_front(list, &b);
    printf("empty: %d\n", is_empty(list));

    print(list);

    printf("&list->head %p\n", &(list->head));
    printf("list->head %p\n", (list->head));
    printf("&(list->tail) %p\n", &(list->tail));


    remove_head(list);
    remove_head(list);
    remove_head(list);
    remove_head(list);

    // clear(list);
    printf("empty: %d\n", is_empty(list));
    // insert_front(list, "new string!");
    printf("length: %d\n", list->length);
    printf("l->tail: %p\n", list->tail);

    print(list);
    // insert_front(list, "new string____");
    // remove_head(list);


    free(list);

    return 0;
}
