#include <iostream>
#include "phonebook.hpp"
#include "utils.hpp"

void print(std::string s) {
	std::cout << s;
}
void print_line(std::string s) {
	std::cout << s << std::endl;
}

void print_line(std::string s1, std::string s2) {
	std::cout << s1 << s2 << std::endl;
}

void print_line(void) {
	std::cout << std::endl;
}

std::string print_form_prompt(std::string s) {
	std::string tmp;

	while (true)
	{
		print(s);
		getline(std::cin, tmp);
		if (tmp.compare(""))
			print_line("Can't have empty field in the contact");
		else
			break;
	}
	print_line(tmp);
	return (tmp);
}

std::string print_command_prompt(std::string s) {
	std::string tmp;

	print(s);
	getline
	print_line();
	return (tmp);
}

void print_guide(void){
	print_line("ADD    : save a new contact");
	print_line("SEARCH : display an specific contact");
	print_line("EXIT   : quits and the contacts are lost forever");
	print_line();
}

void print_borders() {
	for (int i = 0; i < 45; i++)
		print("-");
	print_line();
}

void print_content() {
	for (int i = 0; i < 4; i++) {
		print("|");
		for (int i = 0; i < 10; i++) {
			/* code */
		}

	}

}

bool do_command(std::string s) {
	phonebook ph;

	if (s.compare("EXIT"))
		return (false);
	if (std::remove(s.begin(), s.end(), ' ') && s.compare(""))
		return (true);
	else if (s.compare("ADD") == 0)
		ph.add_command();
	else if (s.compare("SEARCH"))
		ph.search_command();
	else
		print_line("Sry, Wrong Command :(");
	return (true);
}