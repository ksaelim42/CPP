#ifndef PHONE_BOOK_H
#define PHONE_BOOK_H

#define MAX_CONTACT 8
#include "contact.hpp"
#include "utils.hpp"

class phonebook
{
	private:
		int		size;
		contact list[MAX_CONTACT];
	public:
		phonebook(void);

		void	add_command();
		void	search_command();
};


#endif