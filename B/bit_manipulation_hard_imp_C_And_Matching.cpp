/**
 *    author  : amit_dwivedi
 *    created : 27.01.2022 20:12:16
 **/
#include "bits/stdc++.h"
using namespace std;
using ll = int64_t;

#define all(x) begin(x), end(x)
#define bit(x, i) ((1LL << i) & x)
#define len(x) ((int)x.size())
#define out(x) return cout << x << "\n", 0

mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());
int rand(int l, int r)
{
    uniform_int_distribution<int> uid(l, r);
    return uid(rng);
}

int main()
{
    cin.tie(0)->sync_with_stdio(0);
    for (int tt = -1; tt < 0 && cin >> tt, tt--;)
        [&]()
        {
            ll n = 64, k = 14;
            cin >> n >> k;
            // n = rand(2, 10);
            // n = 1ll << n;
            // k = rand(0, n - 1);
            ll mask = n - 1;
            set<pair<int, int>> ans;
            vector<bool> vis(n, false);
            if (k == mask)
            {
                if (n == 4)
                {
                    out(-1);
                }
                ans.insert({mask - 1, mask});
                ans.insert({1, mask - 2});
                ans.insert({0, 2});
                vis[mask] = vis[mask - 1] = vis[mask - 2] = vis[0] = vis[1] = vis[2] = 1;
                for (int i = 0; i < n; i++)
                {
                    if (!vis[i])
                    {
                        ans.insert({i, mask ^ i});
                        vis[i] = vis[mask ^ i] = 1;
                    }
                }
            }
            else
            {
                ans.insert({0, mask ^ k});
                ans.insert({k, mask});
                vis[0] = vis[k] = vis[mask] = vis[mask ^ k] = 1;
                for (int i = 1; i < n - 1; ++i)
                {
                    if (!vis[i])
                    {
                        ans.insert({i, mask ^ i});
                        vis[i] = vis[mask ^ i] = 1;
                    }
                }
            }

            assert(len(ans) == n / 2);
            ll tot = 0;

            for (auto [u, v] : ans)
            {
                cout << u << " " << v << "\n";
                tot += u & v;
                // dbg(u, v, u)
            }
            // dbg(ans);
            // dbg(n, k, tot);
            assert(tot == k);
            return 0;
        }();
    return 0;
}
