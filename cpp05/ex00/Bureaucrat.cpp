#include "Bureaucrat.hpp"

//*********************************************************************//
//----------------------- Constuctors & Destructors -------------------//
//*********************************************************************//

Bureaucrat::Bureaucrat(std::string name, int grade) : _name(name), _grade(validGrade(grade))
{
	std::cout << "Bureaucrat<" << _name << ">: " << "has been Created !" << std::endl;
}

Bureaucrat::Bureaucrat(Bureaucrat const &r) : _name(r._name), _grade(r._grade) {}

Bureaucrat &Bureaucrat::operator=(Bureaucrat const &r)
{
	if (this != &r)
	{
		_grade = r._grade;
	}
	return (*this);
}

Bureaucrat::~Bureaucrat()
{
	std::cout << "Bureaucrat<" << _name << ">: " << "has been Destroyed !" << std::endl;
}

//*********************************************************************//
//----------------------- Puclic main member functions ----------------//
//*********************************************************************//

std::string Bureaucrat::getName() const { return _name; }

int Bureaucrat::getGrade() const { return _grade; }

void Bureaucrat::increaseGrade()
{
	validGrade(--_grade);
}

void Bureaucrat::decreaseGrade()
{
	validGrade(++_grade);
}

int Bureaucrat::validGrade(int grade)
{
	if (grade < 1)
		throw GradeTooHighException();
	else if (grade > 150)
		throw GradeTooLowException();
	return grade;
}

const char *Bureaucrat::GradeTooHighException::what() const throw()
{
	return ("Grade Too High");
}

const char *Bureaucrat::GradeTooLowException::what() const throw()
{
	return ("Grade Too Low");
}

std::ostream &operator<<(std::ostream &os, Bureaucrat const &r)
{
	os << r.getName() << ", bureaucrat grade " << r.getGrade() << std::endl;
	os << "-------------------------" << std::endl;
	return os;
}