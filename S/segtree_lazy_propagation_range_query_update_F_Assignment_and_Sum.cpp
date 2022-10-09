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
const int mod = 1000000007;

struct segtree
{
    //------------------------------DATA MEMBERS--------------------------------------//
    //0 based indexing and query in range [l,r)
    int size;
    vector<int> operations, values;
    int NO_OPERATION = LLONG_MAX - 1;
    int NEUTRAL_ELEMENT = 0;

    //----------------------------INITIALIZE AND BUILD OPERATION--------------------------------//
    void init(int n)
    {
        size = 1;
        // get to the nearest power of two
        while (size < n)
            size *= 2;

        operations.resize(2 * size, 0ll);
        values.resize(2 * size, 0ll);

        //initialize segtree with 1 as given in problem statement
        // build();
    }

    void build(int x, int lx, int rx)
    {
        if (rx - lx == 1)
        {
            values[x] = 1;
            return;
        }

        int m = (lx + rx) / 2;
        build(2 * x + 1, lx, m);
        build(2 * x + 2, m, rx);

        values[x] = calc_op(values[2 * x + 1], values[2 * x + 2]);
        return;
    }
    void build()
    {
        build(0, 0, size);
    }

    //----------------------------RANGE UPDATE(NON COMMUTATIVE)-------------------------------------//
    //---------------------------------MODIFY(l,r,v)--------------------------------------------//

    void propagate(int x, int lx, int rx)
    {
        //If current node is leaf node we can't push current node's operation to its children
        if (rx - lx == 1)
            return;

        //push current node's operations to its children and mark current node's operation as NO_OPERATION
        int m = (lx + rx) / 2;
        apply_modify_op(operations[2 * x + 1], operations[x], 1);
        apply_modify_op(values[2 * x + 1], operations[x], m - lx);
        apply_modify_op(operations[2 * x + 2], operations[x], 1);
        apply_modify_op(values[2 * x + 2], operations[x], rx - m);
        operations[x] = NO_OPERATION;
    }

    int modify_op(int a, int b, int len)
    {
        if (b == NO_OPERATION)
            return a;
        return b * len;
    }

    int calc_op(int a, int b)
    {
        return a + b;
    }

    void apply_modify_op(int &a, int b, int len)
    {
        a = modify_op(a, b, len);
    }

    void modify(int l, int r, int v, int x, int lx, int rx)
    {
        //propagate
        propagate(x, lx, rx);

        //if segtree range is out of query range
        if (lx >= r || rx <= l)
            return;

        //complete overlap (segtree range completely inside query range)
        if (lx >= l && rx <= r)
        {
            apply_modify_op(operations[x], v, 1);
            apply_modify_op(values[x], v, rx - lx);
            return;
        }

        //partial overlap
        int m = (lx + rx) / 2;
        modify(l, r, v, 2 * x + 1, lx, m);
        modify(l, r, v, 2 * x + 2, m, rx);

        values[x] = (calc_op(values[2 * x + 1], values[2 * x + 2]));
    }
    void modify(int l, int r, int v)
    {
        modify(l, r, v, 0, 0, size);
    }

    //----------------------------------------CALC(l,r)--------------------------------------------//

    int calc(int l, int r, int x, int lx, int rx)
    {
        //propagate
        propagate(x, lx, rx);

        if (lx >= r || rx <= l)
            return NEUTRAL_ELEMENT;
        if (lx >= l and rx <= r)
            return values[x];

        int m = (lx + rx) / 2;
        auto m1 = calc(l, r, 2 * x + 1, lx, m);
        auto m2 = calc(l, r, 2 * x + 2, m, rx);
        return calc_op(m1, m2);
    }
    int calc(int l, int r)
    {
        return calc(l, r, 0, 0, size);
    }
};
void solve()
{
    int n, m;
    cin >> n >> m;
    segtree st;
    st.init(n);
    while (m--)
    {
        int op;
        cin >> op;
        if (op == 1)
        {
            int l, r, v;
            cin >> l >> r >> v;
            st.modify(l, r, v);
        }
        else
        {
            int l, r;
            cin >> l >> r;
            cout << st.calc(l, r) << endl;
        }
    }
    return;
}
int32_t main()
{
    fastio;
    solve();
}