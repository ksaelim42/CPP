#include "PresidentialPardonForm.hpp"

PresidentialPardonForm::PresidentialPardonForm(std::string target): AForm("PresidentialPardonForm", 25, 5), _target(target) {}

PresidentialPardonForm::PresidentialPardonForm(PresidentialPardonForm const& r): AForm(r), _target(r._target) {}

PresidentialPardonForm&	PresidentialPardonForm::operator=(PresidentialPardonForm const& r) {
	if (this != &r) {
		AForm::operator=(r);
		this->_target = r._target;
	}
	return (*this);
}

PresidentialPardonForm::~PresidentialPardonForm() {}

// ********************************************************** //
// --------------------- Member Functions ------------------- //
// ********************************************************** //

void	PresidentialPardonForm::execute(Bureaucrat const& executor) const {
    validForm("Status");
    validForm(executor.getGrade(), "execGrade");
	std::cout << GREEN << this->_target << " has been pardoned by Zaphod Beeblebrox." << RESET << std::endl;
}