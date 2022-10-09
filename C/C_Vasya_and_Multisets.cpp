
#include <bits/stdc++.h>

using namespace std;

const int N = 109;

int n;
int a[N];
map<int, int> m;
set<int> s[2];

int main()
{
    int n;
    cin >> n;
    for (int i = 0; i < n; ++i)
    {
        cin >> a[i];
        m[a[i]]++;
    }

    int pos = 0;
    for (auto p : m)
        if (p.second == 1)
        {
            s[pos].insert(p.first);
            pos = 1 - pos;
        }

    if (s[0].size() == s[1].size())
    {
        string res(n, 'A');
        for (int i = 0; i < n; ++i)
            if (s[1].count(a[i]))
                res[i] = 'B';

        cout << "YES" << endl;
        for (auto c : res)
            cout << c;
        cout << endl;
        return 0;
    }
    else
    {
        assert(int(s[0].size()) - 1 == int(s[1].size()));
        string res(n, 'A');
        for (int i = 0; i < n; ++i)
            if (s[1].count(a[i]))
                res[i] = 'B';

        int id = -1;
        for (auto p : m)
            if (p.second >= 3)
            {
                id = p.first;
                break;
            }

        if (id == -1)
        {
            cout << "NO" << endl;
            return 0;
        }

        bool flag = false;
        for (int i = 0; i < n; ++i)
        {
            if (a[i] == id)
                if (!flag)
                {
                    flag = true;
                    res[i] = 'B';
                }
        }

        cout << "YES" << endl;
        for (auto c : res)
            cout << c;
        cout << endl;
        return 0;
    }
    return 0;
}