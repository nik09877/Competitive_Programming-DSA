/*
https://codeforces.com/contest/1473/submission/104349092
IIT BHU Youtube for explanation

The value of x always changes by 1, thus, the set of values of x

is always some contiguous segment. The length of such segment can be determined by just its minimum and maximum values.

So we have to solve two separate tasks for each query: find the minimum and the maximum value x

gets assigned to. I'll describe only the minimum one.

This task, however, can as well be split into two parts: minimum value on a prefix before l
and on a suffix after r. The prefix is easy — it doesn't get changed by a query, so it can be precalculated beforehand. Minimum value on a prefix of length i is minimum of a minimum value on a prefix of length i−1

and the current value.

The suffix minimum is not that trivial. First, in order to precalculate the minimum value on a suffix of length i
, we have to learn to prepend an instruction to the suffix of length i+1. Consider the graph of values of x over time. What happens to it if the initial value of x is not 0 but 1, for example? It just gets shifted by 1 upwards. That move is actually the same as prepending a '+' instruction. So the minimum value for a suffix of length i is a minimum of a minimum value for a suffix of length i−1, increased by the current instruction, and 0

(the start of the graph).

So now we have a minimum value on a suffix after r
. However, it can't be taken into the answer as it is, because it considers the graph for the suffix to be starting from 0. And that's not the case. The graph for the suffix starts from the value the prefix ends on. So we can shift the answer for the suffix by the value of x after the prefix. The overall minimum value is just the minimum on a prefix and on a suffix, then.
*/
#include <bits/stdc++.h>
using namespace std;
#define in(x) \
    int x;    \
    cin >> x;
#define sin(s) \
    string s;  \
    cin >> s;
#define ll long long
#define lin(x) \
    ll x;      \
    cin >> x;
#define vi vector<int>
#define vll vector<ll>
#define si set<int>
#define pb push_back
#define re(i, n) for (int i = 0; i < n; i++)
#define pe(i, a, b) for (ll i = a; i <= b; i++)
#define rre(i, n) for (int i = n - 1; i > -1; i--)
#define mp make_pair
#define pll pair<ll, ll>
#define pii pair<int, int>
#define endl "\n"
#define pi 3.1415926536
#define FAST                          \
    ios_base::sync_with_stdio(false); \
    cin.tie(0);                       \
    cout.tie(0);
#define fio                           \
    freopen("input.txt", "r", stdin); \
    freopen("output.txt", "w", stdout);
#define mod 998244353
//#define inf LLONG_MAX
#define ninf -INT_MAX
#define inf 1000000
#define MAXN 10000001

int main()
{
    FAST
    in(t) while (t--)
    {
        in(n)
            in(q)
                sin(s) int x = 0;
        int mi[n][2];
        int mx[n][2];
        int a[n];
        re(i, n)
        {
            if (s[i] == '-')
            {
                x--;
            }
            else
            {
                x++;
            }
            // stores prefix sum
            a[i] = x;
            // cout<<x<<endl;
        }
        mi[0][0] = a[0];
        mx[0][0] = a[0];
        mi[n - 1][1] = a[n - 1];
        mx[n - 1][1] = a[n - 1];
        pe(i, 1, n - 1)
        {
            mi[i][0] = min(mi[i - 1][0], a[i]);
            // cout<<mi[i][0]<<' ';
            mx[i][0] = max(mx[i - 1][0], a[i]);
            // cout<<mx[i][0]<<endl;
        }
        for (int i = n - 2; i >= 0; i--)
        {
            mi[i][1] = min(mi[i + 1][1], a[i]);
            // cout<<mi[i][1]<<' ';
            mx[i][1] = max(mx[i + 1][1], a[i]);
            // cout<<mx[i][1]<<endl;
        }
        while (q--)
        {
            in(d)
                in(b)
                    d--;
            b--;
            int l = 0, r = 0;
            if (b < n - 1)
            {
                if (d > 0)
                {
                    l = min(l, mi[b + 1][1] - (a[b] - a[d - 1]));
                    r = max(r, mx[b + 1][1] - (a[b] - a[d - 1]));
                }
                else
                {
                    l = min(l, mi[b + 1][1] - (a[b]));
                    r = max(r, mx[b + 1][1] - (a[b]));
                }
            }
            if (d > 0)
            {
                l = min(l, mi[d - 1][0]);
                r = max(r, mx[d - 1][0]);
            }
            cout << r - l + 1 << endl;
        }
    }
    return 0;
}