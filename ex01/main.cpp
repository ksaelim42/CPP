#include <iostream>
#include "utils.hpp"
#include "phonebook.hpp"


int main(void)
{
	std::string	cmd;
	phonebook	ph;

	while (true)
	{
		print_guide();
		cmd = print_prompt("Which your command ? : ");
		if (!do_command())
			break;
	}
	print_line("BYE ~~");
	return 0;
}