#include "Span.hpp"

Span::Span(unsigned int N) : _maxSize(N) {}

Span::Span(Span const& r) {*this = r;}

Span&	Span::operator=(Span const& r) {
	if (this != &r) {
		_maxSize = r._maxSize;
		_arr = r._arr;
	}
	return *this;
}

// ********************************************************** //
// --------------------- Member Functions ------------------- //
// ********************************************************** //

unsigned int	Span::size() const {return _arr.size();}

void	Span::addNumber(int num) {
	if (_arr.size() >= _maxSize)
		throw ArrFull();
	_arr.push_back(num);
}

static bool	allSameElements(std::vector<int> arr) {
	if (arr.empty())
        return true;
    return std::equal(arr.begin() + 1, arr.end(), arr.begin());
}

void	Span::validSpan() const
{
	if (_arr.empty())
		throw NoNumber();
	if (_arr.size() == 1)
		throw OnlyOne();
	if (allSameElements(_arr))
		throw NoSpan();
}

unsigned int	Span::shortestSpan() {
	unsigned int	num;
	unsigned int	shortNum = UINT_MAX;
	std::vector<int>	tmp(_arr);

    validSpan();
	std::sort(tmp.begin(), tmp.end());
	for (unsigned int i = 0; i <= tmp.size(); i++) {
		num = static_cast<unsigned int>(abs(static_cast<long>(tmp[i + 1]) - static_cast<long>(tmp[i])));
		if (num > 0 && num < shortNum)
			shortNum = num;
	}
	return (shortNum);
}

unsigned int	Span::longestSpan() {
    validSpan();
	long	min_num = static_cast<long>(*std::min_element(_arr.begin(), _arr.end()));
	long	max_num = static_cast<long>(*std::max_element(_arr.begin(), _arr.end()));
	return (static_cast<unsigned int>(abs(max_num - min_num)));
}
