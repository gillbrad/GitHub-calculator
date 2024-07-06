
#include <iostream>
#include "unittest.h"
#include "error.h"

void ErrorHandler( Status eStatus ) {
    switch ( eStatus ) {
        case STACK_FAILURE:
            // Unit Test FAILED Stack test exit with error condition 10
            exit(10);
        case MUL_FAILURE:
            // Unit Test FAILED Multiply test exit with error condition 20
            exit(20);
        case SUB_FAILURE:
            // Unit Test FAILED Subtraction test exit with error condition 30
            exit(30);
        case DIV_FAILURE:
            // Unit Test Divide Divide test exit with error condition 40
            exit(40);
        case ADD_FAILURE:
            // Unit Test FAILED Subtraction test exit with error condition 50
            exit(50);
        default:
            // Unknown error exit with error condition 60
            exit(60);
    }
}
