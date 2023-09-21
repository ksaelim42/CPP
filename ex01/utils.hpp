#ifndef UTILS_H
# define UTILS_H

#include <string>

void		print_line(std::string s);
void		print_line(std::string s1, std::string s2);
void		print_line(void);
void		print_guide(void);
bool		do_command(std::string s);
std::string print_prompt(std::string s1, std::string s2);
std::string print_prompt(std::string s);

#endif