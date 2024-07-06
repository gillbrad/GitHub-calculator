
#ifndef MATHFUNS_H
#define MATHFUNS_H


/////////////////////////////////////////////////////////////////
//
//  Stack DivideData
//      Private data:
//
//      quotient:       Interger value of ( Numerator / Denominator )
//      remainder:      Fractional Value what is left over
//                      from ( Numerator / Denominator )
//
//      Piblic Functions: 
//         
//      get_quotient( )  Public Definition of Function to retrieve 
//                      private member quotient.  
//      get_remainder( ) Public Definition of Function to retrieve 
//                      private member remainder.                                      
// 
/////////////////////////////////////////////////////////////////

struct DivideData {
    int quotient;
    int remainder;
};



/////////////////////////////////////////////////////////////////
//
//  MathFuns public protypes                                        
// 
/////////////////////////////////////////////////////////////////

/////////////////////////////////////////////////////////////////
//
//  Function multiply
//      Discription:    Math Function that will multiply two
//                      Interger Values
//
//      Params: reference to callers local Stack class  
//
//      Return: Interger Value of Val1 * Val2                                     
// 
/////////////////////////////////////////////////////////////////
template <class data_t>
data_t multiply( Stack<data_t> &myStack ) {
    // Retrieve val1 and val2 from Stack
    data_t val1 = myStack.pop( );
    data_t val2 = myStack.pop( );

    return ( val1 * val2 );
}

/////////////////////////////////////////////////////////////////
//
//  Function divide
//      Discription: Math Function that will devide two Values
//
//      Params: reference to callers local Stack class 
//
//      Return: Interger Value of Val1 * Val2                                     
// 
/////////////////////////////////////////////////////////////////
template <class data_t>
float divide( Stack<data_t> &myStack ) {
    // Retrieve val1 and val2 from Stack
    data_t val1 = myStack.pop( );
    data_t val2 = myStack.pop( );

    if ( val1 == 0.0 ) {
        MathErrors mathError = DIVIDE_BY_ZERO;
        throw mathError;
    }

    float answer =  ( ( (float) val2 ) / ( (float) val1 ) ); 

    return answer;
}

/////////////////////////////////////////////////////////////////
//
//  Function DivideFun
//      Discription:    Math Function that will devide two
//                      Interger Values
//
//      Params: reference to callers local Stack class  
//
//      Return: Interger Value of Val1 - Val2                                     
// 
/////////////////////////////////////////////////////////////////
template <class data_t>
data_t subtract( Stack<data_t> &myStack ) {
    // Retrieve val1 and val2 from Stack
    data_t val1 = myStack.pop( );
    data_t val2 = myStack.pop( );
    
    return ( val2 - val1 );
}

/////////////////////////////////////////////////////////////////
//
//  Function add
//      Discription:    Math Function that will add two
//                      Interger Values
//
//      Params: reference to callers local Stack class  
//
//      Return: Interger Value of Val1 + Val2                                     
// 
/////////////////////////////////////////////////////////////////
template <class data_t>
int add( Stack<data_t> &myStack ) {
    // Retrieve val1 and val2 from Stack
    data_t val1 = myStack.pop( );
    data_t val2 = myStack.pop( );
    
    return ( val1 + val2 );
}

DivideData  divide_w_rem     ( Stack<int> &myStack );

#endif // #ifndef MATHFUNS_H