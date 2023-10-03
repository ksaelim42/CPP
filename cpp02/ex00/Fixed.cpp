#include "Fixed.hpp"

int Fixed::getRawBits(void) const {

    print_line("getRawBits member function called");
    return (this->_fixed_point_num);
}

void Fixed::setRawBits(int const raw) {
    this->_fixed_point_num = raw;
}

Fixed::Fixed(void) {
    this->_fixed_point_num = 0;
    print_line("Default constructor called");
}

Fixed::Fixed(const Fixed &fixed) {
    print_line("Copy constructor called");
    // setRawBits(fixed.getRawBits());
    *this = fixed;
}

Fixed& Fixed::operator=(const Fixed &fixed) {
    print_line("Copy assignment operator called");
    if (this != &fixed) {
        this->_fixed_point_num = fixed.getRawBits();
    }
    return *this;
}

Fixed::~Fixed(void) {
    print_line("Destructor called");
}

void print(std::string s) {
	std::cout << s;
}

void print_line(std::string s) {
	std::cout << s << std::endl;
}

void print_line(std::string s1, std::string s2) {
	std::cout << s1 << s2 << std::endl;
}

void print_line(void) {
	std::cout << std::endl;
}
