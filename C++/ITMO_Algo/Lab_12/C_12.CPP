#include "blazingio.hpp"
#include <vector>
using namespace std;
int h(int a)
{
    int x = a;
    x = x % 100000000;
    return ((x % 100000000) * (x % 17) + x % 31);
}
int main()
{
    unsigned long long sum1 = 0;
    unsigned long long product1 = 1;
    unsigned long long sum2 = 0;
    unsigned long long product2 = 1;

    int n;
    cin >> n;
    for (int i = 0; i < n; i++)
    {
        int x;
        cin >> x;
        x = h(x);
        sum1 += x;
        product1 *= x;
    }
    for (int i = 0; i < n; i++)
    {
        int x;
        cin >> x;
        x = h(x);
        sum2 += x;

        product2 *= x;
    }
    if ((sum2 == sum1) && (product1 == product2))
        cout << "YES";
    else
        cout << "NO";
}