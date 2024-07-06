#include <iostream>
#include "error.h"
#include "stack.h"
#include "mathfuns.h"
#include "calculator.h"
#include "unittest.h"

/////////////////////////////////////////////////////////////////
//
//  Unit Test
//      Discription:    
//          Will Test Stack and math functions
//          if Test passes calculator function will be 
//          able to run
//                                    
// 
/////////////////////////////////////////////////////////////////

/////////////////////////////////////////////////////////////////
//
//  Function test_stack
//      Discription:    
//          Unit test to test the following:
//              1. Stack index Value (top)
//              2. Values loaded onto stack are correct
//              3. Stack Over Flow
//              4. Stack Under Flow
//
//      Params: None  
//
//      Return: Enumerated values for status of test                                     
// 
/////////////////////////////////////////////////////////////////
Status test_stack( ) {
    Stack<int>  uStack(20);

    // Test to make sure stack is init properly
    if (!(uStack.empty( ))) {
        return STACK_FAILURE;
    }
    for ( int index = 0; index < 5; index++ ) {
        uStack.push( index );   
    }
    // Test to see if top is valid
    if ( uStack.get_top( ) != 5 ) {
        return STACK_FAILURE;
    }
    int sVal;

    // Test to see is Stack Vals are valid
    for ( int index = 0, sIndex = 4; index < 5; ++index, --sIndex ) {
        sVal = uStack.pop( );
        if ( sVal != sIndex ) {
            return STACK_FAILURE;
        }
    }
    uStack.reset( );
    StackErrors stackError = UNDER_FLOW;
    // Test for under run of stack
    try {
        sVal = uStack.pop(  );
    }
    catch( const std::underflow_error& e ) {
        std::cout << "Unit Test expected error "<< e.what() << std::endl;
        stackError = NO_STACK_ERROR;
    }
    if ( stackError != NO_STACK_ERROR ) {
        return STACK_FAILURE;
    } 
    // Test for under run of stack
    uStack.reset( );
    stackError = OVER_FLOW; 
    // Push max number of data onto stack (should not over run)   
    for ( int index = 0; index < ( SIZE_OF_STACK ); ++index ) {
        uStack.push( index );    
    }
    // Now push one more on (should over run)
    try {
        uStack.push( 10 );
    }
    catch( const std::overflow_error& e ) {
        std::cout << "Unit Test expected error "<< e.what() << std::endl;
        stackError = NO_STACK_ERROR;
    }
    if ( stackError != NO_STACK_ERROR ) {
        return STACK_FAILURE;
    }
    return PASS;
}

//////////////////////////////////////////////////////////////////////////////
//
//  Unit Test Definition: mutiply_test
//
//      Definition:     Will Test for basic functionality 
//                          ( multiply add ints and test results) 
//      Params:         None         
//      return:         Status (Pass or Fail)
//
//      Side Effects:   None
//
///////////////////////////////////////////////////////////////////////////////
Status mutiply_test( ) {
    Stack<int>  uStack(20);

    uStack.push( 10 );
    uStack.push( 20 );

    int answer = multiply(uStack );

    if ( answer == 200 )
    {
        return PASS;    
    }
    return MUL_FAILURE;   
}

//////////////////////////////////////////////////////////////////////////////
//
//  Unit Test Definition: divide_w_float_test
//
//      Definition:     Will Test for basic functionality 
//                          ( devide two ints and test results) 
//      Params:         None         
//      return:         Status (Pass or Fail)
//
//      Side Effects:   None
//
///////////////////////////////////////////////////////////////////////////////
Status divide_w_float_test( ) {
    Stack<int>  uStack(20);

    uStack.push( 10 );
    uStack.push( 20 );
    
    float answer = divide( uStack );
    if ( answer == 0.5 )
    {
        return PASS;    
    }
    return DIV_FAILURE;   
}

//////////////////////////////////////////////////////////////////////////////
//
//  Unit Test Definition: divide_w_rem_test
//
//      Definition:     Will Test for basic functionality 
//                          ( devide two ints and test results) 
//      Params:         None         
//      return:         Status (Pass or Fail)
//
//      Side Effects:   None
//
///////////////////////////////////////////////////////////////////////////////
Status divide_w_rem_test( ) {
    Stack<int>  uStack(20);

    uStack.push( 100 );
    uStack.push( 21 );

    DivideData data = divide_w_rem( uStack );
    
    if ( ( data.quotient == 4 ) && ( data.remainder == 16 ) )
    {
        return PASS;    
    }
    return DIV_FAILURE;   
}

//////////////////////////////////////////////////////////////////////////////
//
//  Unit Test Definition: add_test
//
//      Definition:     Will Test for basic functionality 
//                          ( subtract add ints and test results) 
//      Params:         None         
//      return:         Status (Pass or Fail)
//
//      Side Effects:   None
//
///////////////////////////////////////////////////////////////////////////////
Status add_test( ) {
    Stack<int>  uStack(20);

    uStack.push( 10 );
    uStack.push( 20 );

    int answer = add( uStack );
    if ( answer == 30 ) {
        return PASS;    
    }
    return ADD_FAILURE;   
}

//////////////////////////////////////////////////////////////////////////////
//
//  Unit Test Definition: subtraction_test
//
//      Definition:     Will Test for basic functionality 
//                          ( subtract two ints and test results) 
//      Params:         None         
//      return:         Status (Pass or Fail)
//
//      Side Effects:   None
//
///////////////////////////////////////////////////////////////////////////////
Status subtraction_test( ) {
    Stack<int>  uStack(20);

    uStack.push( 20 );
    uStack.push( 10 );

    int answer = subtract( uStack );
    if ( answer == 10 )
    {
        return PASS;    
    }
    return SUB_FAILURE;   
}

///////////////////////////////////////////////////////////////////////////////
//
//  UnitTest
//
//      Definition:     Used to test:
//                          1. Stack for following:
//                              a. Stack index 
//                              b. Data integrity
//                              c. Over Run
//                              d. Under Run
//                          2. Multiply function 
//                          3. Add function
//                          3. Subtract function
//                          
//      Params:         None
//      return:         Status (Pass or Fail)
//
//      Side Affects:   None
//
///////////////////////////////////////////////////////////////////////////////
Status UnitTest( void ) {
    // Test for stack faiures
    std::cout << "\n***Running Unit Test***" << std::endl;
    if ( test_stack( ) == PASS ) {
        std::cout << "\n***Stack Test PASS***" << std::endl;
    }
    else {
        std::cout << "***Stack Test FAILED***" << std::endl;
        return STACK_FAILURE;   
    }
    // Test multiply( )
    if ( mutiply_test( ) == PASS ) {
        std::cout << "***Mutiply Test PASS***" << std::endl;
    }
    else {
        std::cout << "***Mutiply Test FAILED***" << std::endl;
        return MUL_FAILURE;   
    }
    // Test divide_w_float( )
    if ( divide_w_float_test( ) == PASS ) {
        std::cout << "***Divide with float Test PASS***" << std::endl;
    }
    else {
        std::cout << "***Divide with float Test FAILED***" << std::endl;
        return DIV_FAILURE;   
    }
    // Test divide_w_rem( )
    if ( divide_w_rem_test( ) == PASS ) {
        std::cout << "***Divide with remainder Test PASS***" << std::endl;
    }
    else {
        std::cout << "***Divide with remainder Test FAILED***" << std::endl;
        return DIV_FAILURE;   
    }
    // Test add( )
    if ( add_test( ) == PASS ) {
        std::cout << "***Add Test PASS***" << std::endl;
    }
    else {
        std::cout << "***Add Test FAILED***" << std::endl;
        return ADD_FAILURE;   
    }
    // Test subtract( )
    if ( subtraction_test( ) == PASS ) {
        std::cout << "***Subtraction Test PASS***" << std::endl;
    }
    else {
        std::cout << "***Subtraction Test FAILED***" << std::endl;
        return SUB_FAILURE;   
    }
    return PASS;  
}
