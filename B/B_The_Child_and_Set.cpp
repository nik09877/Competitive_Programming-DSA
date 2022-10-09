#include <bits/stdc++.h>
using namespace std;
#define endl "\n"
#define fo(i, s, e) for (i = s; i < e; i++)
#define rfo(i, s, e) for (i = s; i > e; i--)
#define LL long long int
const LL MOD = 1e9 + 7;
#define pb push_back
#define pob pop_back()
#define sp " "
#define ff first
#define ss second
//            When something is important enough, you do it even if the odds are not in your favor.
LL solve(LL n)
{
    std::vector<bool> v;
    while (n > 0)
    {
        v.pb(n % 2);
        n /= 2;
    }
    LL i;
    fo(i, 0, v.size())
    {
        if (v[i] == 1)
            return pow(2, i);
    }
}
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif
    // code goes here
    int t = 1; // cin>>t;
    while (t--)
    {
        LL s, l, i, j;
        cin >> s >> l;
        std::vector<LL> v;
        rfo(i, l, 0)
        {
            if (solve(i) <= s)
            {
                s -= solve(i);
                v.pb(i);
            }
        }
        if (s == 0)
        {
            cout << v.size() << endl;
            for (auto x : v)
                cout << x << sp;
        }
        else
            cout << -1;
    }
    return 0;
}