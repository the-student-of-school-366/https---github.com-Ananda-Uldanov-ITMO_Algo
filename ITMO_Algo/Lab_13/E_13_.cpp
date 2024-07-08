#include "blazingio.hpp"
#include <vector>
#include <string>
#include <algorithm>

using namespace std;

int main()
{
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);

    int N;
    cin >> N;

    vector<string> books;

    for (int i = 0; i < N; ++i)
    {
        string input;
        cin >> input;

        if (isdigit(input[0]))
        {

            int k = stoi(input);

            cout << books[k - 1] << endl;
        }
        else
        {

            books.push_back(input);

            sort(books.begin(), books.end());
        }
    }

    return 0;
}
