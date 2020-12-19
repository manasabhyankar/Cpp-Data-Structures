#include "stack.hpp"
#include <iostream>
int main()
{
    Stack stack(5);
    for (size_t i = 0; i < stack.get_size()+1; i++)
    {
        stack.push(i);
    }
    std::cout << std::endl;
    for (size_t i = 0; i < stack.get_size(); i++)
    {
        std::cout << stack.pop() << std::endl;
    }
}