#include "ShrubberyCreationForm.hpp"

ShrubberyCreationForm::ShrubberyCreationForm(std::string target): AForm("ShrubberyCreationForm", 145, 137), _target(target) {}

ShrubberyCreationForm::ShrubberyCreationForm(ShrubberyCreationForm const& r): AForm(r), _target(r._target) {}

ShrubberyCreationForm&	ShrubberyCreationForm::operator=(ShrubberyCreationForm const& r)
{
	if (this != &r)
	{
		AForm::operator=(r);
		_target = r._target;
	}
	return (*this);
}

ShrubberyCreationForm::~ShrubberyCreationForm() {}


void    ShrubberyCreationForm::execute(Bureaucrat const & executor) const {

	std::ofstream	outfile((_target + "_shrubbery").c_str());

	validForm("Status");
	validForm(executor.getGrade(), "execGrade");
	if (!outfile.is_open())
		throw CanNotOpenFileException();
	outfile << ASCII_TREES;
	outfile.close();
}

const char*		ShrubberyCreationForm::CanNotOpenFileException::what() const throw()
{
	return ("Can't open file :(");
}