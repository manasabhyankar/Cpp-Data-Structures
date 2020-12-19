#include <vector>
class Stack
{
    public:
        Stack();
        Stack(int size);
        ~Stack();
        void push(int e);
        int pop();
        int get_size();
        bool is_empty();
        bool is_full();
    private:
        int *data;
        int data_size;
        int top;
};