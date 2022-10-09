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

// ///---------------Functions---------------------///
// int gcd(int a, int b)
// {
//     if (a == 0)
//         return b;
//     return gcd(b % a, a);
// }
// int lcm(int a, int b)
// {
//     return (a * b) / __gcd(a, b);
// }
// int max(int a, int b)
// {
//     if (a > b)
//         return a;
//     else
//         return b;
// }
// int min(int a, int b)
// {
//     if (a < b)
//         return a;
//     else
//         return b;
// }
// int ceil(int numerator, int denominator)
// {
//     return (numerator + denominator - 1) / denominator;
// }
// bool isPrime(int N)
// {
//     for (int i = 2; i * i <= N; ++i)
//     {
//         if (N % i == 0)
//             return false;
//     }
//     return true;
// }
// int cbrt(int x) //cuberoot
// {
//     int lo = 1, hi = min(2000000ll, x);
//     while (hi - lo > 1)
//     {
//         int mid = (lo + hi) / 2;
//         if (mid * mid * mid < x)
//         {
//             lo = mid;
//         }
//         else
//             hi = mid;
//     }
//     if (hi * hi * hi <= x)
//         return hi;
//     else
//         return lo;
// }
// lli sqrt(lli target)
// {
//     lli l = 1, r = target;
//     while (r > l + 1)
//     {
//         lli m = (l + r) / 2;
//         if (m * m <= target)
//             l = m;
//         else
//             r = m;
//     }
//     return l;
// }
// void compress(vi &a)
// {
//     //for fenwick tree
//     int n = (int)a.size();
//     map<ii> mpp, back;
//     int idx = 1;
//     rep(i, n)
//     {
//         if (mpp.find(a[i]) == mpp.end())
//         {
//             mpp.insert({a[i], idx});
//             back.insert({idx, a[i]}); //to get back original values
//             idx++;
//         }
//     }
//     rep(i, n)
//     {
//         a[i] = mpp[a[i]];
//     }
// }
// ///---------------custom_hash---------------------///
// class chash
// {
// public:
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

// ///---------------variables---------------------///
// const int dx[4] = {-1, 1, 0, 0};
// const int dy[4] = {0, 0, -1, 1};
// int XX[] = {-1, -1, -1, 0, 0, 1, 1, 1};
// int YY[] = {-1, 0, 1, -1, 1, -1, 0, 1};
const int mod = 1000000007;

// The problem can be solved using standard Dijkstra algorithm with slight modifications.

//     In priority queue for each vertex a vector corresponding to {cost, time, vertex} is stored.
//     The priority queue will be a min-heap, the vectors will be arranged first by cost and then by time.
//     Source vertex (0) will be push into min-heap first.
//     Follow the standard dijkstra by popping vertices and traverse the connected edges.
//     The difference here will be that only those edges will be traversed which will not cause the time to exceed maxTime.
//     Also a new entry will be pushed to heap if the cost or time of vertex will reduce.
//     At the end return the cost of destination vertex(dest).

// https://leetcode.com/problems/minimum-cost-to-reach-destination-in-time/discuss/1328953/C%2B%2B-Solution-or-Dijkstra's-Algorithm
class Solution
{
public:
    vvi g[1001];
    int cost[1001], time[1001];

    int dijkstra(int start, int dest, int mx_time)
    {

        priority_queue<vi, vvi, greater<vi>> pq; // {min_cost_to_reach_cur_node,time_to_reach,cur_node}
        pq.push({cost[start], 0, 0});

        while (pq.size())
        {
            auto cur_state = pq.top();
            pq.pop();
            int node = cur_state[2];
            int cost_of_node = cur_state[0];
            int time_to_reach = cur_state[1];

            for (auto child : g[node])
            {
                int child_node = child[0];
                int edge_wt = child[1];
                int fee = child[2];

                if (time_to_reach + edge_wt <= mx_time)
                {
                    if (cost_of_node + fee < cost[child_node])
                    {
                        cost[child_node] = cost_of_node + fee;
                        time[child_node] = time_to_reach + edge_wt;
                        pq.push({cost[child_node], time[child_node], child_node});
                    }

                    else if (time_to_reach + edge_wt < time[child_node])
                    {
                        time[child_node] = time_to_reach + edge_wt;
                        pq.push({cost_of_node + fee, time[child_node], child_node});
                    }
                }
            }
        }

        return cost[dest];
    }
    int minCost(int maxTime, vector<vector<int>> &edges, vector<int> &passingFees)
    {

        int n = sz(passingFees);

        rep(i, n)
        {
            cost[i] = time[i] = INT_MAX;
        }

        for (auto e : edges)
        {
            int x, y, wt;
            x = e[0], y = e[1], wt = e[2];
            g[x].push_back({y, wt, passingFees[y]});
            g[y].push_back({x, wt, passingFees[x]});
        }

        cost[0] = passingFees[0];
        time[0] = 0;

        int ans = dijkstra(0, n - 1, maxTime);

        if (ans == INT_MAX)
        {
            return -1;
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