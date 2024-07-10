#include <iostream>
#include<stdexcept>
using namespace std;

class myexception : public exception {
public:
    myexception(const char* message) : stroka(message) {}

    const char* what() const noexcept override {
        return stroka;
    }

private:
    const char* stroka;
};

template <class T>
class Stack
{
private:
    int top;
    T *arr;
    int size;

public:
    Stack(int n);
    ~Stack();

    void push(T x);
    T pop();
};

template <class T>
Stack<T>::Stack(int n)
{
    arr = new T[n];
    size = n;
    top = -1;
}

template <class T>
Stack<T>::~Stack()
{
    delete[] arr;
}

template <class T>
void Stack<T>::push(T x)
{
    if (top + 1 >= size)
    {
        throw myexception("Stack overflow");
    }
    arr[top++] = x;
}

template <class T>
T Stack<T>::pop()
{
    if (top < 0)
    {
        throw myexception("Stack is empty");
    }
    return arr[top--];
}

template <class T>
void getDegree(T x, int n)
{
    T res = 1;
    for (int i = 0; i < n; i++)
    {
        res = x * res;
    }
    cout << res << "\n";
}

int main()
{
    int N;
    cin >> N;
    Stack<int> stack(N);

    string command;
    while (cin >> command)
    {
        if (command == "push")
        {
            int x;
            cin >> x;
            try
            {
                stack.push(x);
            }
            catch (const myexception &e)
            {
                cout << e.what() << endl;
            }
        }
        else if (command == "Degree")
        {
            double y;
            int n;
            cout << "Please, add base and exponent" << '\n';
            cin >> y >> n;
            cout << "Degree = ";
            getDegree<double>(y, n);
        }
        else if (command == "pop")
        {
            try
            {
                cout << stack.pop() << endl;
            }
            catch (const myexception &e)
            {
                cout << e.what() << endl;
            }
        }
    }

}
