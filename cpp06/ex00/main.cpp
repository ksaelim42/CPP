#include "ScalarConverter.hpp"

int	main(int ac, char **av)
{
	if (ac != 2)
	{
		std::cerr << RED << "Program take one parameter." << std::endl;
		std::cerr << "<Usage>: ./convert inff" << RESET << std::endl;
		return 1;
	}
	ScalarConverter::convert(av[1]);
	return (0);
}