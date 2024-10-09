#include <vector>
#include <stdexcept>
#include <algorithm>
#include <iostream>
#include <climits>

#ifndef SPAN_HPP
#define SPAN_HPP

class Span {
	private:
		std::vector<int> _arr;
		unsigned int _maxSize;
		
		Span(){};

	public:
		Span(unsigned int N);
		Span(Span const& r);
		Span & operator=(Span const& r);
		~Span(){};

		void			validSpan() const;
		unsigned int	size() const;
		void			addNumber(int num);
		unsigned int	shortestSpan();
		unsigned int	longestSpan();

		class ArrFull : public std::exception {
			const char*	what() const throw() {return "already full elements stored :(";}
		};

		class NoNumber : public std::exception {
			const char*	what() const throw() {return "no numbers stored :(";}
		};

		class OnlyOne : public std::exception {
			const char*	what() const throw() {return "have only one number :(";}
		};

		class NoSpan : public std::exception {
			const char*	what() const throw() {return "No span can be found";}
		};

};

#endif