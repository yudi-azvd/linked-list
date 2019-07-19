#include "catch2/catch.hpp"
#include <string.h>

// Esse pedaço é só pra incluir uma biblioteca
// que deve ser tratada como código C.
#ifndef _TEST_LIST
#define _TEST_LIST
extern "C" {
#endif
    #include "list.h"
#ifdef _TEST_LIST
}
#endif


TEST_CASE("double 1", "[list]") {
    t_list* doubles = create_list("double");

    double a = 5.67;

    insert_head(doubles, &a);
    remove_head(doubles);

    insert_head(doubles, &a);
    remove_head(doubles);

    free(doubles);
}

TEST_CASE("double 2", "[list]") {
    t_list* doubles = create_list("int");

    double a = 5;

    insert_head(doubles, &a);
    soft_clear(doubles);

    insert_head(doubles, &a);
    soft_clear(doubles);

    free(doubles);
}


TEST_CASE("double 3", "[list]") {
    t_list* strings = create_list("char*");

    char str1[] = "lista";
    char str2[] = "abacaxi";
    char str3[] = "land rover";

    insert_head(strings, str1);
    insert_head(strings, str2);
    insert_head(strings, str3);

    char str[15];
    strcpy(str, (char*) get_head(strings));

    REQUIRE(strcmp(str, "land rover") == 0);

    soft_clear(strings);
    free(strings);
}


TEST_CASE("double 4", "[list]") {
    double i = .59;
    double* ptr_double = (double*) calloc(1, sizeof(double));
    t_list* list = create_list("double");

    *ptr_double = i;
    insert_head(list, ptr_double);
    ptr_double = (double*) calloc(1, sizeof(double));
    i += 0.59;

    *ptr_double = i;
    insert_head(list, ptr_double);
    ptr_double = (double*) calloc(1, sizeof(double));
    i += 0.59;

    REQUIRE(list->length == 2);

    print(list);
    clear(list);
    free(list);
    free(ptr_double);
}

TEST_CASE("double 5", "[list]") {
    int* ptr_int = (int*) calloc(1, sizeof(int));
    t_list* list = create_list("int");

    int i = 0;
    while(i < 5) {
        *ptr_int = i;
        insert_tail(list, ptr_int);
        ptr_int = (int*) calloc(1, sizeof(int));
        i++;
    }

    REQUIRE(list->length == 5);
    REQUIRE(*((int*) get_tail(list)) == 4);
    REQUIRE(*((int*) get_head(list)) == 0);

    // print(list);
    clear(list);
    free(list);
    free(ptr_int);
}


TEST_CASE("double 5.1", "[list]") {
    int* ptr_int = (int*) calloc(1, sizeof(int));
    t_list* list = create_list("int");

    SECTION("created list is empty") {
        REQUIRE(is_empty(list) == true);
    }

    SECTION("add elements to list") {
        int i = 0;
        while(i < 5) {
            *ptr_int = i;
            insert_head(list, ptr_int);
            ptr_int = (int*) calloc(1, sizeof(int));
            i++;
        }

        REQUIRE(list->length == 5);

        delete_head(list);
        delete_head(list);

        REQUIRE(list->length == 3);
    }

    clear(list);
    free(list);
    free(ptr_int);
}
