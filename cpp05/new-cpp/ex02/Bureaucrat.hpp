#ifndef BUREAUCRAT_HPP
#define BUREAUCRAT_HPP

#include <iostream>
#include <string>
#include <exception>
#include "AForm.hpp"

#define BLACK "\e[0;30m"
#define RED "\e[0;31m"
#define GREEN "\e[0;32m"
#define YELLOW "\e[0;33m"
#define BLUE "\e[0;34m"
#define PURPLE "\e[0;35m"
#define CYAN "\e[0;36m"
#define WHITE "\e[0;37m"
#define RESET "\e[0m"

class AForm;

class Bureaucrat
{
private:
	std::string const _name;
	int _grade;

public:
	Bureaucrat(std::string name, int grade);
	Bureaucrat(Bureaucrat const &r);
	Bureaucrat &operator=(Bureaucrat const &r);
	~Bureaucrat();

	std::string getName() const;
	int getGrade() const;
	void increaseGrade();
	void decreaseGrade();
	void showInfo();
	int validGrade(int grade);
	void signAForm(AForm &r);

	class GradeTooHighException : public std::exception
	{
	public:
		const char *what() const throw();
	};

	class GradeTooLowException : public std::exception
	{
	public:
		const char *what() const throw();
	};
};

std::ostream &operator<<(std::ostream &os, Bureaucrat const &r);

#endif