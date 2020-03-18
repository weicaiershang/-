#include "box.h"

Box::Box()
{

}

double Box::getVolume()
{
    return m_height * m_width * m_length;
}

void Box::setLength(double length)
{
    m_length = length;
}

void Box::setWidth(double width)
{
    m_width = width;
}

void Box::setHeight(double height)
{
    m_height = height;
}

Box Box::operator+(const Box &b)
{
    Box box;
    box.m_width = this->m_width + b.m_width;
    box.m_height = this->m_height + b.m_height;
    box.m_length = this->m_length + b.m_length;
    return box;
}


