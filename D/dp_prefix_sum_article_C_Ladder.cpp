#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
#define pb push_back
#define mp make_pair
#define lli long long int
#define in(a, n)                \
    lli a[n];                   \
    for (lli i = 0; i < n; i++) \
        cin >> a[i];
#define mem(a, val, n)      \
    for (i = 0; i < n; i++) \
        a[i] = val;
#define print(a, n)             \
    for (lli i = 0; i < n; i++) \
        cout << a[i] << ' ';    \
    br
#define printv(v)                                                      \
    for (vector<lli>::iterator itv = v.begin(); itv != v.end(); itv++) \
        cout << *itv << ' ';                                           \
    br
#define prints(s)                                                   \
    for (set<lli>::iterator its = s.begin(); its != s.end(); its++) \
        cout << *its << ' ';                                        \
    br
#define printm(m)                                                        \
    for (map<lli, lli>::iterator itm = m.begin(); itm != m.end(); itm++) \
        cout << (*itm).ff << ' ' << (*itm).ss << endl;
#define printmm(m)                                                            \
    for (multimap<lli, lli>::iterator itm = m.begin(); itm != m.end(); itm++) \
        cout << (*itm).ff << ' ' << (*itm).ss << endl;
#define print2(a, b)       \
    cout << a << ' ' << b; \
    br
#define print3(a, b, c)                \
    cout << a << ' ' << b << ' ' << c; \
    br
#define print4(a, b, c, d)                         \
    cout << a << ' ' << b << ' ' << c << ' ' << d; \
    br
#define sum(a, n)               \
    lli sum = 0;                \
    for (lli i = 0; i < n; i++) \
        sum += a[i];
#define br cout << endl;
#define check cout << "x" << endl;
#define lower(a) transform(a.begin(), a.end(), a.begin(), ::tolower);
#define upper(a) transform(a.begin(), a.end(), a.begin(), ::toupper);
#define ff first
#define ss second
#define mod 1000000007
#define maxn 100005
#define inf 1000000000
using namespace std;
using namespace __gnu_pbds;
typedef tree<lli, null_type, less_equal<lli>, rb_tree_tag, tree_order_statistics_node_update> ordered_set;
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    lli t, i, j, k, n, m, c, x, ans, l, r;
    cin >> n >> t;
    in(a, n);
    lli left[n], right[n];
    // x = a[0];
    left[0] = 0;
    for (i = 1; i < n; i++)
    {
        if (a[i] <= a[i - 1])
        {
            left[i] = left[i - 1];
        }
        else
        {
            left[i] = i;
        }
    }
    right[n - 1] = n - 1;
    for (i = n - 2; i >= 0; i--)
    {
        if (a[i] <= a[i + 1])
        {
            right[i] = right[i + 1];
        }
        else
        {
            right[i] = i;
        }
    }
    // print(left, n);
    // print(right, n);
    while (t--)
    {
        cin >> l >> r;
        l--;
        r--;
        if (right[l] >= left[r])
        {
            cout << "Yes";
            br
        }
        else
        {
            cout << "No";
            br
        }
    }
    return 0;
}