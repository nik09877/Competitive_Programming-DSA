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
#define int long long
const int mod = 1000000007;
int32_t main()
{
    fastio;
    int n, a, b;
    cin >> a >> b >> n;
    int gcd = __gcd(a, b);
    vi div;
    for (int i = 1; i * i <= gcd; i++)
    {
        if (gcd % i == 0)
        {
            div.pb(i);
            if ((gcd / i) != i)
                div.pb(gcd / i);
        }
    }
    asort(div);
    while (n--)
    {
        int L, R, ans = -1;
        cin >> L >> R;
        // rrep(i, sz(div) - 1, 0)
        // {
        //     if (div[i] >= L and div[i] <= R)
        //     {
        //         ans = div[i];
        //         break;
        //     }
        // }
        auto it = upper_bound(all(div), R);
        if (it != div.begin())
            it--;
        if (*it >= L)
            ans = *it;
        prln(ans);
    }
}