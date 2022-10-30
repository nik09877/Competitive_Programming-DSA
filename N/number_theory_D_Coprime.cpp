#include <bits/stdc++.h>
#define int long long
using namespace std;

void solve()
{
    map<int, int> m;
    int n;
    cin >> n;

    for (int i = 1; i <= n; i++)
    {
        int a;

        cin >> a;
        // cout<<a<<endl;
        m[a] = i;
    }
    int ans = -1;
    for (int i = 1; i <= 1000; i++)
    {
        for (int j = 1; j <= 1000; j++)
        {
            if ((m.find(i) == m.end()) or (m.find(j) == m.end()))
                continue;

            // cout<<i<<" "<<j<<endl;
            if (__gcd(i, j) == 1)
                ans = max(ans, m[i] + m[j]);
        }
    }

    cout << ans << endl;
}

int32_t main()
{
    int t = 1;

    cin >> t;

    while (t--)
    {
        solve();
    }
    return 0;
}