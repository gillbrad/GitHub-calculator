#include <iostream>
#include "error.h"
#include "stack.h"
#include "mathfuns.h"
#include "calculator.h"

///////////////////////////////////////////////////////////////////////////////
//
//  Public Function Definitions
//
/////////////////////////////////////////////////////////////////////////////// 

/////////////////////////////////////////////////////////////////
//
//  Function divide_w_rem
//      Discription:    Math Function that will devide two
//                      Interger Values
//
//      Params: reference to callers local DivideData pointer
//              reference to callers local Stack class 
//
//      Return: struct DivideData 
//                  int quotient  
//                  int remainder                                   
// 
/////////////////////////////////////////////////////////////////
DivideData divide_w_rem( Stack<int> &myStack ) {
    // Retrieve val1 and val2 from Stack
    int val1 = myStack.pop( );
    int val2 = myStack.pop( );

    if ( val1 == 0 ) {
        MathErrors mathError = DIVIDE_BY_ZERO;
        throw mathError;
    }

    DivideData data;
    data.quotient = ( val2 / val1 );
    // Use Mod opperator to calculate remainder
    data.remainder = ( val2 % val1 );

    return data;
}