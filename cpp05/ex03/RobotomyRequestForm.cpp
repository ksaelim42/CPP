#include "RobotomyRequestForm.hpp"

RobotomyRequestForm::RobotomyRequestForm(std::string target): AForm("RobotomyRequestForm", 72, 45), _target(target) {}

RobotomyRequestForm::RobotomyRequestForm(RobotomyRequestForm const& r): AForm(r), _target(r._target) {}

RobotomyRequestForm&	RobotomyRequestForm::operator=(RobotomyRequestForm const& r) {
	if (this != &r) {
		AForm::operator=(r);
		this->_target = r._target;
	}
	return (*this);
}

RobotomyRequestForm::~RobotomyRequestForm() {}

// ********************************************************** //
// --------------------- Member Functions ------------------- //
// ********************************************************** //

void	RobotomyRequestForm::execute(Bureaucrat const& executor) const {
    validForm("Status");
    validForm(executor.getGrade(), "execGrade");
	srand(time(NULL));
	if (rand() % 2 == 0)
		std::cout << GREEN << "Boom!, " << this->_target << " has been robotomized :)" << RESET << std::endl;
	else
		std::cout << RED << "robotomy failed :(" << RESET << std::endl;
}