#include "BitcoinExchange.hpp"
int main(int ac, char **av)
{
    (void)ac;
    if(ac != 2)
    {
        std::cout << "Error: could not open file." << std::endl;
        return 1;
    }

    // BitcoinExchange b("test","test");
    // BitcoinExchange a(b);
    BitcoinExchange b(av[1]);
    return 0;
    // BitcoinExchange("data1.csv","data.csv"); //for testing purposes
    // BitcoinExchange("./test/data1.csv","data.csv"); //for testing purposes
}