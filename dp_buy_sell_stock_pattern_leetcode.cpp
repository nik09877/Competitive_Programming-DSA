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
const int mod = 1000000007;

class Solution
{
public:
    //  Best Time to Buy and Sell Stock - I
    int maxProfit(vector<int> &a)
    {
        int n = a.size();
        vector<int> mx(n, 0);
        mx[n - 1] = a[n - 1];
        for (int i = n - 2; i >= 0; i--)
        {
            mx[i] = max(mx[i + 1], a[i]);
        }
        int mx_prof = 0;
        for (int i = 0; i < n - 1; i++)
        {
            int cur = 0;
            cur -= a[i];
            cur += mx[i + 1];
            mx_prof = max(mx_prof, cur);
        }
        return mx_prof;
    }
    //  Best Time to Buy and Sell Stock - II
    //idea is to buy on local minima and sell on local maxima
    int maxProfit(vector<int> &prices)
    {
        int profit = 0;
        for (int i = 1; i < prices.size(); i++)
        {
            if (prices[i] > prices[i - 1])
            {
                profit += (prices[i] - prices[i - 1]);
            }
        }
        return profit;
    }
    // Best Time to Buy and Sell Stock with Transaction Fee
    int maxProfit(vector<int> &a, int fee)
    {
        int n = a.size();

        // dp to store the profit when someone starts trading at day i
        // and first thing can be done is to Buy
        vector<int> dpBuy(n, -1);

        // dp to store the profit when someone starts trading at day i
        // and first thing can be done is to Sell
        vector<int> dpSell(n, -1);
        // when on last day so you canot sell so you will not buy
        dpBuy[n - 1] = 0;

        // when on last day and you cannot buy and you can only sell
        dpSell[n - 1] = a[n - 1];

        // do pull dp from last to first
        for (int i = n - 2; i >= 0; i--)
        {
            dpBuy[i] = max(dpBuy[i + 1], -a[i] - fee + dpSell[i + 1]);
            dpSell[i] = max(dpSell[i + 1], a[i] + dpBuy[i + 1]);
        }
        return dpBuy[0];
    }
    // Best Time to Buy and Sell Stock with Cooldown (if u ssell on ith day u can't buy on the next day)
    int maxProfit(vector<int> &a)
    {
        int n = a.size();
        vector<int> dp_buy(n + 1, 0), dp_sell(n + 1, 0);

        dp_buy[n - 1] = 0;
        dp_sell[n - 1] = a[n - 1];

        for (int i = n - 2; i >= 0; i--)
        {
            dp_buy[i] = max(dp_buy[i + 1], -a[i] + dp_sell[i + 1]);
            dp_sell[i] = max(dp_sell[i + 1], a[i] + dp_buy[i + 2]);
        }
        return dp_buy[0];
    }
    //  Best Time to Buy and Sell Stock III (HARD) (atmost 2)
    int getAns(int i, bool bought_prev, int k, vector<int> &a, vector<vector<int>> &dp_buy, vector<vector<int>> &dp_sell, int &n)
    {
        //it's time to buy
        if (not bought_prev)
        {
            if (dp_buy[i][k] != -1)
                return dp_buy[i][k];
            //if it's the last element or we have already bought 2 items we can't buy this item
            if (i == n - 1 or k == 0)
                return 0;
            return dp_buy[i][k] = max(-a[i] + getAns(i + 1, true, k - 1, a, dp_buy, dp_sell, n), getAns(i + 1, false, k, a, dp_buy, dp_sell, n));
        }

        //it's time to sell
        else
        {
            if (dp_sell[i][k] != -1)
                return dp_sell[i][k];
            if (i == n - 1)
                return a[n - 1];

            return dp_sell[i][k] = max(a[i] + getAns(i + 1, false, k, a, dp_buy, dp_sell, n), getAns(i + 1, true, k, a, dp_buy, dp_sell, n));
        }
    }
    int maxProfit(vector<int> &a)
    {
        int n = a.size();
        vector<vector<int>> dp_buy(n, vector<int>(3, -1)), dp_sell(n, vector<int>(3, -1));
        int ans = getAns(0, false, 2, a, dp_buy, dp_sell, n);
        return ans;
    }
    // Best Time to Buy and Sell Stock IV (Hard) (at most k)
    int getAns(int i, bool bought_prev, int k, vector<int> &a, vector<vector<int>> &dp_buy, vector<vector<int>> &dp_sell, int &n)
    {
        //it's time to buy
        if (not bought_prev)
        {
            if (dp_buy[i][k] != -1)
                return dp_buy[i][k];
            //if it's the last element or we have already bought 2 items we can't buy this item
            if (i == n - 1 or k == 0)
                return 0;
            return dp_buy[i][k] = max(-a[i] + getAns(i + 1, true, k - 1, a, dp_buy, dp_sell, n), getAns(i + 1, false, k, a, dp_buy, dp_sell, n));
        }

        //it's time to sell
        else
        {
            if (dp_sell[i][k] != -1)
                return dp_sell[i][k];
            if (i == n - 1)
                return a[n - 1];

            return dp_sell[i][k] = max(a[i] + getAns(i + 1, false, k, a, dp_buy, dp_sell, n), getAns(i + 1, true, k, a, dp_buy, dp_sell, n));
        }
    }
    int maxProfit(int k, vector<int> &a)
    {
        int n = a.size();
        if (n <= 1)
            return 0;
        vector<vector<int>> dp_buy(n, vector<int>(k + 2, -1)), dp_sell(n, vector<int>(k + 2, -1));
        int ans = getAns(0, false, k, a, dp_buy, dp_sell, n);
        return ans;
    }
    //House Robbery
    int dp[101][2];
    int getAns(int i, int prev_taken, int &n, vector<int> &a)
    {
        if (i == n)
            return 0;
        if (dp[i][prev_taken] != -1)
            return dp[i][prev_taken];

        int x = 0, y = 0;
        if (not prev_taken)
        {
            x = a[i] + getAns(i + 1, 1, n, a);
        }
        y = getAns(i + 1, 0, n, a);

        return dp[i][prev_taken] = max(x, y);
    }
    int rob(vector<int> &a)
    {
        memset(dp, -1, sizeof dp);
        int n = a.size();
        int ans = getAns(0, 0, n, a);
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