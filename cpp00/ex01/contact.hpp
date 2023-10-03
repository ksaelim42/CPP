#ifndef CONTACT_HPP
# define CONTACT_HPP
#include <string>

class Contact
{
	private:
		std::string fname;
		std::string lname;
		std::string nname;
		std::string phone;
		std::string secret;

	public:
		Contact(void);
		~Contact();

		std::string	get_fname();
		std::string get_lname();
		std::string get_nname();
		std::string get_phone();
		std::string get_secret();
		void ShowContact(std::string n);
		void InsertContact();
};

#endif