#include <iostream>
#include <cctype>

void print_upper_str(char *str)
{
	while (*str)
		std::cout << (char)toupper(*str++);
}

int main(int ac, char *av[])
{
	if (ac == 1)
		std::cout << "* LOUD AND UNBEARABLE FEEDBACK NOISE *" << std::endl;
	else {
		for (int i = 1; i < ac; i++)
			print_upper_str(av[i]);
		std::cout << std::endl;
	}
	return 0;
}