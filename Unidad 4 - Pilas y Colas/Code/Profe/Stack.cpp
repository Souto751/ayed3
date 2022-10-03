#include <iostream>
using namespace std;

class Stack
{
private:
    int stack[50];
    int MaxCapacity;
    int top;

public:
    Stack()
    {
        MaxCapacity = 50;
        top = -1;
    }
    int getTop();
    int pop();
    void push(int Element);
    int Empty();
    int CurrSize();
    int IsFull();
};
int Stack ::getTop()
{
    if (!Empty())
        return (stack[top]);
}
int Stack ::pop()
{
    if (!Empty())
        return (stack[top--]);
}
int Stack ::Empty()
{
    if (top == -1)
        return 1;
    else
        return 0;
}
int Stack ::IsFull()
{
    if (top == MaxCapacity - 1)
        return 1;
    else
        return 0;
}
int Stack ::CurrSize()
{
    return (top + 1);
}
void Stack ::push(int Element)
{
    if (!IsFull())
        stack[++top] = Element;
}
int main()
{
    Stack S;
    S.pop();
    S.push(1);
    S.push(2);
    cout << S.getTop() << endl;
    cout << S.pop() << endl;
    cout << S.pop() << endl;
    return 0;
}
