#include "stack.hpp"
#include <iostream>
int main()
{
    Stack stack(5);

    stack.push(5);
    stack.push(5757324);
    std::cout << stack.peek() << std::endl;
    stack.pop();
    std::cout << stack.peek() << std::endl;
    stack.push(35);
    std::cout << stack.peek() << std::endl;
    stack.push(57);
    std::cout << stack.peek() << std::endl;
    stack.push(7);
    std::cout << stack.peek() << std::endl;
    stack.push(37);
    std::cout << stack.peek() << std::endl;
    stack.pop();
    std::cout << stack.peek() << std::endl;
    stack.pop();
    std::cout << stack.peek() << std::endl;
    stack.pop();
    std::cout << stack.peek() << std::endl;
    stack.pop();
    std::cout << stack.peek() << std::endl;
    stack.pop();
    std::cout << stack.peek() << std::endl;
    stack.pop();
    std::cout << stack.peek() << std::endl;
}