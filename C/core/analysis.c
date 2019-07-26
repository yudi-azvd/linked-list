#include "analysis.h"

int is_number(char c) {
    return ('0' <= c && c <= '9');
}


int is_operator(char c) {
    if     (c == '+')
        return 1;
    else if(c == '-')
        return 1;
    else if(c == '*')
        return 1;
    else if(c == '/')
        return 1;
    else if(c == '^')
        return 1;
    return 0;
}

/* definido originalmente em calculator.h
onde essa função deve ficar? */
int is_bracket(char c);

int is_function(char c) {
    /* fazendo nada. */
    return 0;
}

/* o índice retornado é sempre o do último dígito
+ 1. */
int find_number_end(char str[], int start) {
	int end = start, number_of_dots = 0;

	while(1) {
		if (is_number(str[end])) {
			end++;
		}
		else if(str[end] == '.') {
			if(number_of_dots > 1) {
				printf("smthng went wrong in validation\n");
				return -1;
			}
			else {
				end++;
			}
		}
		else if (str[end] == '\0') {
			break;
		}
		else {
			break;
		}
	}

	return end;
}
