#include<iostream>
using namespace std;

template<class T>
class queue : public Queue<T>
{
 private:
 int Front; // 1 counterclockwise from the 
Front element
 int Rear; // position of the Back element
 int ArrayLength; // queue capacity
 T *Queue; // element array
 public:
 queue(int InitialCapacity = 20);
 ~ queue()
 {
 delete[] queue;
 }
 bool Empty() const
 {
 return Front == Rear;
 }
 int Size() const
 {
 return(Rear - Front + ArrayLength) % ArrayLength;
 }
 T& Front()
 {
 if(Front == Rear)
 cout << "Sorry queue empty" << endl;
 return Queue[(Front + 1) % ArrayLength];
 }
 T& Back()
 {
 // return Rear element
 if(Front == Rear)
 cout << "Sorry queue empty" << endl;
 return Queue[Rear];
 }
 void Delete()
{
 // remove Front element
 if(Front == Rear)
 cout << "Sorry Queue Empty" << endl;
 Front = (Front + 1) % ArrayLength;
 Queue[Front].~T();
 }
  void Add(const T& Element);
};
template<class T>
queue <T> :: queue(int InitialCapacity)
{
 ArrayLength = InitialCapacity;
 Queue = new T[ArrayLength];
 Front = 0;
 Rear = 0;
}
template<class T>
void queue <T> :: Add(const T& Element)
{
 if((theBack + 1) % arrayLength == Front)
 cout << "Sorry queue is full" << endl;
 else
 Rear = (Rear + 1) % ArrayLength;
 Queue[Rear] = Element;
}
int main(void)
{
 queue <int> Q(10);
 int Data;
 Q.Add(1);
 Q.Add(2);
 Data = Q.Delete();
 cout << Data;
 Q.Add(3);
 Data = Q.Delete();
 cout << Data;
 Q.Add(4);
}
