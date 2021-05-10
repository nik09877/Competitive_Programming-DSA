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
// struct custom_hash
// {
//     static uint64_t splitmix64(uint64_t x)
//     {
//         x += 0x9e3779b97f4a7c15;
//         x = (x ^ (x >> 30)) * 0xbf58476d1ce4e5b9;
//         x = (x ^ (x >> 27)) * 0x94d049bb133111eb;
//         return x ^ (x >> 31);
//     }

//     size_t operator()(uint64_t x) const
//     {
//         static const uint64_t FIXED_RANDOM = chrono::steady_clock::now().time_since_epoch().count();
//         return splitmix64(x + FIXED_RANDOM);
//     }
//     // umap<lli, lli, custom_hash> mp;
// };
void howSum(int target, vi &nums)
{
    //O(n*m)space
    // vi ans[target + 1];
    // vector<bool> dp(target + 1, false);
    // dp[0] = true;
    // for (int i = 0; i <= target; i++)
    // {
    //     if (dp[i] == true)
    //     {
    //         for (int num : nums)
    //         {
    //             if (i + num <= target)
    //             {
    //                 dp[i + num] = true;
    //                 ans[i + num] = ans[i];
    //                 ans[i + num].push_back(num);
    //             }
    //         }
    //     }
    // }
    // if (dp[target])
    // {
    //     for (int num : ans[target])
    //     {
    //         cout << num << sp;
    //     }
    //     cout << endl;
    // }
    // else
    // {
    //     cout << -1 << endl;
    // }
    vi prev(target + 1, 0);
    prev[0] = 1;
    for (int i = 0; i <= target; i++)
    {
        if (prev[i])
        {
            for (int num : nums)
            {
                if (i + num <= target)
                {
                    prev[i + num] = num;
                }
            }
        }
    }
    if (prev[target])
    {
        int cur = target;
        while (cur > 0)
        {
            cout << prev[cur] << sp;
            cur -= prev[cur];
        }
        cout << endl;
    }
    else
        cout << -1 << endl;

    // rep(i, target + 1) cout << prev[i] << sp;
    // cout << endl;
}
void solve()
{
    int n, target;
    cin >> n >> target;
    vi nums(n);
    rep(i, n) { cin >> nums[i]; }
    howSum(target, nums);
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