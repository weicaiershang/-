#ifndef SHAPE_H
#define SHAPE_H
#include <iostream>

using namespace std;

class Shape
{
public:
    Shape(int a = 0, int b = 0);
    virtual ~Shape();
    int area();

protected:
    int m_width;
    int m_height;
};


class Rectangle : public Shape
{
public:
    Rectangle(int a = 0, int b = 0);
    int area();
};

class Triangle : public Shape
{
public:
    Triangle(int a = 0, int b = 0);
    int area();
};
#endif // SHAPE_H
