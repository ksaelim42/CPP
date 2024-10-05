#include "Bureaucrat.hpp"

int main()
{
    try
    {
        Bureaucrat A("A", 72);
        Bureaucrat B("B", 2);

        std::cout << A;
        std::cout << B;
        B.increaseGrade();
        std::cout << B;
        B.increaseGrade();
        std::cout << B;
        B.increaseGrade();
        std::cout << B;
        
        std::cout << A;
        A.decreaseGrade();
        std::cout << A;
    }
    catch(const std::exception& e)
    {
        std::cerr << e.what() << '\n';
    }
    
}


