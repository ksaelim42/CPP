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

        int getRawBits(void) const;
        void setRawBits(int const raw);
        float toFloat(void) const;
        int toInt(void) const;
};

std::ostream& operator<<(std::ostream& output, const Fixed& input);

#endif