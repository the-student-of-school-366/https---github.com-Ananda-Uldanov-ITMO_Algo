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
    int n, k, v;
    k = 0;
    cin >> n;
    int a[n];
    char sign;
    Stack st;
    for (int i = 0; i < n; i++)
    {
        cin >> sign;
        if (sign == '-')
        {
            a[k] = st.getTop();
            st.pop();
            k += 1;
        }
        else
        {
            cin >> v;
            st.push(v);
        }
    }
    for (int i = 0; i < k; i++)
    {
        cout << a[i] << '\n';
    }
}