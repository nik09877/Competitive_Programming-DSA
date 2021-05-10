#include <bits/stdc++.h>
#include <stdio.h>
#define rep(i, n) for (int i = 0; i < n; i++)
#define rrep(i, a, b) for (int i = a; i >= b; i--)
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
#define sz(x) ((int)(x).size())
#define fastio ios_base::sync_with_stdio(0), cout.tie(0), cin.tie(0)
#define read(a)       \
    for (auto &i : a) \
        cin >> i;
using namespace std;
const int mod = 1000000007;
struct custom_hash
{
    static uint64_t splitmix64(uint64_t x)
    {
        x += 0x9e3779b97f4a7c15;
        x = (x ^ (x >> 30)) * 0xbf58476d1ce4e5b9;
        x = (x ^ (x >> 27)) * 0x94d049bb133111eb;
        return x ^ (x >> 31);
    }

    size_t operator()(uint64_t x) const
    {
        static const uint64_t FIXED_RANDOM = chrono::steady_clock::now().time_since_epoch().count();
        return splitmix64(x + FIXED_RANDOM);
    }
    // umap<lli, lli, custom_hash> mp;
};

const int N = 1e5 + 5;
bool isPrime[N + 5];
vi primes;
void sieve(int MAXN)
{
    for (int i = 2; i * i <= MAXN; i++)
    {
        if (!isPrime[i])
        {
            for (int j = i * i; j <= MAXN; j += i)
            {
                isPrime[j] = true;
            }
        }
    }
    for (int i = 2; i <= MAXN; i++)
    {
        if (!isPrime[i])
        {
            primes.pb(i);
        }
    }
}
char ans[1005], s[1005];
void solve()
{
    umap<char, int, custom_hash> mp, vis;
    int n, idx = 1;
    string temp;
    cin >> temp;
    n = sz(temp);

    for (auto c : temp)
    {
        mp[c]++, s[idx] = ans[idx] = c, idx++;
    }

    sieve(n);
    for (int p : primes)
    {
        vis[p] = 1;
        mp[s[p]]--;
        ans[p] = s[p];
        if (n == p)
        {
            vis[p] = 0;
        }
        for (int i = 1; i <= n / p; i++)
        {
            if (i * p == p)
            {
                continue;
            }
            if (vis[i * p] == 1 && ans[i * p] != s[p])
            {
                cout << "NO";
                return;
            }
            else
            {
                vis[i * p] = 1;
                if (s[p] != ans[i * p])
                {
                    if (mp[s[p]] == 0)
                    {
                        cout << "NO\n";
                        return;
                    }
                    ans[i * p] = s[p];
                    mp[s[p]]--;
                }
            }
        }
    }
    for (int i = 1; i <= n; i++)
    {
        if (vis[i] == 0)
        {
            for (auto p : mp)
            {
                if (p.ss != 0)
                {
                    ans[i] = p.ff, p.ss--;
                }
            }
        }
    }
    cout << "YES\n";
    for (int i = 1; i <= n; i++)
    {
        cout << ans[i];
    }
    return;
}
int32_t main()
{
    fastio;
    int t = 1;
    // cin >> t;
    while (t--)
    {
        solve();
    }
}