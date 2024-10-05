#ifndef SCALARCONVERTER_HPP
# define SCALARCONVERTER_HPP

#include <iostream>
#include <string>
#include <cstdlib>
#include <cctype>
#include <cstring>
#include <limits>
#include <sstream>

# define BLACK	"\e[0;30m"
# define RED	"\e[0;31m"
# define GREEN	"\e[0;32m"
# define YELLOW	"\e[0;33m"
# define BLUE	"\e[0;34m"
# define PURPLE	"\e[0;35m"
# define CYAN	"\e[0;36m"
# define WHITE	"\e[0;37m"
# define RESET	"\e[0m"

# define MAX_INT	2147483647
# define MIM_INT	-2147483648
# define MAX_FLOAT	3.402823466E+38
# define MIM_FLOAT	-3.402823466E+38 // Actually call lowest float
# define MAX_DOUBLE	1.7976931348623158E+308
# define MIN_DOUBLE	-1.7976931348623158E+308 // Actually call lowest double


enum e_type
{
	e_float, e_double
};

class ScalarConverter
{
	private:
		std::string		error_log[3];
	public:
		ScalarConverter();
		ScalarConverter(ScalarConverter const& r);
		ScalarConverter&	operator=(ScalarConverter const& r);
		~ScalarConverter();

		static void	convert(std::string str);
};

#endif