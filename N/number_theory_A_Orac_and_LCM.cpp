#include <bits/stdc++.h>
#define rep(i, n) for (int i = 0; i < n; i++)
#define rrep(i, a, b) for (int i = a; i >= b; i--)
#define rep1(i, n) for (int i = 1; i <= n; i++)
#define fo(i, a, n) for (int i = a; i <= n; i++)
#define repll(i, a, n) for (lli i = a; i <= n; i++)
#define mkp make_pair
#define pb emplace_back
#define ff first
#define ss second
#define ll long long
#define lli long long int
#define ii int, int
#define pii pair<int, int>
#define pll pair<long, long>
#define plli pair<long long int, long long int>
#define vi vector<int>
#define vvi vector<vector<int>>
#define vlli vector<long long int>
#define vpii vector<pair<int, int>>
#define vplli vector<pair<long long int, long long int>>
#define vvlli vector<vector<long long int>>
#define MAXLL 1e18
#define endl '\n'
#define sp ' '
#define dsort(v) sort(v.begin(), v.end(), greater<int>())
#define asort(v) sort(v.begin(), v.end())
#define uniq(v) v.erase(unique(v.begin(), v.end()), v.end())
#define all(v) v.begin(), v.end()
#define umap unordered_map
#define uset unordered_set
#define sz(x) ((int)(x).size())
#define yes cout << "YES\n"
#define no cout << "NO\n"
#define pr(x) cout << x
#define prsp(x) cout << x << sp
#define prln(x) cout << x << endl
#define fastio ios_base::sync_with_stdio(0), cin.tie(0)
#define re(a, n)   \
    rep(i, n)      \
            cin >> \
        a[i];
using namespace std;
const int mod = 1000000007;
lli binPower(lli a, lli n)
{
    lli res = 1;
    while (n > 0)
    {
        if (n & 1)
        {
            res = (res * a);
        }
        n >>= 1;
        a = (a * a);
    }
    return res;
}

int32_t main()
{
    fastio;
    lli n, ans = 1;
    cin >> n;
    map<lli, vlli> mp;
    rep(i, n)
    {
        lli x;
        cin >> x;
        for (int j = 2; j * j <= x; j++)
        {
            if (x % j == 0)
            {
                lli cnt = 0;
                while (x % j == 0)
                {
                    cnt++;
                    x /= j;
                }
                mp[j].pb(cnt);
            }
        }
        if (x > 1)
            mp[x].pb(1);
    }
    for (auto &it : mp)
    {
        int Sz = (int)mp[it.ff].size();
        if (Sz < (n - 1))
            continue;

        asort(mp[it.ff]);
        if (Sz == n - 1)
        {
            ans *= binPower(it.ff, mp[it.ff][0]);
        }
        else
        {
            ans *= binPower(it.ff, mp[it.ff][1]);
        }
    }
    prln(ans);
}