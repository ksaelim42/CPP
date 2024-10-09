#include "Span.hpp" 

int main() {

    try {
        Span outMax = Span(5);
        outMax.addNumber(6);
        outMax.addNumber(3);
        outMax.addNumber(17);
        outMax.addNumber(9);
        outMax.addNumber(11);
        std::cout << "shortestSpan: " << outMax.shortestSpan() << std::endl;
        std::cout << "shortestSpan: " << outMax.longestSpan() << std::endl;


        // outMax.addNumber(12);


        Span minimumNum = Span(10000);
        for (size_t i = 0; i < 10000; i++)
            minimumNum.addNumber(i);

        std::cout << "sp2 size: " << minimumNum.size() << std::endl;
    
        // Span noNum = Span(1);
        // std::cout << "shortestSpan: " << noNum.shortestSpan() << std::endl;
        
        // Span onlyOne = Span(1);
        // onlyOne.addNumber(2);
        // std::cout << "shortestSpan: " << onlyOne.shortestSpan() << std::endl;
        
        // Span noSpan = Span(5);
        // for (size_t i = 0; i < 5; i++)
        //     noSpan.addNumber(2);
        // std::cout << "shortestSpan: " << noSpan.shortestSpan() << std::endl;

    }
    catch(const std::exception& e) {
        std::cerr << e.what() << '\n';
    }
    
    return 0;
}