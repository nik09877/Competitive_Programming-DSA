/* Priyansh Agarwal*/

#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>

using namespace std;
using namespace chrono;
using namespace __gnu_pbds;

#define fastio()                      \
    ios_base::sync_with_stdio(false); \
    cin.tie(NULL);                    \
    cout.tie(NULL)
#define MOD 1000000007
#define MOD1 998244353
#define INF 1e18
#define nline "\n"
#define pb push_back
#define ppb pop_back
#define mp make_pair
#define ff first
#define ss second
#define PI 3.141592653589793238462
#define set_bits __builtin_popcountll
#define sz(x) ((int)(x).size())
#define all(x) (x).begin(), (x).end()

#ifdef Priyansh31dec
#define debug(x)       \
    cerr << #x << " "; \
    _print(x);         \
    cerr << endl;
#else
#define debug(x) ;
#endif

void solve()
{
    int t;
    cin >> t;
    while (t--)
    {
        int n, m;
        cin >> n >> m;
        map<string, pair<pair<int, int>, int>> av;
        vector<string> grid(n);
        for (int i = 0; i < n; i++)
        {
            cin >> grid[i];
            for (int j = 0; j <= m - 2; j++)
            {
                string here = "";
                here += grid[i][j];
                here += grid[i][j + 1];
                av[here] = {{j, j + 1}, i};
            }
            for (int j = 0; j <= m - 3; j++)
            {
                string here = "";
                here += grid[i][j];
                here += grid[i][j + 1];
                here += grid[i][j + 2];
                av[here] = {{j, j + 2}, i};
            }
        }
        // bigger length can be divided into length of 2 and 3 and concatenated
        //  dp[i] denotes if it is possible to get s[i....m] as segments of other strings
        //  as well as it stores the break point ie of length 2 or 3.
        vector<pair<bool, int>> dp(m + 1, {false, -1});
        dp[m].ff = true; // if there is no string
        string s;
        cin >> s;
        if (sz(s) == 1)
        {
            cout << -1 << nline;
            continue;
        }

        for (int j = m - 2; j >= 0; j--)
        {
            // length 2
            if (j + 2 <= m)
            {
                string here = "";
                here += s[j];
                here += s[j + 1];
                if (av.find(here) != av.end() && dp[j + 2].ff)
                {
                    dp[j] = {true, 2};
                }
            }
            // length 3
            if (j + 3 <= m && !dp[j].ff)
            {
                string here = "";
                here += s[j];
                here += s[j + 1];
                here += s[j + 2];
                if (av.find(here) != av.end() && dp[j + 3].ff)
                {
                    dp[j] = {true, 3};
                }
            }
        }
        vector<pair<pair<int, int>, int>> ans;
        if (dp[0].ff)
        {
            int current = 0;
            while (current < m)
            {
                string here = "";
                here += s[current];
                here += s[current + 1];
                if (dp[current].ss == 3)
                    here += s[current + 2];
                ans.pb(av[here]);
                current += dp[current].ss;
            }
            cout << sz(ans) << nline;
            for (auto i : ans)
            {
                cout << i.ff.ff + 1 << " " << i.ff.ss + 1 << " " << i.ss + 1 << nline;
            }
        }
        else
        {
            cout << -1 << nline;
        }
    }
}
int main()
{
#ifdef Priyansh31dec
    freopen("Error.txt", "w", stderr);
#endif
    fastio();
    auto start1 = high_resolution_clock::now();
    solve();
    auto stop1 = high_resolution_clock::now();
    auto duration = duration_cast<microseconds>(stop1 - start1);
#ifdef Priyansh31dec
    cerr << "Time: " << duration.count() / 1000 << endl;
#endif
}