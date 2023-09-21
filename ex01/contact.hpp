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

		void ShowContact();
		void InsertContact();
};

#endif