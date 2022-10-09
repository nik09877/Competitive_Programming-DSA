#include <bits/stdc++.h>
using namespace std;

int main()
{
    int n, k;
    cin >> n >> k;
    vector<int> a(n);
    for (auto &i : a)
        cin >> i;
    int l = 1, r = n + 1;
    while (r - l > 1)
    {
        int m = (l + r) / 2;
        vector<int> b(n);
        for (int i = 0; i < n; ++i)
            if (a[i] >= m)
            {
                b[i] = 1;
            }
            else
            {
                b[i] = -1;
            }
        for (int i = 1; i < n; ++i)
            b[i] += b[i - 1];
        int mx = b[k - 1];
        int mn = 0;
        for (int i = k; i < n; ++i)
        {
            mn = min(mn, b[i - k]);
            mx = max(mx, b[i] - mn);
        }
        if (mx > 0)
        {
            l = m;
        }
        else
        {
            r = m;
        }
    }
    cout << l << '\n';
    return 0;
}