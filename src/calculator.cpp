#include <iostream>
#include <cctype>
#include <exception>
#include "error.h"
#include "stack.h"
#include "mathfuns.h"
#include "calculator.h"
#include "unittest.h"

/////////////////////////////////////////////////////////////////
//
//  Function valid_operation
//      Discription:    Validates for valid math operation 
//
//      Params: char operation ( Valid operations + - / * )
//
//      Return: true if operation is valid                                   
// 
/////////////////////////////////////////////////////////////////
bool valid_operation( char operation ) {
    if ( ( operation == '/') || ( operation == '*') || ( operation == '+') || ( operation == '-') ) {
        return true;
    }
    return false;
}
/////////////////////////////////////////////////////////////////
//
//  Function calculator
//      Discription:    Will perform basic math operations
//                          on two input values
//
//      Params: None
//
//      Return: None                                   
// 
/////////////////////////////////////////////////////////////////
void calculator ( ) {
    std::cout << "\n****Calculator****" << std::endl;  
    
    char operation;
    while (true) {
        std::cout << "\nChoose Mathematical operation * / + -" << std::endl;
        std::cout << "Choose Q to Quit" << std::endl;

        std::cin >> operation;
        operation = (char) toupper( operation );

        if( operation == 'Q' ) {
            return;
        }
        if ( !(valid_operation( operation ) ) ) {
            // Set error condition to Invalid Argument and throw Error 
            throw(std::invalid_argument("Invalid Math Operation")); 
        }
        
        if ( operation == '/' ) {
            char rDiv;
            int intVal_1, intVal_2;
            Stack<int> intStack(20);
            std::cout << "\n***Divide***" << std::endl;
            std::cout << "\nDo you Want to Divide with remainder ?" << std::endl;
            std::cout << "Enter Y for Yes" << std::endl;
            std::cin >> rDiv;
            rDiv = (char) toupper( rDiv );

            if( rDiv == 'Y' )  {
                std::cout << "\nEnter First interger Value " << std::endl;
                std::cin >> intVal_1;
                intStack.push( intVal_1 );

                std::cout << "\nEnter Second interger Value " << std::endl;
                std::cin >> intVal_2;
                intStack.push( intVal_2 );
                 
                DivideData DivData = divide_w_rem( intStack );
                std::cout << "\n" << intVal_1 << " / " << intVal_2 << " = " << DivData.quotient << " With remainder " << DivData.remainder << std::endl;
                continue;
            } 
        }
        
        Stack<float> stack(20);
        float v1, v2;
        
        std::cout << "\nEnter First Value " << std::endl;
        std::cin >> v1;
        stack.push( v1 );

        std::cout << "\nEnter Second Value " << std::endl;
        std::cin >> v2;
        stack.push( v2 );     
    
        switch( operation ) {
            case '*': {
                std::cout << "\n***Multiply***" << std::endl;
                float answer = multiply( stack );
                std::cout << "\n" << v1 << " * " << v2 << " = " << answer << std::endl; 
                break; 
            } 
            case '/': {
                float answer = divide( stack );
                std::cout << "\n" << v1 << " / " << v2 << " = " << answer << std::endl;
                break;  
            }
            case '+': {
                std::cout << "\n***Add***" << std::endl; 
                float answer = add( stack );
                std::cout << "\n" << v1 << " * " << v2 << " = " << answer << std::endl; 
                break; 
            } 
            case '-': {
                std::cout << "\n***Subtract***" << std::endl; 
                int answer = subtract( stack );
                std::cout << "\n" << v1 << " - " << v2 << " = " << answer << std::endl;
                break; 
            }
        }
    }
}