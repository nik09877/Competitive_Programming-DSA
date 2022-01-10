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
const int mod = 1000000007;
lli n, k;

// Let's say that a segment of this array a[l..r] (1≤l≤r≤n) is good if the difference between the maximum and minimum elements on this segment is at most k. Your task is to find the number of different good segments.
struct stack
{
    vlli s, s_max = {LLONG_MIN}, s_min = {LLONG_MAX};
    void push(lli val)
    {
        s.pb(val);
        s_max.pb(::max(s_max.back(), val));
        s_min.pb(::min(s_min.back(), val));
    }
    lli pop()
    {
        lli res = s.back();
        s.pop_back();
        s_max.pop_back();
        s_min.pop_back();
        return res;
    }
    bool empty()
    {
        return s.empty();
    }
    lli max()
    {
        return s_max.back();
    }
    lli min()
    {
        return s_min.back();
    }
};
::stack s1, s2;

void add(lli val)
{
    s2.push(val);
}

void remove()
{
    if (s1.empty())
    {
        while (!s2.empty())
        {
            s1.push(s2.pop());
        }
    }
    s1.pop();
}

bool good()
{
    lli mx = 0, mn = 0;
    mx = std::max(s1.max(), s2.max());
    mn = std::min(s1.min(), s2.min());
    return (mx - mn) <= k;
}

void solve()
{
    cin >> n >> k;
    vlli a(n);
    repll(i, 0, n - 1) cin >> a[i];

    lli ans = 0, l = 0;
    for (lli r = 0; r < n; r++)
    {
        add(a[r]);
        while (!good())
        {
            remove();
            l++;
        }
        ans += r - l + 1; // why? think
    }
    prln(ans);
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
