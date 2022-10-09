#include <bits/stdc++.h>
#define rep(i, n) for (int i = 0; i < n; i++)
#define rrep(i, n) for (int i = n - 1; i >= 0; i--)
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
#define pi pair<int, int>
#define vi vector<int>
#define vvi vector<vector<int>>
#define vlli vector<long long int>
#define vpi vector<pair<int, int>>
#define vvlli vector<vector<long long int>>
#define mod 1000000007
#define endl '\n'
#define dsort(v) sort(v.begin(), v.end(), greater<int>())
#define asort(v) sort(v.begin(), v.end())
#define uniq(v) v.erase(unique(v.begin(), v.end()), v.end())
#define all(v) v.begin(), v.end()
#define umap unordered_map
#define uset unordered_set
#define fastio ios_base::sync_with_stdio(false), cout.tie(NULL), cin.tie(NULL)
using namespace std;
class Solution
{
public:
    int maxSubarraySumCircular(vector<int> &a)
    {
        int max_ans = INT_MIN, min_ans = INT_MAX, curr_mx = 0, curr_mn = 0, sum = 0;
        for (int x : a)
        {
            sum += x;

            curr_mx += x;
            max_ans = max(max_ans, curr_mx);
            curr_mx = max(curr_mx, 0);

            curr_mn += x;
            min_ans = min(min_ans, curr_mn);
            curr_mn = min(curr_mn, 0);
        }
        if (min_ans == sum)
            return max_ans; //if all items are negative

        return max(max_ans, sum - min_ans);
    }
};
int32_t main()
{
    fastio;
    lli n, x;
    cin >> n;
    vlli v;
    repll(i, 0, n - 1)
    {
        cin >> x;
        v.pb(x);
    }
    //KADANE'S ALGO
    lli sum = 0, ans = LONG_MIN;
    for (auto x : v)
    {
        sum += x;
        ans = max(ans, sum);
        sum = max(sum, (long long int)0);
    }
    cout << ans;
}
