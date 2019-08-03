#include "catch2/catch.hpp"
#include <iostream>

using std::string;
using std::cout;
using std::endl;

// Esse pedaço é só pra incluir uma biblioteca
// que deve ser tratada como código C.
#ifndef _TEST_CALCULATOR
#define _TEST_CALCULATOR
extern "C" {
#endif

#include <stdio.h>
#include <string.h>
#include "calculator.h"

#ifdef _TEST_CALCULATOR
}
#endif


TEST_CASE("evaluate", "[evaluate]") {
    char* data;
    char* result;
    t_list* list;
    t_list* postfix;

    char expression[] = "3*(8+3.5)/1.2";

    list = expression_to_list(expression);

    evaluate(list, &result);
    // printf("%s\n", *result);
    // REQUIRE(string(*result) == "5");

    clear(list); // liberar os nós e os data's
    free(list);

    soft_clear(postfix); // tem que liberar os nós
    free(postfix);

    free(result);
}
