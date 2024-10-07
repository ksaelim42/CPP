#include "ScalarConverter.hpp"

//*********************************************************************//
//----------------------- Constuctors & Destructors -------------------//
//*********************************************************************//

ScalarConverter::ScalarConverter() {}

ScalarConverter::ScalarConverter(ScalarConverter const& r) {
	(void)r;
}

ScalarConverter&	ScalarConverter::operator=(ScalarConverter const& r) {
	(void)r;
	return (*this);
}

ScalarConverter::~ScalarConverter() {}


static std::string      convertFloat(std::string str);
static std::string      convertDouble(std::string str);
static std::string      convertInt(std::string str);
static std::string		convertChar(std::string str);
static std::string      toLower(std::string str);

void	ScalarConverter::convert(std::string str) {

	str = toLower(str);
	std::cout << "char: " << convertChar(str) << std::endl;
	std::cout << "int: " << convertInt(str) << std::endl;
	std::cout << "float: " << convertFloat(str) << std::endl;
	std::cout << "double: " << convertDouble(str) << std::endl;
}

static std::string toLower(std::string str) {

	for (size_t i=0; i < str.length(); i++)
		str[i] = tolower(str[i]);
	return str;
}

static bool     isTxtSci(std::string & str) {

	std::string		sciText[] = {"inf", "-inf", "+inf", "inff", "-inff", "+inff", "nan", "nanf"};
	int             size = sizeof(sciText) / sizeof(sciText[0]);

	for (int i = 0; i < size; i++) {
		if (str == sciText[i]) {
			if (str[0] == 'i')
				str.insert(0, 1, '+');
			if (str.substr(str.length()-2) == "ff" || str == "nanf")
				str.erase(str.size() - 1);
			return true;
		}
	}
	return false;
}

static std::string		convertChar(std::string str) {
	std::istringstream input(str);
	std::ostringstream output;
	long double d = 0;

	if (input >> d) {
		if(d > static_cast<int>(CHAR_MAX) || d < static_cast<int>(CHAR_MIN))
			output << "impossible";
		else if(isprint(static_cast<unsigned char>(d)))
			output << "'" << static_cast<char>(d) << "'";   
		else
			output << "Non displayable";
	}
	else {
		if (input.eof())
			output << "Non displayable";
		else
			output << "impossible";
	}
	return (output.str());
}

static std::string      convertInt(std::string str) {
	std::istringstream input(str);
	std::ostringstream output;
	long double d = 0;

	if(input >> d) {

		if( d > static_cast<int>(INT_MAX) || d < static_cast<int>(INT_MIN))
			output << "impossible";
		else
			output << static_cast<int>(d);   
	}
	else {
		if (input.eof())
			output << static_cast<int>(d);
		else   
			output << "impossible";
	}

	return (output.str());
}

static std::string      convertFloat(std::string str)
{
	std::istringstream input(str);
	std::ostringstream output;
	long double d = 0;


	if(isTxtSci(str)) {
		output << str << "f";
		return output.str();
	}
	else {
		if (input >> d) {
			if (d > (FLT_MAX) || d < -(FLT_MAX))
			{
				output << "impossible";
				return output.str();
			}
			else
				output << static_cast<float>(d);   
		}
		else {
			if (input.eof())
				output << static_cast<float>(d);
			else {
				output << "impossible";
				return output.str();
			}
		} 
	}
	
	if(output.str().find('.') != std::string::npos)
		output << "f";
	else
		output << ".0f";

	return (output.str());
}

static std::string      convertDouble(std::string str)
{
	std::istringstream input(str);
	std::ostringstream output;
	long double d = 0;
	
	if(isTxtSci(str)) {
		output << str;
		return output.str();
	}
	else {
		if (input >> d) {
			if (d > (DBL_MAX) || d < -(DBL_MAX)) {
				output << "impossible";
				return output.str();
			}
			else
				output << static_cast<double>(d);   
		}
		else {
			if (input.eof())
				output << static_cast<double>(d);
			else {
				output << "impossible";
				return output.str();
			}
		} 
	}

	if(output.str().find('.') == std::string::npos)
		output << ".0";

	return (output.str());
}
