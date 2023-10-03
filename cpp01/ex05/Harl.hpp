#ifndef HARL_H
# define HARL_H

#include <string>
#include <iostream>

class Harl
{
	private:
		void _debug(void);
		void _info(void);
		void _warning(void);
		void _error(void);
		std::string _level[4];
	public:
		Harl();
		~Harl();
		void complain( std::string level);
};

void print_line();

void print_line(std::string s);

void print_line(std::string s1, std::string s2);

#endif