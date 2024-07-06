#ifndef ERROR_H
#define ERROR_H

enum Status {
    PASS,
    STACK_FAILURE,
    ADD_FAILURE,
    SUB_FAILURE,
    MUL_FAILURE,
    DIV_FAILURE
};

enum StackErrors {
    NO_STACK_ERROR,
    UNDER_FLOW = 10,
    OVER_FLOW = 20
};

enum MathErrors {
    DIVIDE_BY_ZERO = 30
};

void ErrorHandler( Status eStatus );

#endif // #ifndef ERROR_H