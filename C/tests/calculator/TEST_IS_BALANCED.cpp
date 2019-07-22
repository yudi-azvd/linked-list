#include "catch2/catch.hpp"
#include <string.h>

// Esse pedaço é só pra incluir uma biblioteca
// que deve ser tratada como código C.
#ifndef _TEST_CALCULATOR
#define _TEST_CALCULATOR
extern "C" {
#endif
#include "calculator.h"
#ifdef _TEST_CALCULATOR
}
#endif


TEST_CASE("test 1", "[is_balanced]") {
    REQUIRE(is_balanced((char*) "rdm") == 0);
}
