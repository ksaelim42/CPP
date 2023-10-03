#ifndef FIXED_H
# define FIXED_H

#include <cmath>
#include <iostream>

class Fixed
{
    private:
        int _fixed_point_num;
        static const int _fractional_bits = 8;
    public:
        Fixed(void);
        Fixed(const int num);
        Fixed(const float num);
        Fixed(const Fixed &fixed);
        ~Fixed(void);
        Fixed & operator = (const Fixed &fixed);

        int     getRawBits(void) const;
        void    setRawBits(int const raw);
        float   toFloat( void ) const;
        int     toInt( void ) const;

        bool operator>(const Fixed &fixed);
        bool operator>=(const Fixed &fixed);
        bool operator<(const Fixed &fixed);
        bool operator<=(const Fixed &fixed);
        bool operator==(const Fixed &fixed);
        bool operator!=(const Fixed &fixed);

        Fixed operator+(const Fixed &fixed);
        Fixed operator-(const Fixed &fixed);
        Fixed operator*(const Fixed &fixed);
        Fixed operator/(const Fixed &fixed);

        Fixed&  operator++(void);
        Fixed   operator++(int);
        Fixed&  operator--(void);
        Fixed   operator--(int);

        static Fixed&          max(Fixed& a, Fixed& b);
        static const Fixed&    max(const Fixed& a, const Fixed& b);
        static Fixed&          min(Fixed& a, Fixed& b);
        static const Fixed&    min(const Fixed& a, const Fixed& b);
};

std::ostream& operator<<(std::ostream& output, const Fixed &input);

#endif