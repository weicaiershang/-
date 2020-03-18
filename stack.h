#ifndef STACK_H
#define STACK_H

#include <iostream>
#include <vector>
#include <cstdlib>
#include <string>
#include <stdexcept>

using namespace std;


template <class T> class Stack
{

public:
    void push(T const& elem);        //入栈
    void pop();
    T top() const;
    bool isEmpty() const;

private:
    vector<T> m_elems;
};

#endif // STACK_H
