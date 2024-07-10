#include<iostream>
#include<string>
using namespace std;
struct Node
{
    int value;
    Node *next;

    Node(int val)
    {
        value = val;
    }
};

struct Stack
{
    Node *top;
    Stack()
    {
        top = NULL;
    }

    void push(int val)
    {
        Node *tmp = new Node(val);
        tmp->next = top;
        top = tmp;
    }

    int getTop()
    {
        if (!isEmpty())
        {
            return top->value;
        }
        else
        {
            cout << "Error Stack is empty";
            exit(1);
        }
    }
    void pop()
    {
        if (!isEmpty())
        {
            Node *tmp = top;
            top = top->next;
            free(tmp);
        }
        else
        {
            cout << "Error stack is empty";
            exit(1);
        }
    }
    bool isEmpty()
    {
        return top == NULL;
    }
};
int main()
{
    string c;
    Stack st;
    
}