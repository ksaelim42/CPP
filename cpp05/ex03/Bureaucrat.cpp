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
	std::cout << "Bureaucrat<" << _name << ">: " << "has been Destroyed" << std::endl;
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

void Bureaucrat::signForm(AForm &r)
{
	try
	{
		if (!r.getStatus())
		{
			r.beSigned(*this);
			std::cout << GREEN << _name << " signed " << r.getName() << RESET << std::endl;
		}
		else
			std::cout << GREEN << "AForm[" << r.getName() << "] has already been signed." << RESET << std::endl;
	}
	catch (const std::exception &e)
	{
		std::cerr << RED << _name << " couldn't sign " << r.getName();
		std::cerr << " because " << e.what() << RESET << std::endl;
	}
}

void	Bureaucrat::executeForm(AForm const& r)
{
	try
	{
		r.execute(*this);
		std::cout << GREEN << this->_name << " executed " << r.getName() << RESET << std::endl;
	}
	catch(const std::exception& e)
	{
		std::cerr << RED << this->_name << " couldn't execute " << r.getName();
		std::cerr << " because " << e.what() << RESET << std::endl;
	}
	
}

std::ostream &operator<<(std::ostream &os, Bureaucrat const &r)
{
	os << "Name : " << r.getName() << std::endl;
	os << "Grade: " << r.getGrade() << std::endl;
	os << "-------------------------" << std::endl;
	return os;
}