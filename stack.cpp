#include "stack.h"

template<class T>
void Stack<T>::push(const T &elem)
{
    m_elems.push_back(elem);
}

template<class T>
void Stack<T>::pop()
{
    if(m_elems.empty())
    {
        throw out_of_range("Stack<>::pop():empty stack");
    }
    m_elems.pop_back();
}

template<class T>
T Stack<T>::top() const
{
    if(m_elems.empty())
    {
        throw out_of_range("Stack<>::top(): empty stack");
    }
    return m_elems.back();
}
