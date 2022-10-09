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

//!EDITORIAL
//  Assume that the array of speeds is sorted, i.e. s1≤s2≤⋯≤sn.

// The key observation is that the last running can be assumed to be either s1 or sn. This is because if s1 and sn are both in the prefix of length i, then clearly di=sn−s1, which is the maximum possible value of any discrepancy. Similarly di+1,di+2,…,dn are all equal to sn−s1. This moving either s1 or sn (whichever appears last) to the very end of the array cannot possibly increase the sum of these discrepancies, since they already have the largest possible value.

// If we repeat the previous observation, we deduce that for each i, the prefix of length i in an optimal solution forms a contiguous subarray of the sorted array. Therefore, we may solve the problem through dynamic programming: dp(l,r) represents the minimum possible answer if we solve for the subarray s[l…r]. Clearly dp(x,x)=0, and the transition is given by

// dp(l,r)=sr−sl+min(dp(l+1,r),dp(l,r−1))
// Which corresponds to placing either the smallest or the largest element at the end of the sequence. The final answer is dp(1,n). This allows us to solve the problem in O(n2).

const int MAX = 2e3 + 5;
ll dp[MAX][MAX], a[MAX];

ll getAns(int l, int r)
{
    if (dp[l][r] != -1)
        return dp[l][r];
    if (l == r)
        return 0;
    return dp[l][r] = a[r] - a[l] + min(getAns(l + 1, r), getAns(l, r - 1));
}

int main()
{
    int n;
    cin >> n;

    for (int i = 0; i < n; i++)
        cin >> a[i];

    sort(a, a + n);
    memset(dp, -1, sizeof dp);

    cout << getAns(0, n - 1) << '\n';
}