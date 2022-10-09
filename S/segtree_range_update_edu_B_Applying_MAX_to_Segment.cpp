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

struct node
{
    int mx;
};
struct segtree
{
    //------------------------------DATA MEMBERS--------------------------------------//
    //0 based indexing and query in range [l,r)
    int size;
    vector<node> st;
    node NEUTRAL_ELEMENT = {0};

    //----------------------------INITIALIZE AND BUILD OPERATION--------------------------------//
    void init(int n)
    {
        size = 1;
        // get to the nearest power of two
        while (size < n)
            size *= 2;

        st.resize(2 * size, NEUTRAL_ELEMENT);
    }

    //---------------------------------RANGE UPDATE---------------------------------------------//
    //----------------------------MODIFY(l,r,v) and GET(i)--------------------------------------//
    node operation(node a, node b)
    { //this is just for example ,this operation here doesn't make sense ,I just took it like this ,change it however you like
        return {max(a.mx, b.mx)};
    }
    void modify(int l, int r, int v, int x, int lx, int rx)
    {
        //if segtree range is out of query range
        if (lx >= r || rx <= l)
        {
            return;
        }
        //complete overlap (segtree range completely inside query range)
        if (lx >= l && rx <= r)
        {
            st[x] = operation(st[x], {v});
            return;
        }

        //partial overlap
        int m = (lx + rx) / 2;
        modify(l, r, v, 2 * x + 1, lx, m);
        modify(l, r, v, 2 * x + 2, m, rx);
    }
    void modify(int l, int r, int v)
    {
        modify(l, r, v, 0, 0, size);
    }

    node get(int i, int x, int lx, int rx)
    {
        //If I am at leaf node
        if (rx - lx == 1)
            return st[x];

        node res;

        int m = (lx + rx) / 2;
        if (i < m)
            res = get(i, 2 * x + 1, lx, m);
        else
            res = get(i, 2 * x + 2, m, rx);

        return operation(res, st[x]);
    }
    int get(int i)
    {
        return get(i, 0, 0, size).mx;
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
            int i;
            cin >> i;
            cout << st.get(i) << endl;
        }
    }
    return;
}
int32_t main()
{
    fastio;
    solve();
    // #ifndef ONLINE_JUDGE
    //     TIME;
    // #endif
}