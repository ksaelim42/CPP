#include "ScalarConverter.hpp"

int main()
{
    ScalarConverter test;

    test.convert("42.0f");
    std::cout << std::endl;
    test.convert("42.12");
     std::cout << std::endl;
    test.convert("0");
     std::cout << std::endl;

    test.convert("Hello");
    std::cout << std::endl;


    test.convert("126");
    std::cout << std::endl;

    test.convert("130");
    std::cout << std::endl;

    test.convert("nan");
    std::cout << std::endl;


    test.convert("inf");
    std::cout << std::endl;

    test.convert("-inf");
    std::cout << std::endl;
    
    test.convert("+inf");
    std::cout << std::endl;
}