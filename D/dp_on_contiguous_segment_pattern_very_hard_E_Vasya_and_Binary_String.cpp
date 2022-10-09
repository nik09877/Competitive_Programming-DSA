#pragma GCC optimize("Ofast")
#pragma GCC target("avx,avx2,fma")
#pragma GCC optimization("unroll-loops")
#include <bits/stdc++.h>
#define rep(i, n) for (int i = 0; i < n; i++)
#define rrep(i, a, b) for (int i = a; i >= b; i--)
#define rep1(i, n) for (int i = 1; i <= n; i++)
#define fo(i, a, n) for (int i = a; i <= n; i++)
#define mkp make_pair
#define pb emplace_back
#define ff first
#define ss second
#define ll long long
#define ii int, int
#define pii pair<int, int>
#define vi vector<int>
#define vvi vector<vector<int>>
#define vpii vector<pair<int, int>>
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
#define TIME cerr << "Time Taken:" << (float)clock() / CLOCKS_PER_SEC * 1000 << "ms" << endl
#define fastio ios_base::sync_with_stdio(0), cin.tie(0)
#define re(a, n)   \
    rep(i, n)      \
            cin >> \
        a[i];
using namespace std;
#define int long long int

int n, cost_of_len[101], dp[101][101][101], max_profit[101];
vi group_size;

//when you touch a group you are doing it so that you can merge another group with its next one ,so you should completely get rid of it anyway you want ,so you can use rod cutting algo and if u dont touch a group that means you want to merge it with some other group to maximize your profit

//dp[i][j][extra_part] denotes max profit by removing [i,j]group_size` such that for ith group there are some extra part of another same group from left side

int getAns(int i, int j, int extra_part)
{
    //if there is no group max profit is 0
    if (i > j)
        return 0;
    if (dp[i][j][extra_part] != -1)
        return dp[i][j][extra_part];

    //you can always destroy the first group and move on without leaving any extra part for the nexxt group_size`
    int ans = max_profit[group_size[i] + extra_part] + getAns(i + 1, j, 0);

    //if you want to merge this group with some next similar group
    for (int next_group = i + 2; next_group <= j; next_group += 2)
    {
        //get the answer for the [middle part] and [merge the ith group with the next_group] and get the answer
        int temp_ans = getAns(i + 1, next_group - 1, 0) + getAns(next_group, j, extra_part + group_size[i]);
        ans = max(ans, temp_ans);
    }
    return dp[i][j][extra_part] = ans;
}

//rod cutting algo
// to remove a current group of size k what is the max profit we can get
void calc_max_profit()
{
    memset(max_profit, 0, sizeof(max_profit));
    fo(i, 1, n)
    {
        for (int cut_part = 1; cut_part <= i; cut_part++)
        {
            int remaining_part = i - cut_part;

            max_profit[i] = max(max_profit[i], cost_of_len[cut_part] + max_profit[remaining_part]);
        }
    }
}
void solve()
{
    string s;
    cin >> n >> s;
    rep1(i, n) cin >> cost_of_len[i];
    calc_max_profit();
    memset(dp, -1, sizeof(dp));

    //make group_size` of 1's and 0's
    int grp_size = 1;
    fo(i, 1, sz(s) - 1)
    {
        if (s[i] == s[i - 1])
            grp_size++;
        else
        {
            group_size.pb(grp_size);
            grp_size = 1;
        }
    }
    group_size.pb(grp_size);
    int ans = getAns(0, sz(group_size) - 1, 0);
    prln(ans);
    return;
}
int32_t main()
{
    fastio;
    solve();
}

// if there are groups of different colors rather than only 0 and 1
class Solution
{
public:
    int32_t n, cost_of_len[101], dp[101][101][101], max_profit[101];
    vpii group_size; //{grp_size,color}

    //when you touch a group you are doing it so that you can merge another group with its next one ,so you should completely get rid of it anyway you want ,so you can use rod cutting algo and if u dont touch a group that means you want to merge it with some other group to maximize your profit

    //dp[i][j][extra_part] denotes max profit by removing [i,j]group_size` such that for ith group there are some extra part of another same group from left side

    int32_t getAns(int32_t i, int32_t j, int32_t extra_part)
    {
        //if there is no group max profit is 0
        if (i > j)
            return 0;

        if (dp[i][j][extra_part] != -1)
            return dp[i][j][extra_part];

        //you can always destroy the first group and move on without leaving any extra part for the nexxt group_size`
        int32_t ans = max_profit[group_size[i].ff + extra_part] + getAns(i + 1, j, 0);

        //if you want to merge this group with some next similar group
        for (int32_t next_group = i + 2; next_group <= j; next_group++)
        {
            if (group_size[i].ss == group_size[next_group].ss)
            {

                //get the answer for the [middle part] and [merge the ith group with the next_group] and get the answer

                int32_t temp_ans = getAns(i + 1, next_group - 1, 0) + getAns(next_group, j, extra_part + group_size[i].ff);

                ans = max(ans, temp_ans);
            }
        }
        return dp[i][j][extra_part] = ans;
    }

    //rod cutting algo
    // to remove a current group of size k what is the max profit we can get
    void calc_max_profit()
    {
        memset(max_profit, 0, sizeof(max_profit));
        fo(i, 1, n)
        {
            for (int32_t cut_part = 1; cut_part <= i; cut_part++)
            {
                int32_t remaining_part = i - cut_part;

                max_profit[i] = max(max_profit[i], cost_of_len[cut_part] + max_profit[remaining_part]);
            }
        }
    }

    int removeBoxes(vector<int> &boxes)
    {
        n = sz(boxes);
        rep1(i, n) cost_of_len[i] = i * i;
        calc_max_profit();
        memset(dp, -1, sizeof(dp));

        //make group_size` of 1's and 0's
        int32_t grp_size = 1;
        int32_t grp_color = boxes[0];
        fo(i, 1, sz(boxes) - 1)
        {
            if (boxes[i] == boxes[i - 1])
                grp_size++;
            else
            {
                group_size.push_back({grp_size, grp_color});
                grp_size = 1;
                grp_color = boxes[i];
            }
        }
        group_size.push_back({grp_size, grp_color});
        int32_t ans = getAns(0, sz(group_size) - 1, 0);
        return ans;
    }
};