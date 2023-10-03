#include "Harl.hpp"

Harl::Harl()
{
	this->_level[0] = "DEBUG";
	this->_level[1] = "INFO";
	this->_level[2] = "WARNING";
	this->_level[3] = "ERROR";
}

Harl::~Harl() {}

void print_line() {
	std::cout << std::endl;
}

void print_line(std::string s) {
	std::cout << s << std::endl;
}

void print_line(std::string s1, std::string s2) {
	std::cout << s1 << s2 << std::endl;
}

void Harl::_debug(void) {
	print_line("[ DEBUG ]");
	print_line("I love having extra bacon for my 7XL-double-cheese-triple-pickle-special-ketchup burger.") ;
	print_line("I really do!");
}

void Harl::_info(void) {
	print_line("[ INFO ]");
	print_line("I cannot believe adding extra bacon costs more money.");
	print_line("You didn’t put enough bacon in my burger! If you did, I wouldn’t be asking for more!");
}

void Harl::_warning(void) {
	print_line("[ WARNING ]");
	print_line("I think I deserve to have some extra bacon for free.");
	print_line("I’ve been coming for years whereas you started working here since last month.");
}

void Harl::_error(void) {
	print_line("[ ERROR ]");
	print_line("This is unacceptable, I want to speak to the manager now.");
}


int Harl::harlFilter(std::string s) {
	for (size_t i = 0; i < 4; i++) {
		if (s == this->_level[i])
			return i;
	}
	return -1;
}

void Harl::complain(int level) {
	switch (level)
	{
		case 0:
			Harl::_debug();
			Harl::_info();
			Harl::_warning();
			Harl::_error();
			break;
		case 1:
			Harl::_info();
			Harl::_warning();
			Harl::_error();
			break;
		case 2:
			Harl::_warning();
			Harl::_error();
			break;
		case 3:
			Harl::_error();
			break;
		default:
			print_line("[ Probably complaining about insignificant problems ]");
			break;
	}
}
