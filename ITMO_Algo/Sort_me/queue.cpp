#include <iostream>
using namespace std;
struct Node
{
  Node *next = nullptr;
  int data;
  Node(int data) : data(data) {}
};
struct Queue
{
  Node *head;
  Node *tail;
  Queue() : head(nullptr), tail(nullptr){};

  void enqueue(int data)
  {
    Node *node = new Node(data);
    if (!isEmpty())
    {
      tail->next = node;
      tail = node;
    }
    else
    {
      tail = head = node;
    }
  };
  void dequeue()
  {
    if (!isEmpty())
    {
      Node *tmp = head;
      head = head->next;
      delete tmp;
      if (head == nullptr)
        tail = nullptr;
    }
    else
      cout << "Queue is empty!" << endl;
  }
  bool isEmpty()
  {
    if (head == nullptr)
      return true;
    else
      return false;
  }
  void getFront()
  {
    if (isEmpty())
    {
      cout << "Queue is empty!" << endl;
    }
    else
    {
      cout << head->data << endl;
      dequeue();
    }
  }
};
int main()
{
  Queue q;
  int n;
  cin >> n;
  for (int i = 0; i < n; i++)
  {
    char command;
    cin >> command;
    if (command == '+')
    {
      int input;
      cin >> input;
      q.enqueue(input);
    }
    if (command == '-')
    {
      q.getFront();
    }
  }
}
