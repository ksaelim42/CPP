#include "RPN.hpp"

int main(int ac, char**av)
{
	try
	{
		if (ac != 2) {
			std::cerr << "<Usage>: ./RPN \"8 9 * 9 - 9 - 9 - 4 - 1 +\"" << std::endl;
			return 1;
		}

		RPN rpn;	
		std::cout << rpn.calculate(av[1]) << std::endl;
	}
	catch(const std::exception &e)
	{
		std::cerr << e.what() << std::endl;
	}
	return 0;
}