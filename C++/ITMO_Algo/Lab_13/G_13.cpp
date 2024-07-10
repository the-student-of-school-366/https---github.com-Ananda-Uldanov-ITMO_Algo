#include "blazingio.hpp"
#include <vector>
using namespace std;
int main()
{
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);
    int n;
    int m;
    cin >> n >> m;
    vector<int> cards(n);
    for (int &x : cards)
        cin >> x;

    for (int i = ((n + 1) / 2); i >= 0; --i)
    {
        bool flag = true;
        for (int j = 0; j < i; ++j)
        {
            if (cards[i - 1 - j] != cards[i + j])
            {
                flag = false;
                break;
            }
        }
        if (flag)
            cout << n - i << " ";
    }
}