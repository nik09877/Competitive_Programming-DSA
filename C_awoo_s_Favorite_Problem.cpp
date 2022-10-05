// Author : Epsilon573
// If it works, don't touch it.

#include <bits/stdc++.h>
using namespace std;

typedef unsigned long long ull;
typedef long long ll;
typedef long double ld;

const ll mod = 1e9 + 7;
const ld eps = 1e-9;
const ll maxn = 1e5 + 1;
const ll inf = 5e18;
const ll minf = -inf;

#define mp make_pair
#define pb push_back
#define endl "\n"

bool solve()
{
    ll n;
    cin >> n;

    string s, t, s2 = "", t2 = "";
    cin >> s >> t;

    for (ll i = 0; i < n; ++i)
    {
        if (s[i] != 'b')
            s2.pb(s[i]);
        if (t[i] != 'b')
            t2.pb(t[i]);
    }

    // check if relative positions of a and c are same
    if (s2 != t2)
        return false;

    vector<ll> s_cidx, t_cidx;
    for (ll i = 0; i < n; ++i)
    {
        if (s[i] == 'c')
            s_cidx.pb(i);
        if (t[i] == 'c')
            t_cidx.pb(i);
    }

    for (ll i = 0; i < s_cidx.size(); ++i)
        if (s_cidx[i] < t_cidx[i])
            return false;

    vector<ll> s_aidx, t_aidx;
    for (ll i = 0; i < n; ++i)
    {
        if (s[i] == 'a')
            s_aidx.pb(i);
        if (t[i] == 'a')
            t_aidx.pb(i);
    }

    for (ll i = 0; i < s_aidx.size(); ++i)
        if (s_aidx[i] > t_aidx[i])
            return false;

    return true;
}

int main()
{
    ios_base ::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

#ifdef EPSILON
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    freopen("error.txt", "w", stderr);
#endif

    ll t = 1;
    cin >> t;

    while (t--)
    {
        if (solve())
        {
            cout << "YES" << endl;
        }
        else
        {
            cout << "NO" << endl;
        }
    }

    return 0;
}