#include "bits/stdc++.h"

using namespace std;

#define ll long long

int t, n, m;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    cin >> t;
    while (t--)
    {

        cin >> n >> m;
        string s(m, 'B');

        while (n--)
        {

            int x;
            cin >> x;
            x--;
            x = min(x, m - x - 1);

            if (s[x] == 'B')
                s[x] = 'A';
            else
                s[m - x - 1] = 'A';
        }

        cout << s << "\n";
    }
}