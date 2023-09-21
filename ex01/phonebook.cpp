#include "phonebook.hpp"

phonebook::phonebook()
{
	this->size = 0;
}

void phonebook::add_command() {
	contact contact;

	contact.InsertContact();
}

void phonebook::search_command() {
	if (this->size > 0) {
		
	} else
		print_line("No Contact");
}