#include <iostream>

class Bureaucrat

int main(int ac, char **av)
{
	private:
		const std::string   _name;
		int					_grade;
		static const int	_HIGHEST = 1;
		static const int	_LOWEST = 150;
	public:
		Bureaucrat();
		Bureaucrat(std::string);
		Bureaucrat(const Bureaucrat &ref);
		Bureaucrat& operator=(const Bureaucrat &ref);
		~Bureaucrat();

		std::string	getName();
		int			getGrade();
		void		addGrade(void);
		void		downGrade(void);
}

