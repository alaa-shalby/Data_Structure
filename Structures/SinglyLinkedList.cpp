#include <bits/stdc++.h>
using namespace std;
struct Node
{
    int data;
    Node *next;
};
class List
{
private:
    Node *start;

public:
    List()
    {
        start = NULL;
    }
    void insert(int item)
    {
        Node *Newnode = new Node;
        Newnode->data = item;
        if (start == nullptr)
        {
            Newnode->next = NULL;
        }
        else
        {
            Newnode->next = start;
        }
        start = Newnode;
    }
    void print (){
        Node *temp=start;
        while (temp!=NULL)
        {
           cout<<temp->data<<' ';
           temp=temp->next;
        }
        cout<<endl;
    }
    void traverse(){
        Node *curr=start;
        Node *prev=NULL;
        Node *next_node=NULL;
        while (curr!=NULL)
        {
          next_node=curr->next;
          curr->next=prev;
          prev=curr;
          curr=next_node;
        }
        start=prev;
    }

};
int main()
{
    List ob;
    ob.insert(1);
    ob.insert(2);
    ob.insert(3);
    ob.insert(4);
    ob.insert(5);
    ob.print();
    ob.traverse();
    ob.print();
}