#include "Intern.hpp"

int	main(void)
{
	Intern	someRandomIntern;

	AForm*	rrf;
	rrf = someRandomIntern.makeForm("kingdom ocean", "Bender");

	rrf = someRandomIntern.makeForm("shrubbery creation", "Bender");
	std::cout << *rrf << std::endl;
	delete rrf;

	rrf = someRandomIntern.makeForm("robotomy request", "Bender");
	std::cout << *rrf << std::endl;
	delete rrf;

	rrf = someRandomIntern.makeForm("presidential pardon", "Bender");
	std::cout << *rrf << std::endl;
	Bureaucrat	obj("Oven", 2);
	obj.signForm(*rrf);
	obj.executeForm(*rrf);
	delete rrf;
	return (0);
}