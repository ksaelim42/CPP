#include "Harl.hpp"

int main(int ac, char *av[]) {
	Harl	harl;
	if (ac != 2)
		return (print_line("Function recieve one argrument!"), 1);
	harl.complain(harl.harlFilter(av[1]));
	return 0;
}