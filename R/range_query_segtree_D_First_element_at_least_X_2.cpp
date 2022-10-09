#pragma GCC optimize("O3")
#pragma GCC target("sse4")
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

typedef int node;
struct segtree
{
    //0 based indexing and query in range [l,r)
    int size;
    vector<node> st;
    node NEUTRAL_ELEMENT = INT_MIN;

    node merge(node a, node b)
    {
        return max(a, b);
    }

    node single_merge(int v)
    {
        return v;
    }

    void init(int n)
    {
        size = 1;
        // get to the nearest power of two
        while (size < n)
            size *= 2;

        st.resize(2 * size);
    }

    void build(int x, int lx, int rx, vi &a)
    {
        if (rx - lx == 1)
        {
            //as we have increased our segment range we need to check if left boundary is within the size of the array and if true initialize segtree with that value else it is already assigned to 0 in the init function

            if (lx < sz(a))
            {
                st[x] = single_merge(a[lx]);
            }
            return;
        }

        int m = (lx + rx) / 2;
        build(2 * x + 1, lx, m, a);
        build(2 * x + 2, m, rx, a);

        st[x] = merge(st[2 * x + 1], st[2 * x + 2]);
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
            st[x] = single_merge(v);
            return;
        }

        int m = (lx + rx) / 2;
        if (i < m)
            set(i, v, 2 * x + 1, lx, m);
        else
            set(i, v, 2 * x + 2, m, rx);

        st[x] = merge(st[2 * x + 1], st[2 * x + 2]);
    }
    void set(int i, int v)
    {
        set(i, v, 0, 0, size);
    }

    node query(int l, int r, int x, int lx, int rx)
    {
        //if segtree range is out of query range
        if (lx >= r || rx <= l)
        {
            return NEUTRAL_ELEMENT;
        }
        //complete overlap (segtree range completely inside query range)
        if (lx >= l && rx <= r)
        {
            return st[x];
        }

        //partial overlap
        int m = (lx + rx) / 2;

        auto left = query(l, r, 2 * x + 1, lx, m);
        auto right = query(l, r, 2 * x + 2, m, rx);

        return merge(left, right);
    }
    node query(int l, int r)
    {
        return query(l, r, 0, 0, size);
    }

    int first_above(int v, int l, int x, int lx, int rx)
    {
        if (st[x] < v or rx <= l)
            return -1;
        if (rx - lx == 1)
            return lx;

        int m = (lx + rx) / 2;
        int res = first_above(v, l, 2 * x + 1, lx, m);
        if (res == -1)
        {
            res = first_above(v, l, 2 * x + 2, m, rx);
        }
        return res;
    }
    int first_above(int x, int l)
    {
        return first_above(x, l, 0, 0, size);
    }
};

void solve()
{
    int n, m;
    cin >> n >> m;

    segtree st;
    st.init(n);

    vi a(n);
    re(a, n);
    st.build(a);

    while (m--)
    {
        int op;
        cin >> op;
        if (op == 1)
        {
            int i, v;
            cin >> i >> v;
            st.set(i, v);
        }
        else
        {
            int x, l;
            cin >> x >> l;
            cout << st.first_above(x, l) << endl;
        }
    }
    return;
}
int32_t main()
{
    fastio;
    solve();
}