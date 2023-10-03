#include <iostream>
#include "utils.hpp"
#include "phonebook.hpp"

int main(int ac, char *av[])
{
	std::string	cmd;
	Phonebook	ph;

	if (ac > 1)
		return 0;
	(void)av;
	print_guide();
	while (true) {
		// wait for command
		cmd = command_prompt("Which your command ? : ");

		// check whitespace string
		if (!check_emptyline(cmd))
			continue ;

		// check correct command
		if (cmd == "EXIT")
			break ;
		else if (cmd == "ADD")
			ph.add_command();
		else if (cmd == "SEARCH")
			ph.search_command();
		else
			print_line("Sry, Wrong Command :(");
	}
	print_line("BYE bye ~~");
	return 0;
}