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

class Solution
{
public:
    //mp[0,R] - mp[0,L-1] = 00000
    //mp[0,R] = mp[0,L-1] or mp[0,R] = 00000
    int findTheLongestSubstring(string s)
    {
        unordered_map<char, int> pos;
        pos['a'] = 0;
        pos['e'] = 1;
        pos['i'] = 2;
        pos['o'] = 3;
        pos['u'] = 4;

        int mp[32], mask = 0;
        memset(mp, -1, sizeof(mp));

        int n = (int)s.size();

        int ans = 0;

        for (int i = 0; i < n; i++)
        {
            char c = s[i];

            if (pos.find(c) != pos.end())
                mask ^= (1 << pos[c]);

            if (mask == 0 or mp[mask] != -1)
            {
                int len = i - mp[mask];
                ans = max(ans, len);
            }

            else
                mp[mask] = i;
        }
        return ans;
    }
};
const int mod = 1000000007;

int32_t main()
{
    fastio;
    int t = 1;
    cin >> t;
    while (t--)
    {
        int n;
        cin >> n;
    }
}