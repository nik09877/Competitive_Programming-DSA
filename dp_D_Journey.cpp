#include <bits/stdc++.h>
#include <stdio.h>
#define rep(i, n) for (int i = 0; i < n; i++)
#define rrep(i, a, b) for (int i = a; i >= b; i--)
#define rep1(i, n) for (int i = 1; i <= n; i++)
#define fo(i, a, n) for (int i = a; i <= n; i++)
#define repll(i, a, n) for (lli i = a; i <= n; i++)
#define mkp make_pair
#define pb push_back
#define eb emplace_back
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
#define ceil(numerator, denominator) return (numerator + denominator - 1) / denominator;
#define umap unordered_map
#define uset unordered_set
#define sz(x) ((int)(x).size())
#define fastio ios_base::sync_with_stdio(0), cout.tie(0), cin.tie(0)
#define read(a, n) \
    rep(i, n)      \
            cin >> \
        a[i];
using namespace std;
const int mod = 1000000007;

void solve()
{
    int n;
    string s;
    cin >> n >> s;
    vi Ll(n + 1, 0);
    vi Lr(n + 1, 0);
    vi Rl(n + 1, 0);
    vi Rr(n + 1, 0);

    //Ll[i] denotes from this nodes how far left we can go and Rr[i] denotes how far right we can go
    //Lr[i] denotes in left direction presence of R
    //Rl[i] denotes in right direction presence of L
    // to satisfy  ....R L R L R L <-(node)-> R L R L R L....
    //this is similar to longest regular bracket sequence
    rep1(i, n)
    {
        if (s[i - 1] == 'L')
        {
            Ll[i] = Lr[i - 1] + 1;
            Lr[i] = 0;
        }
        else
        {
            Lr[i] = Ll[i - 1] + 1;
            Ll[i] = 0;
        }
    }
    rrep(i, n - 1, 0)
    {
        if (s[i] == 'R')
        {
            Rr[i] = Rl[i + 1] + 1;
            Rl[i] = 0;
        }
        else
        {
            Rl[i] = Rr[i + 1] + 1;
            Rr[i] = 0;
        }
    }
    rep(i, n + 1)
    {
        cout << Ll[i] + Rr[i] + 1 << sp;
    }
    cout << endl;
    return;
}
int32_t main()
{
    fastio;
    int t = 1;
    cin >> t;
    while (t--)
    {
        solve();
    }
}