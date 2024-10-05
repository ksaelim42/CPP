#include "Intern.hpp"

Intern::Intern() {
    _formName[0] = "shrubbery creation";
	_formName[1] = "robotomy request";
	_formName[2] = "presidential pardon";
}

Intern::Intern(Intern const& r) {
    _formName[0] = "shrubbery creation";
	_formName[1] = "robotomy request";
	_formName[2] = "presidential pardon";
    (void)r;
}

Intern&	Intern::operator=(Intern const& r) {
	if (this != &r) {
        return *this;
	}
	return *this;
}

Intern::~Intern() {}

// ********************************************************** //
// --------------------- Member Functions ------------------- //
// ********************************************************** //

AForm*	Intern::makeForm(std::string const formName, std::string const targetName) const {
	for (int i = 0; i < 3; i++) {
		if (formName == _formName[i]) {
			std::cout << GREEN << "Intern creates " << _formName[i] << RESET << std::endl;
			switch (i) {
				case 0:
					return new ShrubberyCreationForm(targetName);
				case 1:
					return new RobotomyRequestForm(targetName);
				case 2:
					return new PresidentialPardonForm(targetName);
			}
		}
	}
	std::cout << RED << formName << " form doesn’t exist." << RESET << std::endl;
	return (NULL);
}