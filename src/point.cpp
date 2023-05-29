#include "point.h"


void Point::setX(int x)
{
    m_x = x;
}

void Point::setY(int y)
{
    m_y = y;
}

Point::Point(int x, int y)
    :m_x(x), m_y(y)
{

}

Point::~Point()
{

}

bool Point::operator==(const Point p)
{
    if(this->m_x == p.m_x && this->m_y == p.m_y)
    {
        return true;
    }
    return false;
}

int Point::x() const
{
    return m_x;
}

int Point::y() const
{
    return m_y;
}
