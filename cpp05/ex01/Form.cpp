#include "Form.hpp"

//*********************************************************************//
//----------------------- Constuctors & Destructors -------------------//
//*********************************************************************//

Form::Form(std::string name, int signGrade, int execGrade) : _name(name), _status(false), _signGrade(validGrade(signGrade, 0)), _execGrade(validGrade(execGrade, 0))
{
	std::cout << "Form<" << _name << ">: " << "has been Created !" << std::endl;
}

Form::Form(Form const &r) : _name(r._name), _status(r._status), _signGrade(r._signGrade), _execGrade(r._execGrade) {}

Form &Form::operator=(Form const &r)
{
	if (this != &r)
	{
		_status = r._status;
	}
	return (*this);
}

Form::~Form()
{
	std::cout << "Form<" << _name << ">: " << "has been Destroyed !" << std::endl;
}

//*********************************************************************//
//----------------------- Puclic main member functions ----------------//
//*********************************************************************//

std::string Form::getName() const {return _name;}

bool Form::getStatus() const {return _status;}

int Form::getSignGrade() const {return _signGrade;}

int Form::getExecGrade() const {return _execGrade;}

void Form::beSigned(Bureaucrat const &r)
{
	validGrade(r.getGrade(), 1);
	_status = true;
}

int Form::validGrade(int grade, int mode)
{

	if (mode == 0)
	{
		if (grade < 1)
			throw GradeTooHighException();
		if (grade > 150)
			throw GradeTooLowException();
	}
	else if (mode == 1)
	{
		if (grade > _signGrade)
			throw GradeTooLowException();
	}
	return grade;
}

const char *Form::GradeTooHighException::what() const throw()
{
	return ("Grade Too High");
}

const char *Form::GradeTooLowException::what() const throw()
{
	return ("Grade Too Low");
}

std::ostream &operator<<(std::ostream &os, Form const &r)
{
	os << "Name      : " << r.getName() << std::endl;
	os << "Status    : " << (r.getStatus() ? BGREEN "signed" RESET : BRED "unsigned" RESET) << std::endl;
	os << "signGrade : " << r.getSignGrade() << std::endl;
	os << "execGrade : " << r.getExecGrade() << std::endl;
	os << "--------------------------------" << std::endl;
	return os;
}
