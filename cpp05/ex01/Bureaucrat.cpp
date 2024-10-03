#include "Bureaucrat.hpp"

//*********************************************************************//
//----------------------- Constuctors & Destructors -------------------//
//*********************************************************************//

Bureaucrat::Bureaucrat(std::string name, int grade) : _name(name), _grade(validGrade(grade)) {
	std::cout << "Bureaucrat<" << this->_name << ">: " << "has been Created !" << std::endl;
}

Bureaucrat::Bureaucrat(Bureaucrat const& r): _name(r.getName()), _grade(r.getGrade()) {}

Bureaucrat&	Bureaucrat::operator=(Bureaucrat const& r) {
	if (this != &r)
	{
		this->_grade = r.getGrade();
	}
	return (*this);
}

Bureaucrat::~Bureaucrat() {
	std::cout << "Bureaucrat<" << this->_name << ">: " << "has been Destroyed" << std::endl;
}


//*********************************************************************//
//----------------------- Puclic main member functions ----------------//
//*********************************************************************//

std::string		Bureaucrat::getName() const {return this->_name;}

int		Bureaucrat::getGrade() const{return this->_grade;}


void	Bureaucrat::increaseGrade() {
	validGrade(--this->_grade);
}

void	Bureaucrat::decreaseGrade() {
	validGrade(++this->_grade);
}

int		Bureaucrat::validGrade(int grade) {
	if (grade < 1)
		throw GradeTooHighException();
	else if (grade > 150)
		throw GradeTooLowException();
	return grade;
}

const char*		Bureaucrat::GradeTooHighException::what() const throw() {
	return ("Grade Too High");
}

const char*		Bureaucrat::GradeTooLowException::what() const throw() {
	return ("Grade Too Low");
}

void	Bureaucrat::signForm(Form & r) {
	try
	{
		if (!r.getStatus()) {
			r.beSigned(*this);
			std::cout << GREEN << this->_name << " signed " << r.getName() << RESET << std::endl;
		}
		else
			std::cout << GREEN << "Form[" << r.getName() << "] has already been signed." << RESET << std::endl;

	}
	catch(const std::exception& e)
	{
		std::cerr << RED << this->_name << " couldn't sign " << r.getName();
		std::cerr << " because " << e.what() << RESET << std::endl;
	}
	
}

std::ostream&	operator<<(std::ostream & os, Bureaucrat const& r) {
	os << "Name : " << r.getName() << std::endl;
	os << "Grade: " << r.getGrade() << std::endl;
	os << "-------------------------" << std::endl;
	return os;
}