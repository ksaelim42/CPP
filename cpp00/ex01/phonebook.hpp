#ifndef PHONEBOOK_HPP
#define PHONEBOOK_HPP

#define MAX_CONTACT 8
#include "contact.hpp"
#include "utils.hpp"
#include <cstdlib>
#include <string>

class Phonebook {
	private:
		int		size;
		Contact contact[MAX_CONTACT];
	public:
		Phonebook(void);

		void	add_command();
		void	search_command();
};


#endif