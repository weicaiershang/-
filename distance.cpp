#include "distance.h"

Distance::Distance()
{
    m_feet = 0;
    m_inches = 0;
}

Distance::Distance(int f, int i)
{
    m_feet = f;
    m_inches = i;
}

Distance Distance::operator()(int a, int b, int c)
{
    Distance d;
    d.m_feet = a + c + 10;
    d.m_inches = b + c + 100;
    return d;
}

void Distance::displayDistance()
{
    cout << "F: " << m_feet << "  I: "<< m_inches << endl;
}
