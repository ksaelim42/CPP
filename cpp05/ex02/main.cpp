#include "Bureaucrat.hpp"
#include "ShrubberyCreationForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "PresidentialPardonForm.hpp"

void	testShrub()
{
	try
	{
		ShrubberyCreationForm	form("Nano");
		Bureaucrat	obj("Boji", 137);

		std::cout << form << std::endl;
		std::cout << obj << std::endl;
		obj.signForm(form);
		std::cout << form << std::endl;
		obj.executeForm(form);
	}
	catch (std::exception & e)
	{
		std::cout << RED << e.what() << RESET << std::endl;
	}
}

void	testRobot()
{
	try
	{
		RobotomyRequestForm	form("Nano");
		Bureaucrat	obj("Boji", 45);

		std::cout << form << std::endl;
		std::cout << obj << std::endl;
		obj.signForm(form);
		std::cout << form << std::endl;
		obj.executeForm(form);
	}
	catch (std::exception & e)
	{
		std::cout << RED << e.what() << RESET << std::endl;
	}
}

void	testPresiden()
{
	try
	{
		PresidentialPardonForm	form("Nano");
		Bureaucrat	obj("Boji", 5);

		std::cout << form << std::endl;
		std::cout << obj << std::endl;
		obj.signForm(form);
		std::cout << form << std::endl;
		obj.executeForm(form);
	}
	catch (std::exception & e)
	{
		std::cout << RED << e.what() << RESET << std::endl;
	}
}

int	main(void)
{
	// testShrub();
	// testRobot();
	testPresiden();
	return (0);
}