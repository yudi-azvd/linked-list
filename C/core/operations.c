#include "operations.h"


void operate(char** operand1, char* operand2, char* oper4tor) {
    double op1, op2, result;

    sscanf(*operand1, "%lf", &op1);
    sscanf(operand2, "%lf", &op2);

    if     (*oper4tor == '+') {
        result = op2+op1;
    }
    else if(*oper4tor == '-') {
        result = op2-op1;
    }
    else if(*oper4tor == '*') {
        result = op2*op1;
    }
    else if(*oper4tor == '/') {
        result = op2/op1;
    }
    else {

    }

    // *operand1 = realloc(operand1, OPERAND_MAX_SIZE);
    snprintf(*operand1, OPERAND_MAX_SIZE, "%lf", result);

    // printf("re insi operate: %s\n", *operand1);
    // printf("re insi operate: %lf\n", result);

    return ;
}
