#ifndef CALCULATOR_H_INCLUDED
#define CALCULATOR_H_INCLUDED

#include <stdio.h>
#include "list.h" /* t_stack */

int is_bracket(char c);

int match(char c1, char c2);

int is_balanced(char expression[]);


#endif
