#include <iostream>
#include <exception>

void do_stuff(int x)
{
    if ( x < 0 )
    { 
        throw(std::invalid_argument("x is negative!"));
    }
}

void do_more(int y)
{
    if (y > 10)
    {
        throw std::range_error("y is too big!");
    }
}

int main([[maybe_unused]] int argc, [[maybe_unused]] char* argv[])
{
    
    try
    {
        do_stuff(99);
        do_more(99); 
    }
    catch( const std::invalid_argument& e )
    {
        std::cout << "We caught an invalid_argument! " << e.what() << std::endl;
        // Do stuff to handle this!
        return(1);
    } 
    catch( const std::range_error& e )
    {
        std::cout << "We caught an invalid_argument! " << e.what() << std::endl;
        return(2);
        // Do stuff to handle this!
    }
    catch( const std::exception& e )
    {
        std::cout << "Caught an invalid_argument: " << e.what() << std::endl;
        return(3);
    }
    catch( ... )
    {
        std::cout << "Unknown error." << std::endl;
        return(99);
    }

    std::cout << "Continue running..." << std::endl;
    return 0;
}

