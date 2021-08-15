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
    //keep in mind even and odd case
    //mask[0,R] = 0 or power of 2
    //mask[0,R]-mask[0,L-1] = 0 (even case)
    /*
    Update the answer if:
    a. We have seen similar mask before.
    b. We have seen a mask such that it differs from the current mask by one bit     being different.
    c. update mask pos to minimum ie dp[mask]=min(dp[mask],i)
    */
    int longestAwesome(string s)
    {
        int mask = 0, ans = 0, n = s.size();
        //initialized with n because i dont want to check everytime if mask existed or not to update answer,if mask does not exist ,then our current answer will be -ve ,so it wont affect our answer
        vector<int> dp(1 << 11, n);
        dp[0] = -1;

        for (int i = 0; i < n; i++)
        {
            int pos = s[i] - '0';
            mask ^= (1 << pos);
            ans = max(ans, i - dp[mask]);

            for (int j = 0; j < 10; j++)
            {
                int new_mask = mask ^ (1 << j);
                ans = max(ans, i - dp[new_mask]);
            }

            //update pos of mask to min pos
            dp[mask] = min(dp[mask], i);
        }

        return ans;
    }
};

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