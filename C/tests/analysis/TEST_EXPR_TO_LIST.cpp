#include "catch2/catch.hpp"
#include <string.h>

using namespace std;

// Esse pedaço é só pra incluir uma biblioteca
// que deve ser tratada como código C.
#ifndef _TEST_ANALYSIS
#define _TEST_ANALYSIS
extern "C" {
#endif
    #include "analysis.h"
#ifdef _TEST_ANALYSIS
}
#endif

TEST_CASE("expression_to_list", "[expression_to_list]") {
    t_list* list;
    SECTION("1") {
        char expression[] = "3*1.5+4";

        t_list* list = expression_to_list(expression);
        // REQUIRE(get_at(list, 0) == );
    }

    clear(list);
    free(list);
}
