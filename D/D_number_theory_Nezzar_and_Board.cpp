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

//Editorial
/*Let's first assume that x1=0 (Otherwise, we could subtract x1 for x1,x2,…,xn and k). We will now prove that the answer is "YES" if and only if k can be divided by g=gcd(x2,x3,…,xn).

One direction is straightforward. Note that any number written on the board should be divisible by g, which follows from the fact that g|x,g|y⟹g|2x−y. It only remains to prove that for any x divisible by g, we could write down x on the board. We will prove it by induction on n.

Base case (n=2) is obvious. Let g0=gcd(x2,x3,…,xn−1). By Bézout's Theorem, there exists integers s,t such that g0s−xnt=g. By induction, we could write down g0 on the board, and trivially xnt can be written on the board. Therefore, we could write down g applying operation recursively.*/
void solve()
{
    lli n, k;
    cin >> n >> k;
    vlli x(n);
    rep(i, n)
    {
        cin >> x[i];
    }
    lli g = 0;
    rep1(i, n - 1)
    {
        g = __gcd(g, x[i] - x[0]);
    }
    if ((k - x[0]) % g == 0)
        cout << "YES\n";
    else
        cout << "NO\n";
    asort(x);

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