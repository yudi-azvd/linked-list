#ifndef ANALYSIS_H_INCLUDED
#define ANALYSIS_H_INCLUDED

#include <stdio.h>

int is_number(char c);

int is_operator(char c);

int is_function(char c);

int find_number_end(char str[], int start);


#endif
