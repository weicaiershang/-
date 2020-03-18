#ifndef BOX_H
#define BOX_H

class Box
{
public:
    Box();
    double getVolume();
    void setLength(double length);
    void setWidth(double width);
    void setHeight(double height);

    Box operator+(const Box &b);
private:
    double m_length;
    double m_width;
    double m_height;
};


#endif // BOX_H
