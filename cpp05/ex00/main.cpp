#include "Bureaucrat.hpp"

int main()
{
    try
    {
        Bureaucrat A("A", 72);
        Bureaucrat B("B", 2);

        std::cout << B;
        B.increaseGrade();
        std::cout << B;
        B.increaseGrade();
        std::cout << B;
        B.increaseGrade();
        std::cout << B;
        
        A.showInfo();
        A.decreaseGrade();
        A.showInfo();
    }
    catch(const std::exception& e)
    {
        std::cerr << e.what() << '\n';
    }
    
}


