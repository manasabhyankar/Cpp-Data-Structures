#include "stack.hpp"
#include <vector>
#include <iostream>

Stack::Stack()
{}

Stack::Stack(int size)
{
    data = new int[size];
    data_size = size;
    top = -1;
}

Stack::~Stack()
{
    delete[] data;
}

int Stack::get_size()
{
    return data_size;
}

int Stack::pop()
{
    if(is_empty())
    {
        std::cout << "Stack is empty." << std::endl;
    }
    else
    {
        return data[--top];
    }
}

void Stack::push(int element)
{
    if(is_full())
    {
        std::cout << "Stack is full." << std::endl;
    }
    else
    {
        data[++top] = element;
    }
        
}
int Stack::peek()
{
    if(is_empty())
    {
        std::cout << "Stack is empty." << std::endl;
        return -1;
    }
        
    else
        return data[top];
}

bool Stack::is_empty()
{
    return top == -1;
}
bool Stack::is_full()
{   
    return top == data_size-1;
}