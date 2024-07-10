#include "blazingio.hpp"
#include <string>
#include <map>
#include <vector>

using namespace std;

struct SufAuto
{
    struct State
    {
        int length, link;
        map<char, int> transitions;
    };

    vector<State> states;
    int last;

    SufAuto(const string &s)
    {
        states.push_back({0, -1});
        last = 0;

        for (char c : s)
        {
            extend(c);
        }
    }

    void extend(char c)
    {
        int cur = states.size();
        states.push_back({states[last].length + 1, 0});
        int p = last;

        while (p != -1 && !states[p].transitions.count(c))
        {
            states[p].transitions[c] = cur;
            p = states[p].link;
        }

        if (p == -1)
        {
            states[cur].link = 0;
        }
        else
        {
            int q = states[p].transitions[c];
            if (states[p].length + 1 == states[q].length)
            {
                states[cur].link = q;
            }
            else
            {
                int clone = states.size();
                states.push_back({states[p].length + 1, states[q].link, states[q].transitions});
                while (p != -1 && states[p].transitions[c] == q)
                {
                    states[p].transitions[c] = clone;
                    p = states[p].link;
                }
                states[q].link = states[cur].link = clone;
            }
        }
        last = cur;
    }

    long long UniqSub()
    {
        long long count = 0;
        for (const auto &state : states)
        {
            count += state.length - (state.link == -1 ? 0 : states[state.link].length);
        }
        return count;
    }
};

int main()
{
    string p;
    cin >> p;

    SufAuto sf(p);
    cout << sf.UniqSub();
}
