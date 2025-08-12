#include <bits/stdc++.h>
using namespace std;
#define nl endl
const int Max_size = 100;
class Stack
{
private:
    int top;
    int arr[Max_size];

public:
    Stack() { top = -1; }
    void push(char c)
    {
        if (top == Max_size - 1)
        {
            cout << "Stack is full\n";
        }
        else
        {
            top++;
            arr[top] = c;
        }
    }
    bool isEmpty()
    {
        return top == -1;
    }
    void pop()
    {
        if (isEmpty())
        {
            cout << "Stack is empty\n";
        }
        else
        {
            top--;
        }
    }
    char Top()
    {
        if (isEmpty())
        {

            return '\0';
        }
        else
        {
            return arr[top];
        }
    }
};
void balance(string s)
{
    Stack st;
    string str = {};
    for (auto &i : s)
    {

        if (i == '(' || i == '{' || i == '[')
        {
            st.push(i);
        }
        else if (i == ')' && st.Top() == '(' && !st.isEmpty())
        {
            st.pop();
        }
        else if (i == '}' && st.Top() == '{' && !st.isEmpty())
        {
            st.pop();
        }
        else if (i == ']' && st.Top() == '[' && !st.isEmpty())
        {
            st.pop();
        }
        else if ((i == ')' || i == '}' || i == ']') && (st.isEmpty()))
        {
            cout << "No\n";
            return;
        }
    }
    if (st.isEmpty())
    {
        cout << "Yes\n";
    }
    else
    {
        cout << "No\n";
    }
}
void outPut()
{
    string exp;
    cin >> exp;
    balance(exp);
}
int main()
{
   
    int t = 1;
    cin >> t;
    while (t--)
    {
        outPut();
    }
}
/* 6
 (A+B)
 {(A+B)+(c+d)}
 {(x+y)*(z)
 [2+3]+(A)]
 {a+z)
 {())}(*/