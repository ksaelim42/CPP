#include "phonebook.hpp"
#include <iostream>

Phonebook::Phonebook()
{
	this->size = 0;
}

void Phonebook::add_command() {
	Contact contact;
	static int		i = 0;

	contact.InsertContact();
	if (this->size >= MAX_CONTACT) {
		if (i == 8)
			i = 0;
		this->contact[i++] = contact;
	}
	else
		this->contact[this->size++] = contact;
}

int	check_index(std::string s) {
	for (size_t i = 0; i < s.length(); i++) {
        if (!isdigit(s[i]))
            return -1;
    }
	int n = std::atoi(s.c_str());
	if (n >= 0 && n <= 7)
    	return n;
	else
		return -1;

}

void Phonebook::search_command() {
	int	index = 0;
	if (this->size > 0) {
		print_table("Index", "Firstname", "Lastname", "Nickname");
		for (int i = 0; i < this->size; i++) {
			print_table(ft_itos(i), this->contact[i].get_fname(), this->contact[i].get_lname(), this->contact[i].get_nname());
		}
		index = check_index(command_prompt("Enter Index : "));
		if (index >= 0)
			this->contact[index].ShowContact(ft_itos(index));
		else
			print_line("Lol, It's out of range");
	} else
		print_line("No Contact :(");
}
