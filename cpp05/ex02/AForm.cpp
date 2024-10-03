#include "AForm.hpp"

//*********************************************************************//
//----------------------- Constuctors & Destructors -------------------//
//*********************************************************************//

AForm::AForm(std::string name, int signGrade, int execGrade) : _name(name), _status(false), _signGrade(validGrade(signGrade, 0)), _execGrade(validGrade(execGrade, 0))
{
	std::cout << "AForm<" << this->_name << ">: " << "has been Created !" << std::endl;
}

AForm::AForm(AForm const &r) : _name(r._name), _status(r._status), _signGrade(r._signGrade), _execGrade(r._execGrade) {}

AForm &AForm::operator=(AForm const &r)
{
	if (this != &r)
	{
		this->_status = r._status;
	}
	return (*this);
}

AForm::~AForm()
{
	std::cout << "AForm<" << this->_name << ">: " << "has been Destroyed" << std::endl;
}

//*********************************************************************//
//----------------------- Puclic main member functions ----------------//
//*********************************************************************//

std::string AForm::getName() const { return this->_name; }

bool AForm::getStatus() const { return this->_status; }

int AForm::getSignGrade() const { return this->_signGrade; }

int AForm::getExecGrade() const { return this->_execGrade; }

void AForm::beSigned(Bureaucrat const &r)
{

	validGrade(r.getGrade(), 1);
	this->_status = true;
}

int AForm::validGrade(int grade, int mode)
{

	if (mode == 0)
	{
		if (grade < 1)
			throw GradeTooHighException();
		else if (grade > 150)
			throw GradeTooLowException();
	}
	else if (mode == 1)
	{
		if (grade > this->_signGrade)
			throw GradeTooLowException();
	}
	return grade;
}

const char *AForm::GradeTooHighException::what() const throw()
{
	return ("Grade Too High");
}

const char *AForm::GradeTooLowException::what() const throw()
{
	return ("Grade Too Low");
}

std::ostream &operator<<(std::ostream &os, AForm const &r)
{
	os << "Name      : " << r.getName() << std::endl;
	os << "Status    : " << (r.getStatus() ? BGREEN "signed" RESET : BRED "unsigned" RESET) << std::endl;
	os << "signGrade : " << r.getSignGrade() << std::endl;
	os << "execGrade : " << r.getExecGrade() << std::endl;
	os << "--------------------------------" << std::endl;
	return os;
}
