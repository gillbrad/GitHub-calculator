
#include <iostream>
#include <exception>
#include "calculator.h"
#include "unittest.h"
#include "error.h"
#include "stack.h"

////////////////////////////////////////////////////////////////////
//
//  Calculator Exit values
//
//  Overflow            exit with error condition 1
//  Underflow           exit with error condition 2
//  Invalid Argument    exit with error condition 3
//  Divide by zero      exit with error condition 4
//  
//  Unit Test Exit values
//
// Unit Test FAILED Stack test exit with error condition 10
//            
// Multiply test        exit with error condition 20            
// Subtraction test     exit with error condition 30
// Divide test          exit with error condition 40 
// Subtraction test     exit with error condition 50
// Unknown error        exit with error condition 60
//
////////////////////////////////////////////////////////////////////

int main( [[maybe_unused]] int argc, [[maybe_unused]] char *argv[]) {
    // Run Unit Test for Stack and Calculator functions
    if (UnitTest() != PASS ) {
        return 0;
    }
    // Unit Test passed so run calculator
    try {
        calculator ( );
    }
    // catch block for stack related errors
    catch( const std::overflow_error& e ) {
        std::cout << e.what() << std::endl;
        // overflow error exit with error condition 1
        exit(1);
    }
    catch( const std::underflow_error& e ) {
        std::cout << e.what() << std::endl;
        // Under flow error exit with error condition 2
        exit(2);
    }
    catch( const std::invalid_argument& e ) {
        std::cout << e.what() << std::endl;
        // Invalid operator exit with error condition 3
        exit(3);
    }
    // catch block for math related errors
    catch ( const MathErrors& mathError ) {

        std::cout << "\nMath Error " << mathError << std::endl;

        switch ( mathError ) {
            
            case DIVIDE_BY_ZERO:
                // Divide by zero error exit with error condition 4
                exit(4); 
        }  
    }
    catch(...) {
        std::cout << "Unexpected Exception" << std::endl;   
    }   
    
    return 0;
}
