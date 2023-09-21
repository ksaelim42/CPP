#ifndef CONTACT_H
# define CONTACT_H
#include <string>

class contact
{
	private:
		std::string fname;
		std::string lname;
		std::string nname;
		std::string phone;
		std::string secret;

	public:
		contact(void);
		~contact();

		std::string	get_fname;
		std::string get_lname;
		std::string get_nname;
		std::string get_phone;
		std::string get_secret;
		void ShowContact();
		void InsertContact();
};

#endif