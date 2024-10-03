#include "Bureaucrat.hpp"
#include "AForm.hpp"

struct Param
{
	std::string a;
	int b;
	int c;
};

void testAForm()
{
	Param param[] = {
		{"Warrior", 0, 20},
		{"Archer", 20, 0},
		{"Mage", 151, 20},
		{"Acolyte", 20, 151},
		{"Merchant", 0, 0},
		{"Thief", 151, 151}};
	for (int i = 0; i < 6; i++)
	{
		try
		{
			AForm form(param[i].a, param[i].b, param[i].c);
		}
		catch (std::exception &e)
		{
			std::cout << RED << e.what() << RESET << std::endl;
		}
	}
}

int main(void)
{
	// testAForm();
	std::cout << std::endl;
	try
	{
		AForm form("Warrior", 30, 20);
		Bureaucrat obj1("Me", 31);
		Bureaucrat obj2("You", 30);

		std::cout << ">> form <<\n"
				  << form << std::endl;
		std::cout << ">> obj1 <<\n"
				  << obj1 << std::endl;
		std::cout << ">> obj2 <<\n"
				  << obj2 << std::endl;

		obj1.signAForm(form);
		std::cout << form << std::endl;
		obj2.signAForm(form);

		Bureaucrat obj3("Who", 28);
		std::cout << ">> obj3 <<\n"
				  << obj3 << std::endl;
		obj3.signAForm(form);
	}
	catch (std::exception &e)
	{
		std::cout << RED << e.what() << RESET << std::endl;
	}
	return 0;
}