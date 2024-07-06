
#ifndef STACK_H
#define STACK_H

#include <exception>

const int SIZE_OF_STACK = 20;
static const int STACK_INIT_VAL = 0;

/////////////////////////////////////////////////////////////////
//
//  Stack templet <data_t>
//      Private data
//
//      data[] An array of data_t used to store 
//                  Stack Data.
//      top  An int used store the index of
//                  data where next entry is
//                  Stored.
//
//      Piblic Functions 
//         
//      Stack( )    Constructor used to init top
//      push( )  Function used to load v to data
//                      at index top
//
//                          Params  v Data to be pushed to Stack
//                                  at index top
//                          return  None
//
//      exception   will throw an exctption if Stach is over run
//                  or type StackErrors OVER_FLOW
//
//      pop( )  Function used to remove value stored in 
//                      data[] stored at top
//
//                          Params  None
//                          return  data_t type stored in data[]
//                                  at index top  
//
//              exception   will throw an exctption if Stach is under run
//                          or type StackErrors UNDER_FLOW                                       
// 
/////////////////////////////////////////////////////////////////                                                     


template <class data_t> 
class Stack {
private:
    data_t *data;
    int top;
    int size;

public:
    Stack( int sizeOfStack ) : top{STACK_INIT_VAL}, size{sizeOfStack} { data = new data_t[sizeOfStack]; }
    ~Stack( ) { delete[] data; }
    void push( data_t val );
    data_t pop( ); 
    int  get_top( ) { return top; }
    void reset( ) { top=STACK_INIT_VAL; }
    bool empty( ) { return (top == 0); }  
};

///////////////////////////////////////////////////////////////////////////////
//
//  Stack Class Public Definition: push
//
//      Definition:     Used to Push a new entry onto the stack.
//      Params:         int v to be pushed onto the stack.
//      return:         None
//
//      Side Effects:   Will increment Private Member top
//                      Will modify Private Member data[]
//
///////////////////////////////////////////////////////////////////////////////
template <class data_t> 
void Stack<data_t>::push( data_t val ) {
    if ( top >= SIZE_OF_STACK ) {
        // Set error condition to Stack Over Flow and throw Error 
        throw( std::overflow_error ("Stack Over Flow") );   
    }
    data[top] = val;  
    ++top; 
}

///////////////////////////////////////////////////////////////////////////////
//
//  Stack Class Public Definition: pop
//
//      Definition:     Used to get entry off of stack of type data_t
//                      at top.
//      Params:         None
//      return:         The data type data_t value stored on data[] at index
//                      top.
//
//      Side Effects:   Will decrement Private Member top
//
///////////////////////////////////////////////////////////////////////////////
template <class data_t> 
data_t Stack<data_t>::pop( ) {
    if ( top == STACK_INIT_VAL ) {
        // Set error condition to Stack Over Flow and throw Error 
        throw( std::underflow_error("Stack Under Flow") );   
    }
    //  Decrement top so it aligns with last val Pushed onto Stack
    --top;
    return data[top];
}
#endif // #ifndef STACK_H

