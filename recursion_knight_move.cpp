#include <bits/stdc++.h>
#include <stdio.h>
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
#define fastio ios_base::sync_with_stdio(0), cout.tie(0), cin.tie(0)
#define read(a, n) \
    rep(i, n)      \
            cin >> \
        a[i];
using namespace std;

vector<int> X = {-1, -1, -2, -2, 1, 1, 2, 2};
vector<int> Y = {2, -2, 1, -1, 2, -2, 1, -1};
bool is_safe(int x, int y, int n)
{
    if (x < n and x >= 0 and y < n and y >= 0)
        return true;
    return false;
}

int go(int x, int y, int k, int n)
{
    if (!(is_safe(x, y, n)))
        return 0;

    if (k == 0)
    {
        return 1;
    }

    int ans = 0;
    for (int i = 0; i < 8; i++)
    {
        ans += go(x + X[i], y + Y[i], k - 1, n);
    }
    return ans;
}

void solve()
{
    int n, x, y, k;
    cin >> n >> x >> y >> k;
    int ans = go(x, y, k, n);
    prln((ans * 100) / pow(8, k));
    return;
}
int32_t main()
{
    fastio;
    int t = 1;
    while (t--)
    {
        solve();
    }
}
