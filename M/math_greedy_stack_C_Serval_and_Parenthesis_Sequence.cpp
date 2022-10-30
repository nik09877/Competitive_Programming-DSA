// Lets goto the next level
// AIM CM at CF *__* asap
// Striver_79
// Remember you were also a novice when you started,
// hence never be rude to anyone who wants to learn something
// Never open a ranklist untill and unless you are done with solving problems, wastes 3/4 minuts
// Donot treat CP as a placement thing, love it and ejoy it, you will suceed for sure.
// Any doubts or want to have a talk, contact https://www.facebook.com/raj.striver

#include <algorithm>
#include <bits/stdc++.h>
#include <unordered_map>
#include <unordered_set>
using namespace std;
#define mod (int)1000000007
#define all(a) a.begin(), a.end()
#define for0(i, n) for (int i = 0; i < n; i++)
#define for1(i, n) for (int i = 1; i <= n; i++)
#define loop(i, a, b) for (int i = a; i < b; i++)
#define bloop(i, a, b) for (int i = a; i >= b; i--)
#define tc(t) \
    int t;    \
    cin >> t; \
    while (t--)
#define int long long
#define ll long long
#define pb emplace_back
#define fio ios_base::sync_with_stdio(false), cin.tie(NULL), cout.tie(NULL)
#define in(x) scanf("%d", &x)
#define rr return 0
#define prec(n) fixed << setprecision(n)
#define maxheap priority_queue<int>
#define minheap priority_queue<int, vector<int>, greater<int>>
#define inf (int)(1e18)
#define ini(a, i) memset(a, i, sizeof(a))
#define vi vector<int>
#define fi first
#define se second
#define kitna se
#define endl "\n"
#define pi pair<int, int>
#define vii vector<pi>
const int MAXN = (int)((1e5) + 10);
int gcd(int a, int b)
{
    if (a == 0)
        return b;
    return gcd(b % a, a);
}
int max(int a, int b)
{
    if (a > b)
        return a;
    else
        return b;
}
int min(int a, int b)
{
    if (a < b)
        return a;
    else
        return b;
}
bool isPrime(int N)
{
    for (int i = 2; i * i <= N; ++i)
    {
        if (N % i == 0)
            return false;
    }
    return true;
}
int cbrt(int x)
{
    int lo = 1, hi = min(2000000ll, x);
    while (hi - lo > 1)
    {
        int mid = (lo + hi) / 2;
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
const int dx[4] = {-1, 1, 0, 0};
const int dy[4] = {0, 0, -1, 1};
const int N = (int)(1e5 + 10);
const int MAXBIT = 19;
// vector<int>vec[nax];
//  const int N = 5;

// int SPF[N+5];

// void SOF()
// {
//     SPF[1] = 1;
//     for (int i=2; i<N; i++)
//         SPF[i] = i;
//     for (int i=4; i<N; i+=2)
//         SPF[i] = 2;

//     for (int i=3; i*i<N; i++)
//         {
//         if (SPF[i] == i)
//             {
//             for (int kon=i*i; kon<N; kon+=i)
//                 if (SPF[kon]==kon)
//                    SPF[kon] = i;
//             }
//         }
// }

// int C[1005][1005];
// int binomialCoeff(int n, int k)
// {
//     // int C[n + 1][k + 1];
//     int i, j;

//     // Caculate value of Binomial Coefficient
//     // in bottom up manner
//     for (i = 0; i <= n; i++)
//     {
//         for (j = 0; j <= min(i, k); j++)
//         {
//             // Base Cases
//             if (j == 0 || j == i)
//                 C[i][j] = 1;

//             // Calculate value using previosly
//             // stored values
//             else
//                 C[i][j] = C[i - 1][j - 1] +
//                           C[i - 1][j];
//         }
//     }

//     return C[n][k];
// }

bool isPowerOfTwo(int x)
{
    /* First x in the below expression is for the case when x is 0 */
    return x && (!(x & (x - 1)));
}
vii vec[105];

signed main()
{
#ifndef ONLINE_JUDGE
    // for getting input from input.txt
    freopen("input.txt", "r", stdin);
// for writing output to output.txt
// freopen("output.txt", "w", stdout);
#endif

    // fflush(stdout);
    fio;
    // int t;
    // t = 1;
    int tc = 1;
    while (tc--)
    {
        int n;
        cin >> n;
        string s;
        cin >> s;
        if (n % 2 == 1)
        {
            cout << ":(";
            rr;
        }
        int opn = 0, cls = 0;

        for0(i, n)
        {
            if (s[i] == '(')
                opn++;
            else if (s[i] == ')')
                cls++;
        }

        if (opn > (n / 2) || cls > (n / 2))
        {
            cout << ":(";
            rr;
        }

        int xx = (n / 2) - opn;
        for0(i, n)
        {
            if (s[i] == '?')
            {
                if (xx > 0)
                {
                    s[i] = '(';
                    xx--;
                }
                else
                    s[i] = ')';
            }
        }

        opn = 0;

        for0(i, n - 1)
        {
            if (s[i] == '(')
                opn++;
            else
                opn--;
            if (opn <= 0)
            {
                cout << ":(";
                rr;
            }
        }
        // cout << s;
        if (s[n - 1] == '(')
            opn++;
        else
            opn--;
        // cout << opn;

        if (!opn)
            cout << s;
        else
            cout << ":(";
    }
    rr;
}