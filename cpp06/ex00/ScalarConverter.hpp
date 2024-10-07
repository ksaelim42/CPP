#ifndef SCALARCONVERTER_HPP
# define SCALARCONVERTER_HPP

#include <iostream>
#include <string>
#include <cstdlib>
#include <cctype>
#include <cstring>
#include <climits>
#include <sstream>
#include <cfloat>

# define BLACK	"\e[0;30m"
# define RED	"\e[0;31m"
# define GREEN	"\e[0;32m"
# define YELLOW	"\e[0;33m"
# define BLUE	"\e[0;34m"
# define PURPLE	"\e[0;35m"
# define CYAN	"\e[0;36m"
# define WHITE	"\e[0;37m"
# define RESET	"\e[0m"

class ScalarConverter
{
	public:
		ScalarConverter();
		ScalarConverter(ScalarConverter const& r);
		ScalarConverter&	operator=(ScalarConverter const& r);
		~ScalarConverter();

		static void	convert(std::string str);
};

#endif