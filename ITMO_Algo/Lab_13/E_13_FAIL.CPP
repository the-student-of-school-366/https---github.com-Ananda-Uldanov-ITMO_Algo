#include "blazingio.hpp"
#include <set>
#include <vector>
#include <string>
using namespace std;
int main()
{
    int N;
    cin >> N;

    set<string> books;
    vector<string> sorted_books;

    for (int i = 0; i < N; ++i)
    {
        string input;
        cin >> input;

        if (isdigit(input[0]))
        {
            int k = stoi(input);
            cout << sorted_books[k - 1] << endl;
        }
        else
        {
            books.insert(input);
            sorted_books = vector<string>(books.begin(), books.end());
        }
    }
}
