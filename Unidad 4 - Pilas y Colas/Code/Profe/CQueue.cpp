#include <iostream>
using namespace std;

class Cqueue
{
private:
    int Rear, Front;
    int Queue[50];
    int Max;
    int Size;

public:
    Cqueue()
    {
        Size = 0;
        Max = 50;
        Rear = Front = -1;
    }
    int Empty();
    int Full();
    void Add(int Element);
    int Delete();
    int getFront();
};
int Cqueue ::Empty()
{
    if (Front == Rear)
        return 1;
    else
        return 0;
}
int Cqueue ::Full()
{
    if (Rear == Front)
        return 1;
    else
        return 0;
}
void Cqueue ::Add(int Element)
{
    if (!Full())
        Rear = (Rear + 1) % Max;
    Queue[Rear] = Element;
    Size++;
}
int Cqueue ::Delete()
{
    if (!Empty())
        Front = (Front + 1) % Max;
    Size--;
    return (Queue[Front]);
}
int Cqueue ::getFront()
{
    int Temp;
    if (!Empty())
        Temp = (Front + 1) % Max;
    return (Queue[Temp]);
}
int main(void)
{
    Cqueue Q;
    Q.Add(11);
    Q.Add(12);
    Q.Add(13);
    cout << Q.Delete() << endl;
    Q.Add(14);
    cout << Q.Delete() << endl;
    cout << Q.Delete() << endl;
    cout << Q.Delete() << endl;
    cout << Q.Delete() << endl;
    Q.Add(15);
    Q.Add(16);
    cout << Q.Delete() << endl;
    return 0 ;
}
