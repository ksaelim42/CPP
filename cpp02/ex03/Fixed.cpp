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
    // std::cout << "Default constructor called" << std::endl;
}

Fixed::Fixed(const int num) {
    this->_fixed_point_num = num << this->_fractional_bits;
    // std::cout << "Int constructor called" << std::endl;
}

Fixed::Fixed(const float num) {
    this->_fixed_point_num = roundf(num * (1 << this->_fractional_bits));
    // std::cout << "Float constructor called" << std::endl;
}

Fixed::Fixed(const Fixed &fixed) {
    // std::cout << "Copy constructor called" << std::endl;
    // setRawBits(fixed.getRawBits());
    *this = fixed;
}

Fixed& Fixed::operator=(const Fixed &fixed) {
    // std::cout << "Copy assignment operator called" << std::endl;
    if (this != &fixed) {
        // this->_fixed_point_num = fixed.getRawBits();
        this->_fixed_point_num = fixed._fixed_point_num;
    }
    return *this;
}

std::ostream& operator<<(std::ostream& output, const Fixed &input) {
    output << input.toFloat();
    return output;
}

float Fixed::toFloat(void) const {
    return static_cast<float>(this->_fixed_point_num) / (1 << this->_fractional_bits);
}

int Fixed::toInt(void) const {
    return this->_fixed_point_num >> this->_fractional_bits;
}

Fixed::~Fixed(void) {
    // std::cout << "Destructor called" << std::endl;
}

// ---------- 6 comparison operators ------------ //

bool Fixed::operator>(const Fixed &fixed) {
    return this->_fixed_point_num > fixed._fixed_point_num;
}

bool Fixed::operator>=(const Fixed &fixed) {
    return this->_fixed_point_num >= fixed._fixed_point_num;
}

bool Fixed::operator<(const Fixed &fixed) {
    return this->_fixed_point_num < fixed._fixed_point_num;
}

bool Fixed::operator<=(const Fixed &fixed) {
    return this->_fixed_point_num <= fixed._fixed_point_num;
}

bool Fixed::operator==(const Fixed &fixed) {
    return this->_fixed_point_num == fixed._fixed_point_num;
}

bool Fixed::operator!=(const Fixed &fixed) {
    return this->_fixed_point_num != fixed._fixed_point_num;
}


// ---------- 4 arithmetic operators ------------ //

Fixed Fixed::operator+(const Fixed &fixed) {
    return Fixed(this->toFloat() + fixed.toFloat());
}
Fixed Fixed::operator-(const Fixed &fixed) {
    return Fixed(this->toFloat() - fixed.toFloat());
}
Fixed Fixed::operator*(const Fixed &fixed) {
    return Fixed(this->toFloat() * fixed.toFloat());
}
Fixed Fixed::operator/(const Fixed &fixed) {
    return Fixed(this->toFloat() / fixed.toFloat());
}


// ---------- 4 increment/decrement ------------ //

Fixed& Fixed::operator++(void) {
    ++this->_fixed_point_num;
    return *this;
}

Fixed Fixed::operator++(int) {
    Fixed tmp(*this);
    tmp._fixed_point_num = this->_fixed_point_num++;
    return tmp;
}

Fixed& Fixed::operator--(void) {
    --this->_fixed_point_num;
    return *this;
}

Fixed Fixed::operator--(int) {
    Fixed tmp(*this);
    tmp._fixed_point_num = this->_fixed_point_num--;
    return tmp;
}


// ---------- min/max member functions ------------ //

Fixed& Fixed::max(Fixed& a, Fixed& b) {
    if (a._fixed_point_num > b._fixed_point_num)
        return a;
    return b;
}

const Fixed& Fixed::max(const Fixed& a, const Fixed& b) {
    if (a._fixed_point_num > b._fixed_point_num)
        return a;
    return b;
}

Fixed& Fixed::min(Fixed& a, Fixed& b) {
    if (a._fixed_point_num < b._fixed_point_num)
        return a;
    return b;
}

const Fixed& Fixed::min(const Fixed& a, const Fixed& b) {
    if (a._fixed_point_num < b._fixed_point_num)
        return a;
    return b;
}
