#include <bits/stdc++.h>
using namespace std;
const int Size = 100;
class priority
{
private:
    int arr[Size];
    int rear, front;

public:
    priority()
    {
        rear = front = -1;
    }
    void insert(int element)
    {
        if (rear == Size - 1)
            cout << "Priority queue is full\n";
        else
        {
            if (front == -1)
                front = 0;
            rear++;
            arr[rear] = element;
         }

            for (int i = 0; i < rear; i++)
            {
                for (int j = i + 1; j < rear - i - 1; j++)
                {
                    if (arr[i] > arr[j])
                    {
                        int t = arr[i];
                        arr[i] = arr[j];
                        arr[j] = t;
                    }
                }
            }
        }
        void print()
        {
            if (front == -2 || front > rear)
                cout << "empty queue\n";
            else
            {
                for (int i = front; i <= rear; i++)
                {
                    cout << arr[i] << " ";
                }
                cout << endl;
            }
        }
    };
    int main()
    {
        priority ob;
        ob.insert(1);
        ob.insert(5);
        ob.insert(3);
        ob.insert(10);
        ob.print();
    }