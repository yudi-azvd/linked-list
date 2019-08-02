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


TEST_CASE("to_postfix", "[to_postfix]") {
    char* data;
    t_list* list;
    t_list* postfix;

    SECTION("to_postfix 1") {
        string expression = "3*(8+3.5)/1.2";
        // char expression[] = "3*(8+3.5)/1.2";
        // char output[] = "3 8 3.5 + * 1.2 /";

        // list = expression_to_list(expression);
        list = expression_to_list((char*) expression.c_str());
        postfix = to_postfix(list);

        data = (char*) get_at_index(postfix, 0);
        REQUIRE(string(data) == "3");

        data = (char*) get_at_index(postfix, 1);
        REQUIRE(string(data) == "8");

        data = (char*) get_at_index(postfix, 2);
        REQUIRE(string(data) == "3.5");

        data = (char*) get_at_index(postfix, 3);
        REQUIRE(string(data) == "+");

        data = (char*) get_at_index(postfix, 4);
        REQUIRE(string(data) == "*");

        data = (char*) get_at_index(postfix, 5);
        REQUIRE(string(data) == "1.2");

        data = (char*) get_at_index(postfix, 6);
        REQUIRE(string(data) == "/");
    }

    // sim, eu sei que são dois testes iguais. Já vou mudar
    SECTION("to_postfix 2") {
        string expression = "3*(8+3.5)/1.2";
        // char output[] = "3 8 3.5 + * 1.2 /";

        list = expression_to_list((char*) expression.c_str());
        postfix = to_postfix(list);

        data = (char*) get_at_index(postfix, 0);
        REQUIRE(string(data) == "3");

        data = (char*) get_at_index(postfix, 1);
        REQUIRE(string(data) == "8");

        data = (char*) get_at_index(postfix, 2);
        REQUIRE(string(data) == "3.5");

        data = (char*) get_at_index(postfix, 3);
        REQUIRE(string(data) == "+");

        data = (char*) get_at_index(postfix, 4);
        REQUIRE(string(data) == "*");

        data = (char*) get_at_index(postfix, 5);
        REQUIRE(string(data) == "1.2");

        data = (char*) get_at_index(postfix, 6);
        REQUIRE(string(data) == "/");
    }

    clear(list); // liberar os nós e os data's
    free(list);

    soft_clear(postfix); // tem que liberar os nós
    free(postfix);
}
