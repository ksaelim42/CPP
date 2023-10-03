#ifndef FIXED_H
# define FIXED_H

#include <string>
#include <iostream>

class Fixed
{
    private:
        int _fixed_point_num;
        static const int _fractional_bits = 8;
    public:
        Fixed(void);
        Fixed(const Fixed &fixed);
        ~Fixed(void);
        Fixed & operator = (const Fixed &fixed);

        int getRawBits(void) const;
        void setRawBits(int const raw);
};

void print(std::string s);
void print_line(std::string s);
void print_line(std::string s1, std::string s2);
void print_line(void);

#endif