#ifndef POINT_H
# define POINT_H

#include "Fixed.hpp"

class Point
{
    private:
        Fixed const _x;
        Fixed const _y;
    public:
        Point(void);
        Point(const Point& point);
        Point(const float n1, const float n2);
        ~Point();

        Point &	operator=(Point const & point);
};

#endif