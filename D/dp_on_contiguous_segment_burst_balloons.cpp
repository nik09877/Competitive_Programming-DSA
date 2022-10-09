#pragma GCC optimize("Ofast")
#pragma GCC target("avx,avx2,fma")
#pragma GCC optimization("unroll-loops")
#include <bits/stdc++.h>
using namespace std;
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

// I saw multiple solutions on the discussions forum and was not able to figure out what they were trying to explain. So, I came up with solution myself and will try to explain it in the simplest way. If you are clear with the subproblems and are just confused with the implementation, you can jump directly to the diagram below.

// Bruteforce: Generate all permutations for the ordering of balloons and check which permutation yields the best profit. But it will take O(n!) time.

// DP Solution: For a DP solution to exist, we need to define the subproblems. Let's define the problem first as:

// solve(nums, i, j)

// by which I mean that we need to burst balloons starting from index i to index j. At the beginning, they'll be 0, nums.size() -1 respectively. Let's suppose we burst the kth balloon in the first chance. We will get nums[k-1] * nums[k] * nums[k+1] coins. Now let's define the subproblems as:

// solve(nums, i, k - 1) , solve(nums, k + 1, j)

// As the balloon k is already burst, we solve the subproblems from i to k -1 and k + 1 to j. But wait, what's going wrong here? The subproblem solve(nums, i, k - 1) and solve(nums, k + 1, j) are not independent since after bursting kth balloon, balloon k - 1 and k + 1 have become adjacent and they will need each other in order to calculate the profit.

// So, as we saw that if we choose the kth balloon to be the first one to be burst, we can't make the subproblems independent. Let's try the other way round. We choose the kth balloon as the last one to be burst. Now the subproblems will become independent since (k - 1)th balloon and (k + 1)th balloon won't need each other in order to calculate the answer. (Try it out using pen and paper).

// Now for each k starting from i to j, we choose the kth balloon to be the last one to be burst and calculate the profit by solving the subproblems recursively. Whichever choice of k gives us the best answer, we store it and return.
// Important point to be noted here is that the balloons in the range (i, k - 1) and (k + 1, j) will be burst BEFORE kth balloon. So, when we burst the kth balloon, the profit will be nums[i - 1] * nums[k] * nums[j + 1] PROVIDED that index i - 1 and j + 1 are valid.

class Solution
{
public:
    int maxCoins(vector<int> &a)
    {
        int n = a.size();
        a.insert(a.begin(), 1);
        a.insert(a.end(), 1);

        // dp[i][j] is the maximum # of coins that can be obtained
        // by popping balloons only in the range [i,j]

        vvi dp(a.size(), vector<int>(a.size(), 0));

        // build up from shorter ranges to longer ranges

        for (int len = 1; len <= n; ++len)
        {

            for (int start = 1; start <= n - len + 1; ++start)
            {

                int end = start + len - 1;

                // calculate the max # of coins that can be obtained by
                // popping balloons only in the range [start,end].
                // consider all possible choices of final balloon to pop

                int bestCoins = 0;

                for (int final = start; final <= end; ++final)
                {

                    int coins = dp[start][final - 1] + dp[final + 1][end]; // coins from popping subranges

                    coins += a[start - 1] * a[final] * a[end + 1]; // coins from final pop

                    if (coins > bestCoins)
                        bestCoins = coins;
                }
                dp[start][end] = bestCoins;
            }
        }
        return dp[1][n];
    }
};