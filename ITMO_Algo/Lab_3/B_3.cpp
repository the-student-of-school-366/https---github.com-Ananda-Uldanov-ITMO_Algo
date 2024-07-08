#include <iostream>
using namespace std;

struct Node
{
    int data;
    Node *next;

    Node(int data) : data(data), next(nullptr) {}
};

struct Queue
{

    Node *head;
    Node *tail;
    Queue()
        : head(nullptr),
          tail(nullptr)
    {
    }

    void enqueue(int data)
    {
        Node *newNode = new Node(data);
        if (isEmpty())
        {
            head = tail = newNode;
        }
        else
        {
            tail->next = newNode;
            tail = newNode;
        }
    }

    void dequeue()
    {
        if (isEmpty())
        {
            cout << "Queue is empty." << endl;
            return;
        }
        Node *temp = head;
        head = head->next;
        delete temp;
        if (head == nullptr)
        {
            tail = nullptr;
        }
    }

    int front()
    {
        if (isEmpty())
        {
            cout << "Queue is empty." << endl;
            return -1;
        }
        return head->data;
    }

    bool isEmpty()
    {
        return head == nullptr;
    }
};

int main()
{
    int n, k, v;
    k = 0;
    cin >> n;
    int a[n];
    char sign;
    Queue st;
    for (int i = 0; i < n; i++)
    {
        cin >> sign;
        if (sign == '-')
        {
            a[k] = st.front();
            st.dequeue();
            k += 1;
        }
        else
        {
            cin >> v;
            st.enqueue(v);
        }
    }
    for (int i = 0; i < k; i++)
    {
        cout << a[i] << '\n';
    }
}/*#include <iostream>
using namespace std;
struct Node
{
    int value;
    Node *next;
    Node *prev;

    Node(int val)
    {
        value = val;
    }
};

struct Queue
{
    Node *head;
    Node *tail;
    Queue()
    {
        head = NULL;
        tail = NULL;
    }
    void push(int val)
    {
        Node *tmp = new Node(val);
        if (isEmpty())
        {
            head = tmp;
            tail = tmp;
            return;
        }
        tail->next = tmp;
        tmp->prev = tail;
        tail = tmp;
    }

    int getTop()
    {
        if (isEmpty())
        {
            cout << "Error Stack is empty";
            return;
        }
            return head->value;
    }
    void pop()
    {
        if (!isEmpty())
        {
            Node *tmp = head;
            head = head->next;
            // if (head == NULL)
            //   head->prev = NULL;
            delete tmp;
            if (head == NULL)
                tail = NULL;
        }
        else
        {
            cout << "Error queue is empty";
            return;
        }
    }
    bool isEmpty()
    {
        return head == NULL;
    }
};
int main()
{
    int n, k, v;
    k = 0;
    cin >> n;
    int a[n];
    char sign;
    Queue st;
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
}*/