#ifndef RPN_HPP
# define RPN_HPP

#include <iostream>
#include <cstdlib>
#include <sstream>
#include <stack>
#include <stdexcept>

class RPN
{
	private:
		std::stack<int> _stack;;

	public:
		RPN() {};
		RPN(RPN const& r);
		RPN&  operator=(RPN const& r);
		~RPN() {};

		int calculate(const std::string& str);
};



#endif