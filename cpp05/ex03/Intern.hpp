#ifndef Intern_HPP
# define Intern_HPP

# include "Bureaucrat.hpp"
# include "ShrubberyCreationForm.hpp"
# include "RobotomyRequestForm.hpp"
# include "PresidentialPardonForm.hpp"


class Bureaucrat; // Forward Declaration

class Intern
{
	private:
		std::string		_formName[3];

	public:
		Intern();
		Intern(Intern const& other);
		Intern&	operator=(Intern const& rhs);
		~Intern();

		AForm*	makeForm(std::string const formName, std::string const targetName) const;
};

#endif