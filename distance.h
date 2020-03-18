#ifndef DISTANCE_H
#define DISTANCE_H

#include <iostream>
using namespace std;

class Distance
{
public:
    Distance();
    Distance(int f, int i);
    Distance operator()(int a, int b, int c);
    void displayDistance();
private:
    int m_feet;
    int m_inches;
};


#endif // DISTANCE_H
