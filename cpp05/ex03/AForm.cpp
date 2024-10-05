#include "AForm.hpp"

//*********************************************************************//
//----------------------- Constuctors & Destructors -------------------//
//*********************************************************************//

AForm::AForm(std::string name, int signGrade, int execGrade) : _name(name), _status(false), _signGrade(validForm(signGrade, "validGrade")), _execGrade(validForm(execGrade, "validGrade")) {
	std::cout << "AForm<" << _name << ">: " << "has been Created !" << std::endl;
}

AForm::AForm(AForm const &r) : _name(r._name), _status(r._status), _signGrade(r._signGrade), _execGrade(r._execGrade) {}

AForm &AForm::operator=(AForm const &r) {
	if (this != &r) {
		_status = r._status;
	}
	return (*this);
}

AForm::~AForm() {
	std::cout << "AForm<" << _name << ">: " << "has been Destroyed !" << std::endl;
}

//*********************************************************************//
//----------------------- Puclic main member functions ----------------//
//*********************************************************************//

std::string AForm::getName() const {return _name;}

bool AForm::getStatus() const {return _status;}

int AForm::getSignGrade() const {return _signGrade;}

int AForm::getExecGrade() const {return _execGrade;}

void AForm::beSigned(Bureaucrat const &r) {

	validForm(r.getGrade(), "signGrade");
	_status = true;
}


void	AForm::validForm(std::string mode) const {
	if (mode == "Status" && !_status)
		throw FormNotSignException();
}

int		AForm::validForm(int grade, std::string mode) const {

	if (mode == "validGrade") {
		if (grade < 1)
			throw GradeTooHighException();
		else if (grade > 150)
			throw GradeTooLowException();
	}
	else if (mode == "signGrade") {
		if (grade > _signGrade)
			throw GradeTooLowException();
	}
	else if (mode == "execGrade") {
		if (grade > _execGrade)
			throw GradeTooLowException();
	}

	return grade;
}

const char *AForm::GradeTooHighException::what() const throw() {
	return "Grade Too High";
}

const char *AForm::GradeTooLowException::what() const throw() {
	return "Grade Too Low";
}

const char *AForm::FormNotSignException::what() const throw() {
	return "Form have not been signed";
}

std::ostream &operator<<(std::ostream &os, AForm const &r) {
	os << "Name      : " << r.getName() << std::endl;
	os << "Status    : " << (r.getStatus() ? BGREEN "signed" RESET : BRED "unsigned" RESET) << std::endl;
	os << "signGrade : " << r.getSignGrade() << std::endl;
	os << "execGrade : " << r.getExecGrade() << std::endl;
	os << "--------------------------------" << std::endl;
	return os;
}
