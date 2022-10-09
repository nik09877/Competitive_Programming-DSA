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
#define int long long int
const int mod = 1000000007;
struct segtree
{
    //0 based indexing and query in range [l,r)
    int size;
    vector<int> st;
    void init(int n)
    {
        size = 1;
        // get to the nearest power of two
        while (size < n)
            size *= 2;

        st.assign(2 * size, 0ll);
    }
    void build(int x, int lx, int rx, vi &a)
    {
        if (rx - lx == 1)
        {
            //as we have increased our segment range we need to check if left boundary is within the size of the array and if true initialize segtree with that value else it is already assigned to 0 in the init function

            if (lx < sz(a))
            {
                st[x] = a[lx];
            }
            return;
        }

        int m = (lx + rx) / 2;
        build(2 * x + 1, lx, m, a);
        build(2 * x + 2, m, rx, a);
        st[x] = __gcd(st[2 * x + 1], st[2 * x + 2]);
        return;
    }
    void build(vi &a)
    {
        build(0, 0, size, a);
    }

    //i is query index
    // v is the new_value
    // x is the current_node
    // lx is the left boundary of current_node
    // rx is the right boundary of current_node

    // this is point update
    void set(int i, int v, int x, int lx, int rx)
    {
        if (rx - lx == 1)
        {
            st[x] = v;
            return;
        }

        int m = (lx + rx) / 2;
        if (i < m)
            set(i, v, 2 * x + 1, lx, m);
        else
            set(i, v, 2 * x + 2, m, rx);

        st[x] = st[2 * x + 1] + st[2 * x + 2];
    }
    void set(int i, int v)
    {
        set(i, v, 0, 0, size);
    }

    int query(int l, int r, int x, int lx, int rx)
    {
        //if segtree range is out of query range
        if (lx >= r || rx <= l)
        {
            return 0;
        }
        //complete overlap (segtree range completely inside query range)
        if (lx >= l && rx <= r)
        {
            return st[x];
        }

        //partial overlap
        int m = (lx + rx) / 2;
        int left = query(l, r, 2 * x + 1, lx, m);
        int right = query(l, r, 2 * x + 2, m, rx);
        return __gcd(left, right);
    }
    int query(int l, int r)
    {
        return query(l, r, 0, 0, size);
    }
} st;

// bool good(int m, vi &a, int n)
// {
//     for (int i = 0; i + m - 1 < n; i++)
//     {
//         int l = i, r = i + m - 1;
//         int gcd = st.query(l, r);
//         // cerr << gcd << endl;
//         if (gcd > 1 or gcd == 0)
//             return true;
//     }
//     return false;
// }

bool good(int l, int r)
{
    if (l == r)
        return true;
    return st.query(l, r) > 1;
}
int32_t main()
{
    fastio;
    int t;
    cin >> t;
    while (t--)
    {
        int n;
        cin >> n;
        vi a(n), diff;
        read(a, n);
        if (n == 1)
        {
            cout << 1 << endl;
            continue;
        }
        fo(i, 0, n - 2) diff.pb(abs(a[i] - a[i + 1]));
        st.init(n - 1);
        st.build(diff);

        int ans = 1, l = 0;
        for (int r = 0; r < n; r++)
        {
            while (!good(l, r))
                l++;
            ans = max(ans, r - l + 1);
        }
        //binary_search + sliding window of length (mid)(TLE)
        // int l = 0, r = n, ans = 0;
        // while (l <= r)
        // {
        //     int m = (l + r) >> 1;
        //     if (good(m, a, n))
        //     {
        //         ans = m;
        //         l = m + 1;
        //     }
        //     else
        //         r = m - 1;
        // }
        cout << ans << endl;
    }
}