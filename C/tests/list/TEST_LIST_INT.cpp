#define CATCH_CONFIG_MAIN
#include "catch2/catch.hpp"

// Esse pedaço é só pra incluir uma biblioteca
// que deve ser tratada como código C.
#ifndef _LIST_INT
#define _LIST_INT
extern "C" {
#endif
    #include "list.h"
#ifdef _LIST_INT
}
#endif

TEST_CASE("create, insert, clear e free(list)", "[list]") {
    t_list* integers = create_list(&print_int_list);

    int a = 5;

    insert_head(integers, &a);

    clear(integers);
    insert_head(integers, &a);
    clear(integers);

    free(integers);
}

/*

TEST_CASE("testar seções", "[list]") {
    int* ptr_int = (int*) calloc(1, sizeof(int));
    t_list* list = create_list(&print_int_list);

    int i = 0;
    while(i < 3) {
        *ptr_int = i;
        insert_head(list, ptr_int);
        // free(ptr_int);
        ptr_int = (int*) calloc(1, sizeof(int));
        i++;
    }

    print(list);
    clear(list);
    free(list);
    free(ptr_int);
}
 */
