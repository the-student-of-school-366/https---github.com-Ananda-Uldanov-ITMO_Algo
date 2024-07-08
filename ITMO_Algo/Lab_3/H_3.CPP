#include <iostream>
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
    int n, a, s, b;
    long long c;
    b = s = 0;
    cin >> n;
    if(n==0){
        cout<<0;
        exit(1);
    }
    Stack st;
    Stack reverse;
    for (int i = 0; i < n; i++)
    {
        cin >> c;
        st.push(c);
    }
    a =  st.getTop();
    for (int i = 0; i < n; i++)
    {
        if (a > st.getTop())
        {
            a = st.getTop();
        }
        b += 1;
        s = max(s, (a * b));
        s = max(s,st.getTop());
        reverse.push(st.getTop());
        st.pop();
    }
    b = 0;
    a = reverse.getTop();
    for (int i = 0; i < n; i++)
    {
        if (a > reverse.getTop())
        {
            a = reverse.getTop();
        }
        b += 1;
        s = max(s, (a * b));
        s= max(s,reverse.getTop());
        reverse.pop();
    }
    cout << s;
}