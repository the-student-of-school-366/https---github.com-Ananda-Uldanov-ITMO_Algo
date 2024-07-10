#include <iostream>
#include <string>
#include <vector>
using namespace std;

struct Node
{
    double left;
    double right;
    char littera;
    double prob;
};

int main()
{
    vector<int> counter(513, 0);
    vector<double> result;
    vector<Node> nod(513);
    string message;
    cin >> message;
    int sum = 0;
    nod[0].left = 0;
    int count_nod = 0;

    for (int i = 0; i < message.size(); i++)
    {
        char tmp = message[i];
        counter[tmp]++;
    }

    for (int i = 0; i < counter.size(); i++)
    {
        sum += counter[i];
    }

    for (int i = 0; i < counter.size(); i++)
    {
        if (counter[i] != 0)
        {
            result.push_back(counter[i]);
            nod[count_nod].prob = counter[i] / static_cast<double>(sum);
            nod[count_nod].littera = char(i);

            if (count_nod != 0)
            {
                nod[count_nod].left = nod[count_nod - 1].right;
            }

            nod[count_nod].right = nod[count_nod].left + nod[count_nod].prob;
            count_nod++;
        }
    }

    for (int i = 0; i < message.size(); i++)
    {
        int index;
        char sign = message[i];
        for (int j = 0; j < nod.size(); j++)
        {
            if (sign == nod[j].littera)
            {
                index = j;
            }
        }
        double lef = nod[index].left;
        double righ = nod[index].right;
        double pro = nod[index].prob;
        nod[0].left = lef;
        nod[0].right = lef + (righ - lef) * nod[0].prob;
        for (int j = 1; j < nod.size(); j++)
        {
            nod[j].left = nod[j - 1].right;
            nod[j].right = nod[j].left + (righ - lef) * nod[j].prob;
        }
    }

    for (int i = 0; i < nod.size(); i++)
    {
        if (message[message.size() - 1] == nod[i].littera)
        {
            cout << nod[i].left;
        }
    }
}
