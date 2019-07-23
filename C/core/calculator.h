#ifndef CALCULATOR_H_INCLUDED
#define CALCULATOR_H_INCLUDED

#include <stdio.h>
#include <string.h>
#include "list.h" /* t_stack */
#include "util.h"
/*
#include "operations.h"
*/


#define EXPRESSION_OK      0
#define EXPRESSION_INVALID 1


void calculate(char expression[], char** result);


void sanitize(char expression[]);


/* retornar um código de erro */
int is_valid(char expression[]);

int is_bracket(char c);

int match(char c1, char c2);

int is_balanced(char expression[]);


#endif
