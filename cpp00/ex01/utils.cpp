#include <iostream>
#include "utils.hpp"
#include <vector>
#include <sstream>
#include <iomanip> //using setw()

void print(std::string s) {
	std::cout << s;
}

void print_line(std::string s) {
	std::cout << s << std::endl;
}

void print_line(std::string s1, std::string s2) {
	std::cout << s1 << s2 << std::endl;
}

void print_line(std::string s1, std::string s2, std::string s3) {
	std::cout << s1 << s2 << s3 << std::endl;
}

void print_line(void) {
	std::cout << std::endl;
}

bool	check_emptyline(std::string s) {
	for (std::string::iterator it = s.begin(); it != s.end(); it++) {
		if (!std::isspace(*it))
			return (true);
	};
	return (false);
}

std::string contact_prompt(std::string s) {
	std::string field;

	while (true)
	{
		field = command_prompt(s);
		if (!check_emptyline(field))
				print_line("Can't have empty in this field");
		else
			break;
	}
	return (field);
}

std::string command_prompt(std::string s) {
	std::string tmp;

	print(s);
	std::getline(std::cin, tmp);
	print_line();
	return (tmp);
}

void print_guide(void){
	print_line("ADD    : save a new contact");
	print_line("SEARCH : display an specific contact");
	print_line("EXIT   : quits and the contacts are lost forever");
	print_line();
}

std::string	text_form(std::string s) {
	if (s.length() > 10)
		return (s.substr(0, 9) + ".");
	return (s);
}

std::string	ft_itos(int i) {
	std::ostringstream oss;
    oss << i;
    return oss.str();
}

void print_table(std::string col1, std::string col2, std::string col3, std::string col4)
{
	std::cout << "|" << std::setw(10) << std::right << text_form(col1)
		  	  << "|" << std::setw(10) << std::right << text_form(col2)
			  << "|" << std::setw(10) << std::right << text_form(col3)
			  << "|" << std::setw(10) << std::right << text_form(col4) << "|" << std::endl;
	for (int i = 0; i < 45; i++) {
		std::cout << "-";
	}
	print_line();
}
