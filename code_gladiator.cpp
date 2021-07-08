/*Jazzy and Cricket Balls (100 Marks)
Jazzy is good with bowling but is not good with studies. His mom wants him to focus on studies too and for this she has found an interesting way. She has brought N packets of balls which may or may not have the same number of balls in them. The balls in a packet are arranged in a linear manner and Jazzy wants to play with the balls.


She will give the balls to Jazzy only if he can tell the maximum number of moves required in which he can get to play with all the balls. There are few conditions though:

In one move, Jazzy can divide the number of balls in the packet into an equal number of groups only.
Example: Suppose there are 6 balls in the packet.
Jazzy can divide this packet in 3 ways.

1. Two groups of 3 balls each. (3, 3)
2. Three groups of 2 balls each (2, 2, 2)
3. Six groups of 1 ball each.


Note: Dividing a single group into multiple groups of equal number is considered one move only.


Jazzy can get to play with the balls when they are present as a single unit only and not in any group of size greater than 1. Also, getting to play with a ball is considered a move.

Example: In a group there are 2 balls, then Jazzy cannot play with them until he further divides them into single-single units.


The length of all the packets/groups should always be an integer.


Example:

Number of Packets, N = 1
Number of balls in packet = 6





Jazzy only cares about playing with the balls and needs your help in finding the maximum number of moves. Can you help him?




Input Format
The first line of input consists of the number of packets, N.
The second line of input consists of N space-separated integers representing the number of balls in the packet (length of the packet), Ni

Constraints
1<= N <=100
1<= Ni <=10^12 (1e12)

Output Format
Print the required number of maximum moves to get to play with the balls.

Sample TestCase 1
Input
2
6 1
Output
11
Explanation

For 6 numbers of balls in a packet, 10 moves are required as explained above.

For 1 ball, only 1 move is required.


Total number of moves = 10 + 1 = 11

public class CandidateBackup {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in).useDelimiter("[\\s+]");
        System.out.println(Stream.iterate(0, i -> i + 1).limit(sc.nextInt()).map(i -> groups(sc.nextInt())).reduce(0, Integer::sum));
    }
    static int groups(int x){
        int n = x;
        for(int j=2; j<=n;){
            if(n%j==0 || n==j){
                x+=n=n/j;
                continue;
            }
            j++;
        }
        return x;
    }
}
*/

/* 2nd question ans*/
/*
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
#define fastio ios_base::sync_with_stdio(0), cin.tie(0)
#define re(a, n)   \
    rep(i, n)      \
            cin >> \
        a[i];
using namespace std;
// DEBUG TEMPLATE STARTS HERE//
typedef unsigned long long ull;
typedef long double lld;
// typedef tree<pair<int, int>, null_type, less<pair<int, int>>, rb_tree_tag, tree_order_statistics_node_update > pbds; // find_by_order, order_of_key
void _print(int t) { cerr << t; }
void _print(string t) { cerr << t; }
void _print(char t) { cerr << t; }
void _print(lld t) { cerr << t; }
void _print(double t) { cerr << t; }
void _print(ull t) { cerr << t; }

template <class T, class V>
void _print(pair<T, V> p);
template <class T>
void _print(vector<T> v);
template <class T>
void _print(set<T> v);
template <class T, class V>
void _print(map<T, V> v);
template <class T>
void _print(multiset<T> v);
template <class T, class V>
void _print(pair<T, V> p)
{
    cerr << "{";
    _print(p.ff);
    cerr << ",";
    _print(p.ss);
    cerr << "}";
}
template <class T>
void _print(vector<T> v)
{
    cerr << "[ ";
    for (T i : v)
    {
        _print(i);
        cerr << " ";
    }
    cerr << "]";
}
template <class T>
void _print(set<T> v)
{
    cerr << "[ ";
    for (T i : v)
    {
        _print(i);
        cerr << " ";
    }
    cerr << "]";
}
template <class T>
void _print(multiset<T> v)
{
    cerr << "[ ";
    for (T i : v)
    {
        _print(i);
        cerr << " ";
    }
    cerr << "]";
}
template <class T, class V>
void _print(map<T, V> v)
{
    cerr << "[ ";
    for (auto i : v)
    {
        _print(i);
        cerr << " ";
    }
    cerr << "]";
}
// void _print(pbds v) {cerr << "[ "; for (auto i : v) {_print(i); cerr << " ";} cerr << "]";}
#ifndef ONLINE_JUDGE
#define debug(x...)               \
    cerr << "[" << #x << "] = ["; \
    _print(x);                    \
    cerr << "]" << endl;
#else
#define debug(x...)
#endif
//only for prime m
//DEBUG TEMPLATE ENDS HERE
// void compress(vi &a)
// {
//     //for fenwick tree
//     int n = sz(a);
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
// -----------POLICY BASED DATA STRUCTURES------------------------
// #include <ext/pb_ds/assoc_container.hpp>
// #include <ext/pb_ds/tree_policy.hpp>
// using namespace __gnu_pbds;
// template <class T>
// using ordered_set = tree<T, null_type, less<T>, rb_tree_tag, tree_order_statistics_node_update>;
// template <class K, class V>
// using ordered_map = tree<K, V, less<K>, rb_tree_tag, tree_order_statistics_node_update>;
///---------------Functions---------------------///
template <class T>
T gcd(T a, T b)
{
    if (b == 0)
        return a;
    return gcd(b, a % b);
}
template <class T>
T lcm(T a, T b) { return (a * b) / __gcd(a, b); }
template <class T>
T ceil(T numerator, T denominator) { return (numerator + denominator - 1) / denominator; }
template <class T>
bool isPrime(T N)
{
    for (T i = 2; i * i <= N; ++i)
    {
        if (N % i == 0)
            return false;
    }
    return true;
}
template <class T>
T cbrt(T x)
{
    T lo = 1, hi = min(2000000ll, x);
    while (hi - lo > 1)
    {
        T mid = (lo + hi) / 2;
        if (mid * mid * mid < x)
        {
            lo = mid;
        }
        else
            hi = mid;
    }
    if (hi * hi * hi <= x)
        return hi;
    else
        return lo;
}
template <class T>
T sqrt(T target)
{
    T l = 1, r = target;
    while (r > l + 1)
    {
        T m = (l + r) / 2;
        if (m * m <= target)
            l = m;
        else
            r = m;
    }
    return l;
}
template <class T>
T bin_power(T a, T b, T mod)
{
    T res = 1;
    while (b > 0)
    {
        if (b & 1)
            res = ((res % mod) * (a % mod)) % mod;
        a = ((a % mod) * (a % mod)) % mod;
        b = b >> 1;
    }
    return res;
}
int mod_inv(int a, int b) { return bin_power(a, b - 2, b); }
int mod_add(int a, int b, int m)
{
    a = a % m;
    b = b % m;
    return (((a + b) % m) + m) % m;
}
int mod_mul(int a, int b, int m)
{
    a = a % m;
    b = b % m;
    return (((a * b) % m) + m) % m;
}
int mod_sub(int a, int b, int m)
{
    a = a % m;
    b = b % m;
    return (((a - b) % m) + m) % m;
}
int mod_div(int a, int b, int m)
{
    a = a % m;
    b = b % m;
    return (mod_mul(a, mod_inv(b, m), m) + m) % m;
}
///---------------custom_hash---------------------///
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
// ---------------variables-- ------------------- ///
// const int dx[4] = {-1, 1, 0, 0};
// const int dy[4] = {0, 0, -1, 1};
// int XX[] = {-1, -1, -1, 0, 0, 1, 1, 1};
// int YY[] = {-1, 0, 1, -1, 1, -1, 0, 1};
// If you do not sacrifice for what you want, What you want becomes sacrifice.

#define int long long int
const int INF = 1e15;
const int N = 5e4 + 5;

vector<pair<int, int>> adj[N];
int dist[N];
// int actual_dist[N];
bool vis[N];
int n, m;
void Dijkstra()
{
    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
    //min time to reach a node
    // dist[1] = 0;
    // pq.push({0, 1}); //{node,dist}
    // while (!pq.empty())
    // {
    //     int node = pq.top().ss;
    //     int node_d = pq.top().ff;
    //     pq.pop();
    //     if (vis[node])
    //         continue;
    //     vis[node] = true;
    //     for (auto e : adj[node])
    //     {
    //         if (dist[e.ff] > e.ss + node_d)
    //         {
    //             dist[e.ff] = e.ss + node_d;
    //             pq.push({dist[e.ff], e.ff});
    //         }
    //     }
    // }
    // if (dist[n] >= INF)
    // {
    //     prln("NOT POSSIBLE");
    //     exit(0);
    // }

    // 2nd dijkstra for actual dist

    // rep1(i, n) vis[i] = false, actual_dist[i] = dist[i];
    dist[1] = 0;
    pq.push({0, 1}); //{node,dist}
    while (pq.size())
    {
        int node = pq.top().ss;
        int node_d = pq.top().ff;
        pq.pop();
        if (vis[node])
            continue;
        vis[node] = true;
        for (auto e : adj[node])
        {
            int diff = e.ss - node_d;
            if (diff < 0)
                diff = 0;

            if (dist[e.ff] > node_d + diff)
            {
                dist[e.ff] = node_d + diff;
                pq.push({dist[e.ff], e.ff});
            }
        }
    }
    return;
    // 0 30 10 30 60

    //  priority_queue<pair<int, pii>, vector<pair<int, pii>>, greater<pair<int, pii>>> pq;

    // dist[1] = 0;
    // pq.push({0, {1, 0}}); //cur_node_dist,cur_node,prev_edge_cost
    // while (!pq.empty())
    // {
    //     int node = pq.top().ss.ff;
    //     int node_d = pq.top().ff;
    //     int prev_edge_cost = pq.top().ss.ss;
    //     pq.pop();
    //     if (vis[node])
    //         continue;
    //     vis[node] = true;
    //     for (auto e : adj[node])
    //     {
    //         int edge_diff = e.ss - prev_edge_cost;
    //         if (edge_diff < 0)
    //             edge_diff = 0;
    //         if (dist[e.ff] > node_d + edge_diff)
    //         {
    //             dist[e.ff] = node_d + edge_diff;
    //             pq.push({dist[e.ff], {e.ff, e.ss}});
    //         }
    //     }
    // }
}
void solve()
{
    cin >> n >> m;
    for (int i = 1; i <= m; i++)
    {
        int a, b, w;
        cin >> a >> b >> w;
        adj[a].push_back({b, w});
    }
    for (int i = 1; i <= n; ++i)
        dist[i] = INF;

    Dijkstra();
    if (dist[n] >= INF)
        prln("NOT POSSIBLE");
    else
        prln(dist[n]);
    return;
}
int32_t main()
{
    fastio;
    solve();
}
*/

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
#define fastio ios_base::sync_with_stdio(0), cin.tie(0)
#define re(a, n)   \
    rep(i, n)      \
            cin >> \
        a[i];
using namespace std;
#define int long long int

const int N = 105;
int n, a[N];
const int sz = 1e6 + 5;
bool isPrime[sz];
vi primes;
void sieve(int MAXN)
{
    for (int i = 2; i * i <= MAXN; i++)
        if (!isPrime[i])
            for (int j = i * i; j <= MAXN; j += i)
                isPrime[j] = true;

    for (int i = 2; i <= MAXN; i++)
        if (!isPrime[i])
            primes.pb(i);
}

int getAns(int num)
{
    if (num == 1)
        return 1;
    int ans = num, x = num;

    for (auto prime : primes)
    {
        if (prime > x or num == 1)
            break;
        if (num % prime == 0)
        {
            while (num % prime == 0)
            {
                num /= prime;
                ans += num;
            }
        }
    }
    if (num == 1)
        return ans;
    return ans + num + 1;
}
int32_t main()
{
    fastio;
    sieve(1e6);
    int ans = 0;
    cin >> n;
    rep(i, n)
    {
        cin >> a[i];
        ans += getAns(a[i]);
        // cerr << getAns(a[i]) << sp;
    }
    prln(ans);
}
