#ifndef AFORM_HPP
#define AFORM_HPP

#include <iostream>
#include <string>
#include <exception>
#include "Bureaucrat.hpp"

#define BLACK "\e[0;30m"
#define BRED "\x1b[38;5;88m"
#define BGREEN "\x1b[38;5;22m"
#define RED "\e[0;31m"
#define GREEN "\e[0;32m"
#define YELLOW "\e[0;33m"
#define BLUE "\e[0;34m"
#define PURPLE "\e[0;35m"
#define CYAN "\e[0;36m"
#define WHITE "\e[0;37m"
#define RESET "\e[0m"

class Bureaucrat;

class AForm
{
private:
	std::string const _name;
	bool _status;
	int const _signGrade;
	int const _execGrade;

public:
	AForm(std::string name, int signGrade, int execGrade);
	AForm(AForm const &r);
	AForm &operator=(AForm const &r);
	virtual ~AForm();

	std::string getName() const;
	bool getStatus() const;
	int getSignGrade() const;
	int getExecGrade() const;

	void beSigned(Bureaucrat const &r);
	int validForm(int grade, std::string mode) const;
	void validForm(std::string mode) const;

	virtual void	execute(Bureaucrat const& executor) const = 0;

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

	class FormNotSignException : public std::exception
	{
		public:
			const char *what() const throw();
	};
};

std::ostream &operator<<(std::ostream &os, AForm const &r);

#endif