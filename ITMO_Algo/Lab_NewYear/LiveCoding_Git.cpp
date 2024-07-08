#include <iostream>
#include <vector>
#include<algorithm>
using namespace std;

const size_t Max_ALF = 1000;

struct Suffix
{
    string s;
    vector<int> replace;

    explicit Suffix(const string &str) : s(str), replace(str.size())
    {
        s.push_back(1);
        size_t n = s.size();

        vector<int> clas(n);
        vector<int> mas(n);
        vector<int> counter(max(n, Max_ALF));

        for (int i = 0; i < n; i++)
        {
            counter[s[i]]++;
        }

        for (int i = 1; i < Max_ALF; i++)
        {
            counter[i] += counter[i - 1];
        }

        for (int i = 0; i < n; i++)
        {
            --counter[s[i]];
            mas[counter[s[i]]] = i;
        }

        clas[mas[0]] = 0;
        int numberCl = 1;
        for (int i = 1; i < n; i++)
        {
            if (s[mas[i]] != s[mas[i - 1]])
            {
                numberCl++;
            }
            clas[mas[i]] = numberCl - 1;
        }

        vector<int> npm(n);
        vector<int> nclasses(n);
        for (int j = 0;  pow (2, j) < n; j++)
        {
            int len =  pow (2, j);

            for (int i = 0; i < n; i++)
            {
                npm[i] = mas[i] - len;
                if (npm[i] < 0)
                {
                    npm[i] += n;
                }
            }

            fill(counter.begin(), counter.begin() + numberCl, 0);
            for (int i = 0; i < n; i++)
            {
                counter[clas[npm[i]]]++;
            }

            for (int i = 1; i < numberCl; i++)
            {
                counter[i] += counter[i - 1];
            }

            for (int i = n - 1; i >= 0; i--)
            {
                mas[--counter[clas[npm[i]]]] = npm[i];
            }

            nclasses[mas[0]] = 0;
            numberCl = 1;
            for (int i = 1; i < n; i++)
            {
                pair<int, int> cur = {clas[mas[i]], clas[(mas[i] + ( pow (2, j))) % n]};
                pair<int, int> prev = {clas[mas[i - 1]], clas[(mas[i - 1] + ( pow (2, j))) % n]};
                if (cur != prev)
                {
                    numberCl++;
                }
                nclasses[mas[i]] = numberCl - 1;
            }
            clas.swap(nclasses);
        }

        for (int i = 0; i < n - 1; i++)
        {
            replace[i] = mas[i + 1];
        }
        s.pop_back();
    }

    vector<int> kasaiLCP()
    {
        size_t n = replace.size();

        vector<int> r(n), res(n - 1);
        for (int i = 0; i < n; i++)
        {
            r[replace[i]] = i;
        }

        s.push_back(1);

        int cur = 0;
        for (int i = 0; i < n; i++)
        {
            if (cur > 0)
            {
                cur--;
            }
            if (r[i] == n - 1)
            {
                cur = 0;
            }
            else
            {
                while (s[i + cur] == s[replace[r[i] + 1] + cur])
                {
                    cur++;
                }
                res[r[i]] = cur;
            }
        }
        s.pop_back();

        return res;
    }

    int numberOfDifferentSubs()
    {
        size_t n = replace.size();

        vector<int> r(n);
        vector<int> res(n - 1);
        for (int i = 0; i < n; i++)
        {
            r[replace[i]] = i;
        }

        s.push_back(1);

        int cur = 0;
        int sum = 0;
        for (int i = 0; i < n; i++)
        {
            if (cur > 0)
            {
                --cur;
            }
            if (r[i] == n - 1)
            {
                cur = 0;
            }
            else
            {
                while (s[i + cur] == s[replace[r[i] + 1] + cur])
                {
                    cur++;
                }
                res[r[i]] = cur;
                sum += cur;
            }
        }
        s.pop_back();

        int ans = (int)n * (int)(n + 1) / 2 - sum;
        return ans;
    }

    void print()
    {
        for (int i : replace)
        {
            cout << i + 1 << " ";
        }
        cout << "\n";
    }

    
};

int main()
{

    string s;
    cin >> s;

    Suffix Suffix(s);

    int res = Suffix.numberOfDifferentSubs();
    cout << res << "\n";
}