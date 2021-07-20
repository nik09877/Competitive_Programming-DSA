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

class Dsu
{
public:
    int par[100005];
    int sz[100005];
    set<int> st;
    int mx_size = 1;
    void init(int n)
    {
        rep1(i, n)
        {
            par[i] = i;
            sz[i] = 1;
            st.insert(i);
        }
    }

    int find(int a)
    {
        if (a == par[a])
            return a;
        return par[a] = find(par[a]);
    }

    void merge(int a, int b)
    {
        a = find(a);
        b = find(b);
        if (a != b)
        {
            if (sz[a] < sz[b])
                swap(a, b);
            par[b] = a;
            st.erase(b);
            sz[a] += sz[b];
            mx_size = max(mx_size, sz[a]);
        }
    }
};

int32_t main()
{
    fastio;
    Dsu d;
    int n, m;
    cin >> n >> m;
    d.init(n);
    rep(i, m)
    {
        int a, b;
        cin >> a >> b;
        d.merge(a, b);
        cout << d.st.size() << sp << d.mx_size << endl;
    }
}