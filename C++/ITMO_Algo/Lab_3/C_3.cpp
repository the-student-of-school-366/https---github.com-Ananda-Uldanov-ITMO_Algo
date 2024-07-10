#include <iostream>
#include <string>
using namespace std;
int main()
{
    int n, k, t;
    cin >> n >> k >> t;
    string *a = new string[n];
    char *b = new char[n];
    for (int i = 0; i < n; i++)
    {
        cin >> a[i];
    }
    for (int i = 0; i < n ; i++)
    {
        string c;
        for (int j = 0; j < n - 1; j++)
        {
                if ((a[j]).substr(k-t, t) > (a[j+1]).substr(k-t,t))
                {
                    c = a[j];
                    a[j] = a[j + 1];
                    a[j + 1] = c;
                }
        }
    }

    for (int i = 0; i < n; i++)
    {
        cout << a[i];
        cout << '\n';
    }
    delete[] a;
    delete[] b;
}