#include "Fixed.hpp"

int Fixed::getRawBits(void) const {

    std::cout << "getRawBits member function called" << std::endl;
    return (this->_fixed_point_num);
}

void Fixed::setRawBits(int const raw) {
    this->_fixed_point_num = raw;
}

Fixed::Fixed(void) {
    this->_fixed_point_num = 0;
    std::cout << "Default constructor called" << std::endl;
}

Fixed::Fixed(const int num) {
    this->_fixed_point_num = (num << this->_fractional_bits);
    std::cout << "Int constructor called" << std::endl;
}

Fixed::Fixed(const float num) {
    this->_fixed_point_num = (roundf(num * (1 << this->_fractional_bits)));
    std::cout << "Float constructor called" << std::endl;
}

Fixed::Fixed(const Fixed &fixed) {
    std::cout << "Copy constructor called" << std::endl;
    // setRawBits(fixed.getRawBits());
    *this = fixed;
}

std::ostream& operator<<(std::ostream& output, const Fixed& input) {
    output << input.toFloat();
    return output;
}

Fixed& Fixed::operator=(const Fixed &fixed) {
    std::cout << "Copy assignment operator called" << std::endl;
    if (this != &fixed) {
        // this->_fixed_point_num = fixed.getRawBits();
        this->_fixed_point_num = fixed._fixed_point_num;
    }
    return *this;
}

Fixed::~Fixed(void) {
    std::cout << "Destructor called" << std::endl;
}

float Fixed::toFloat(void) const {
    return static_cast<float>(this->_fixed_point_num) / (1 << this->_fractional_bits);
}

int Fixed::toInt(void) const {
    return (this->_fixed_point_num >> this->_fractional_bits);
}