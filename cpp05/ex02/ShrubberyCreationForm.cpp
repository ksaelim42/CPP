#include "ShrubberyCreationForm.hpp"

ShrubberyCreationForm::ShrubberyCreationForm(std::string target): AForm("ShrubberyCreationForm", 145, 137), _target(target) {}

ShrubberyCreationForm::ShrubberyCreationForm(ShrubberyCreationForm const& r)
: AForm(r)
{
	// std::cout << YELLOW << "[ShrubberyCreationForm] Copy Constructor Called" << RESET << std::endl;
}

ShrubberyCreationForm&	ShrubberyCreationForm::operator=(ShrubberyCreationForm const& rhs)
{
	if (this != &rhs)
	{
		AForm::operator=(rhs);
		this->_target = rhs._target;
		// std::cout << YELLOW << "[ShrubberyCreationForm] Copy Assignment Operator Called" << RESET << std::endl;
	}
	return (*this);
}

ShrubberyCreationForm::~ShrubberyCreationForm()
{
	// std::cout << YELLOW << "[ShrubberyCreationForm] Destructor Called" << RESET << std::endl;
}