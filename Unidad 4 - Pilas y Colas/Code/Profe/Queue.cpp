// Queue ADT
#include <iostream>
using namespace std;

class queue
{
private:
    int Rear, Front;
    int Queue[50];
    int max;
    int Size;

public:
    queue()
    {
        Size = 0;
        max = 50;
        Rear = Front - 1;
    }
    int Is_Empty();
    int Is_Full();
    void Add(int Element);
    int Delete();
    int getFront();
};
int queue ::Is_Empty()
{
    if (Front == Rear)
        return 1;
    else
        return 0;
}
int queue ::Is_Full()
{
    if (Rear == max - 1)
        return 1;
    else
        return 0;
}
void queue ::Add(int Element)
{
    if (!Is_Full())
        Queue[++Rear] = Element;
    Size++;
}
int queue ::Delete()
{
    if (!Is_Empty())
    {
        Size--;
        return (Queue[++Front]);
    }
}
int queue ::getFront()
{
    if (!Is_Empty())
        return (Queue[Front + 1]);
}

int main()
{
    queue Q;
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

    return 0;
}