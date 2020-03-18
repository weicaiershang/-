#include "shape.h"

Shape::Shape(int a, int b)
{
    m_width = a;
    m_height = b;
}

int Shape::area()
{
    cout << "Parent class area" << endl;
    return 0;
}

Shape::~Shape()
{

}

Rectangle::Rectangle(int a, int b)
    : Shape (a, b)
{

}

int Rectangle::area()
{
    cout << "Rectangle class area" << endl;
    return (m_width * m_height);
}

Triangle::Triangle(int a, int b)
    : Shape (a, b)
{

}

int Triangle::area()
{
    cout << "Triangle class area" << endl;
    return (m_width * m_height / 2);
}
