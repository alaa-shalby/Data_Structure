//! Circular Queue
#include <iostream>
#include <cassert>
using namespace std;
// assert() --> بترجع true او false وبتعرفني فين السطر بقى false
#define nl "\n"
const int Max_size = 100;
class Queue
{
    int rear, front;
    int arr[Max_size];

public:
    Queue()
    {
        rear = -1;
        front = -1;
    }
    bool isEmpty()
    {
        return ((rear == 0) && (front == 0));
    }
    bool isFull()
    {
        return front == (rear + 1) % Max_size;
    }
    void Add(int item)
    {
        if (isFull())
            cout << "Queue is full\n";
        else
        {
            rear = (rear + 1) % Max_size;
            arr[rear] = item;
        }
    }
    void Delete()
    {
        if (isEmpty())
            cout << "Queue is empty\n";
        front = (front + 1) % Max_size;
    }
    void Display()
    {
        if (isEmpty())
            cout << " Queue is empty \n";
        else
        {
            int r = front;
            while (r != rear)
            {
                r = (r + 1) % Max_size;
                cout << arr[r] << " \n";
            }
        }
    }
};
int main()
{
    if (fopen("input.txt", "r"))
    {
        freopen("input.txt", "r", stdin);
        freopen("output.txt", "w", stdout);
    } 
    Queue q;
    q.Add(1);
    q.Add(2);
    q.Add(3);
    q.Add(15);
    q.Display();
    cout << "______\n";
    q.Delete();
    q.Display();
    cout << "______\n";
    q.Add(7);
    q.Display();
}