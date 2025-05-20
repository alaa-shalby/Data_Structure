#include <bits/stdc++.h>
using namespace std;
struct Node
{
    char data;
    Node *next;
};
class Stack
{
private:
    Node *Top;

public:
    Stack()
    {
        Top = NULL;
    }
    bool isEmpty()
    {
        return !Top;
    }
    void push(char ch)
    {
        Node *NewNode = new Node;
        NewNode->data = ch;
        if (isEmpty())
        {
            NewNode->next = NULL;
        }
        else
        {
            NewNode->next = Top;
        }
        Top = NewNode;
    }

    char top()
    {
        if (isEmpty())
        {
            return '\0';
        }
        else
        {
            return Top->data;
        }
    }
    void pop()
    {
        if (!isEmpty())
        {
            Node *temp = Top;
            Top = Top->next;
            delete temp;
        }
        else
            return;
    }
};
bool isBalance(string s)
{
    Stack st;
    for (auto &i : s)
    {
        if (i == '(' || i == '{' || i == '[')
        {
            st.push(i);
        }
        else if (i == ')' && st.top() == '(')
        {
            st.pop();
        }
        else if (i == ']' && st.top() == '[')
        {
            st.pop();
        }
        else if (i == '}' && st.top() == '{')
        {
            st.pop();
        }
        else if ((i == ']' || i == ')' || i == '}') && st.isEmpty())
        {
            return false;
        }
    }
    if (st.isEmpty())
    {

        return true;
    }
    else
    {

        return false;
    }
}
void solution()
{
    string exp;
    cin >> exp;
    if (isBalance(exp))
    {
        cout << "Yes\n";
        return;
    }
    else
    {
        cout << "NO\n";
        return;
    }
}
int main()
{
    if (fopen("input.txt", "r"))
    {
        freopen("input.txt", "r", stdin);
        freopen("output.txt", "w", stdout);
    }
    int t_ = 1;
    cin >> t_;
    while (t_--)
    {
        solution();
    }
    return 0;
}
