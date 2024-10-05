#ifndef FORM_HPP
# define FORM_HPP

# include <iostream>
# include <string>
# include <exception>
# include "Bureaucrat.hpp"

# define BLACK	"\e[0;30m"
# define BRED	"\x1b[38;5;88m"
# define BGREEN	"\x1b[38;5;22m"
# define RED	"\e[0;31m"
# define GREEN	"\e[0;32m"
# define YELLOW	"\e[0;33m"
# define BLUE	"\e[0;34m"
# define PURPLE	"\e[0;35m"
# define CYAN	"\e[0;36m"
# define WHITE	"\e[0;37m"
# define RESET	"\e[0m"

class Bureaucrat;

class Form
{
	private:
		std::string const	_name;
		bool				_status;
		int const			_signGrade;
		int const			_execGrade;

	public:
		Form(std::string name, int signGrade, int execGrade);
		Form(Form const& r);
		Form&	operator=(Form const& r);
		~Form();

		std::string	getName() const;
		bool		getStatus() const;
		int			getSignGrade() const;
		int			getExecGrade() const;

		void		beSigned(Bureaucrat const& r);
		int			validGrade(int grade, int mode);
		

		class GradeTooHighException : public std::exception {
			public:
				const char * what() const throw();
		};
		
		class GradeTooLowException : public std::exception {
			public:
				const char * what() const throw();
		};
};

std::ostream& operator<<(std::ostream &os, Form const& r);

#endif