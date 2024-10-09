#include "RPN.hpp"

RPN&  RPN::operator=(RPN const& r)
{
	if (this != &r) {
		this->_stack = r._stack;
	}
	return (*this);
}

RPN::RPN(RPN const& r) : _stack(r._stack) {}

static bool isOper(const char c) {
        return (c == '+' || c == '-' || c == '*' || c == '/');
}

int		RPN::calculate(const std::string& str) {

	std::stringstream ss(str);
	std::string token;
	int a, b;

	while (ss >> token) {

		std::cout << token[0] << std::endl;
		if (isdigit(token[0]) ) {
			if (token.length() != 1)
				throw std::runtime_error("Error: Numbers must less than 10 :(");
			_stack.push(atoi(token.c_str()));

		} else if (token.length() == 1 && isOper(token[0])) {

			if (_stack.size() < 2)
				throw std::runtime_error("Error: Not enough operands :(");

			a = _stack.top(); _stack.pop();
			b = _stack.top(); _stack.pop();

			switch (token[0]) {
				case '+': _stack.push(b + a); break;
				case '-': _stack.push(b - a); break;
				case '*': _stack.push(b * a); break;
				case '/':
					if (a == 0) 
						throw std::runtime_error("Error: Division by zero :(");
					_stack.push(b / a); break;
			}
		} else
			throw std::runtime_error("Error: Invalid token :(");
	}

	if (_stack.size() != 1)
		throw std::runtime_error("Error: Invalid RPN expression :(");

	return _stack.top();

}