#ifndef UTILS_H
# define UTILS_H

#include <string>
#include "phonebook.hpp"

void		print_line(std::string s);
void		print_line(std::string s1, std::string s2);
void        print_line(std::string s1, std::string s2, std::string s3);
void		print_line(void);
void		print_guide(void);
void        print_table(std::string col1, std::string col2, std::string col3, std::string col4);
bool        check_emptyline(std::string s);
// bool        do_command(std::string s, Phonebook& ph);
std::string ft_itos(int i);
std::string print_prompt(std::string s1, std::string s2);
std::string command_prompt(std::string s);
std::string contact_prompt(std::string s);

#endif