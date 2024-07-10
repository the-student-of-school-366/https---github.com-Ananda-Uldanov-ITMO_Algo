#include <iostream>
#include <vector>
using namespace std;
template <typename T>
bool grater(T a, T b)
{
    return (a <= b);
}
template <typename T>
bool all_of(typename vector<T>::iterator iter, typename vector<T>::iterator iter2, T x)
{
    while (iter != iter2)
    {
        if (*iter > x)
        {
            return false;
        }
        iter++;
    }
    return true;
}

template <class T, class P>
bool is_sorted(T iter, T iter2, P g)
{

    cout << "stert" << endl;
    T tmp = --iter2;
    while (iter != tmp)
    {
        cout << "in cycle" << endl;
        if (!g(*iter, *(iter+1)))
        {
            cout << "exec if" << endl;
            return false;
        }
        iter++;
    }
    cout << "exec all cycle" << endl;
    return true;
}

template <typename T>
int is_palindrome(typename vector<T>::iterator iter, typename vector<T>::iterator iter2, unsigned int size)
{
    if (size % 2 == 0)
    {
        while (iter != iter2 - 1)
        {
            if (*iter != *iter2)
            {
                return false;
            }
            iter++;
            iter2--;
        }
        return true;
    }
    else
    {
        while (iter != iter2)
        {
            if (*iter != *iter2)
            {
                return false;
            }
            iter++;
            iter2--;
        }
        return true;
    }
}

int main()
{
    vector<int> plenty;
    int n;
    int a;
    int k;

    cin >> n;

    for (int i = 0; i < n; i++)
    {
        cin >> a;
        plenty.push_back(a);
    }

    cout << "Enter the biggest number = ";
    cin >> k;

    vector<int>::iterator iter = plenty.begin();
    vector<int>::iterator iter2 = plenty.end();

    if (all_of<int>(iter, iter2, k))
    {
        cout << "There are NO numbers bigger than " << k << '\n';
    }
    else
    {
        cout << "There are numbers bigger than  " << k << '\n';
    }

    iter = plenty.begin();
    iter2 = plenty.end();

    iter = plenty.begin();
    iter2 = plenty.end();
    iter2--;
    if (is_palindrome<int>(iter, iter2, plenty.size()))
    {
        cout << "Palindrome " << '\n';
    }
    else
    {
        cout << "Not palindrome " << '\n';
    }

    cout << is_sorted(plenty.begin(), plenty.end(), grater<int>);
};