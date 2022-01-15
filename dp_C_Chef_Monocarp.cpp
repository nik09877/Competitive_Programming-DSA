// #include <bits/stdc++.h>
// using namespace std;

// #define INF 1234567890
// #define ll long long

// int T;
// int N;
// int A[202], dp[202][404];

// // Sort the dishes in the non-decreasing order of their optimal time. I claim that there is an optimal answer such that the times T for each dish go in the increasing order. That's not too hard to prove (something along the lines of if there are two dishes i and j such that ti<tj and Ti>Tj, then |ti−Ti|+|tj−Tj| is always greater than |ti−Tj|+|tj−Ti|).

// // So we can use dynamic programming to solve the task. Let dp[i][T] be the minimum total unpleasant value if i dishes are processed and the current minute is T. For the transitions you can either put out the current dish i at the current minute T or wait one more minute. Notice that you'll never need more time than 2n minutes (the actual constraint is even smaller, just consider the case with all dishes times equal to n).

// // So that dp works in O(n^2).
// int main()
// {
//     scanf("%d", &T);
//     while (T--)
//     {
//         scanf("%d", &N);
//         for (int i = 1; i <= N; i++)
//             scanf("%d", &A[i]);
//         sort(A + 1, A + N + 1);
//         for (int i = 1; i <= N; i++)
//         {
//             dp[i][0] = INF;
//             for (int j = 1; j <= N + N; j++)
//             {
//                 dp[i][j] = min(dp[i - 1][j - 1] + abs(A[i] - j), dp[i][j - 1]);
//             }
//         }
//         printf("%d\n", dp[N][N + N]);
//     }
//     return 0;
// }

#include "bits/stdc++.h"
using namespace std;
#define int long long
#define pb push_back
#define ppb pop_back
#define pf push_front
#define ppf pop_front
#define all(x) (x).begin(), (x).end()
#define uniq(v) (v).erase(unique(all(v)), (v).end())
#define sz(x) (int)((x).size())
#define fr first
#define sc second
#define pii pair<int, int>
#define rep(i, a, b) for (int i = a; i < b; i++)
#define mem1(a) memset(a, -1, sizeof(a))
#define mem0(a) memset(a, 0, sizeof(a))
#define ppc __builtin_popcount
#define ppcll __builtin_popcountll

template <typename T1, typename T2>
istream &operator>>(istream &in, pair<T1, T2> &a)
{
    in >> a.fr >> a.sc;
    return in;
}
template <typename T1, typename T2>
ostream &operator<<(ostream &out, pair<T1, T2> a)
{
    out << a.fr << " " << a.sc;
    return out;
}
template <typename T, typename T1>
T amax(T &a, T1 b)
{
    if (b > a)
        a = b;
    return a;
}
template <typename T, typename T1>
T amin(T &a, T1 b)
{
    if (b < a)
        a = b;
    return a;
}

const long long INF = 1e18;
const int32_t M = 1e9 + 7;
const int32_t MM = 998244353;

const int N = 0;

int n;
vector<int> a;
int dp[205][405];
int calc(int p, int t)
{
    if (p == n)
        return 0;
    if (t == 2 * n + 1)
        return INF;
    if (dp[p][t] != -1)
        return dp[p][t];
    return dp[p][t] = min(calc(p, t + 1), calc(p + 1, t + 1) + abs(a[p] - t));
}

void solve()
{
    cin >> n;
    a.resize(n);
    rep(i, 0, n) cin >> a[i];
    sort(all(a));

    mem1(dp);
    cout << calc(0, 1) << "\n";
}
signed main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
// freopen("input.txt", "r", stdin);
// freopen("output.txt", "w", stdout);
#ifdef SIEVE
    sieve();
#endif
#ifdef NCR
    init();
#endif
    int t = 1;
    cin >> t;
    while (t--)
        solve();
    return 0;
}
