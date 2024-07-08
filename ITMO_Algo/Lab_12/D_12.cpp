#include "blazingio.hpp"
#include <vector>
using namespace std;

int has(int x, int m)
{
    return x % m;
}

struct student
{
    int isu;
    int points;
    int group;
};
int main()
{
    int m;
    int q;
    cin >> m >> q;
    vector<int> out;
    vector<vector<student>> plenty(m);
    int g;
    for (int p = 0; p < q; p++)
    {
        char command;
        cin >> command;
        if (command == 'a')
        {
            int sum = 0;
            int count = 0;
            cin >> g;
            for (int i = 0; i < plenty[has(g,m)].size(); i++)
            {

                if (plenty[has(g,m)][i].group == g)
                {
                    sum += plenty[has(g,m)][i].points;
                    count += 1;
                }
            }
            if (count != 0)
                out.push_back(sum / count);
        }
        if (command == '-')
        {
            cin >> g;
            int is;
            cin >> is;
            for (int i = 0; i < plenty[has(g,m)].size(); i++)
            {
                if (plenty[has(g,m)][i].isu == is)
                {
                    plenty[has(g,m)][i] = {};
                }
            }
        }
        if (command == '+')
        {
            int is;
            int po;
            cin >> g >> is >> po;
            student tmp;
            tmp.isu = is;
            tmp.points = po;
            tmp.group = g;
            plenty[has(g,m)].push_back(tmp);
        }
        if (command == 'm')
        {
            int maxx = -1;
            cin >> g;
            for (int i = 0; i < plenty[has(g,m)].size(); i++)
            {
                if (plenty[has(g,m)][i].points > maxx)
                    maxx = plenty[has(g,m)][i].points;
            }
            out.push_back(maxx);
        }
    }
    for (int i = 0; i < out.size(); i++)
    {
        cout << out[i] << '\n';
    }
}