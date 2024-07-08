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
    int n,a,k,s;
    s=0;
    cin>>n;
    int arr[n];
    Queue qu;
    for(int i=0;i<n;i++)
    {
        int c;
        cin>>c;
        qu.enqueue(c);
        arr[i]=c;

    }
    for(int i=0;i<n;i++)
    {
        k=0;
        int j=i;
        a=qu.front();
        while((a>=arr[j]) and(j<n))
        {
            k+=1;
            j+=1;
        }
        if(j>=n){
            k=-1;
        }
        cout<<k<<" ";
        qu.dequeue();

    }
}