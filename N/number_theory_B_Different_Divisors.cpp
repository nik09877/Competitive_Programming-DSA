#include <bits/stdc++.h>
#include <stdio.h>
#define rep(i, n) for (int i = 0; i < n; i++)
#define rrep(i, a) for (int i = a; i >= 0; i--)
#define rep1(i, n) for (int i = 1; i <= n; i++)
#define fo(i, a, n) for (int i = a; i <= n; i++)
#define repll(i, a, n) for (lli i = a; i <= n; i++)
#define mkp make_pair
#define pb push_back
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
#define fastio ios_base::sync_with_stdio(0), cout.tie(0), cin.tie(0)
#define read(a)       \
    for (auto &i : a) \
        cin >> i;
using namespace std;
const int mod = 1000000007;
const lli N = 1e5 + 5;
bool isPrime[N + 5];
vlli primes;
void sieve(lli MAXN)
{
    for (lli i = 2; i * i <= MAXN; i++)
    {
        if (!isPrime[i])
        {
            for (lli j = i * i; j <= MAXN; j += i)
            {
                isPrime[j] = true;
            }
        }
    }
    for (lli i = 1; i <= MAXN; i++)
    {
        if (!isPrime[i])
        {
            primes.pb(i);
        }
    }
}
void solve()
{
    int d;
    cin >> d;
    int x = *upper_bound(all(primes), d);
    int y = *upper_bound(all(primes), x + d - 1);

    cout << x * y << "\n";
    return;
}
int32_t main()
{
    fastio;
    sieve(100005);
    int t = 1;
    cin >> t;
    while (t--)
    {
        solve();
    }
}