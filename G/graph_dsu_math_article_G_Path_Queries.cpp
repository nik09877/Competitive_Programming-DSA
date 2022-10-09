#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using vb = vector<bool>;
using vvb = vector<vb>;
using vi = vector<int>;
using vvi = vector<vi>;
using vl = vector<ll>;
using vvl = vector<vl>;
using vc = vector<char>;
using vvc = vector<vc>;
using vs = vector<string>;
const ll mod = 1e9 + 7, inf = 1e18;
#define pb push_back
#define fast                      \
    ios_base::sync_with_stdio(0); \
    cin.tie(0);                   \
    cout.tie(0);
void setIO()
{
    fast;
}
ll ans;
struct DSU
{
    int n;
    vi leader;
    vl size;
    DSU(int _n)
    {
        n = _n;
        leader.assign(n + 1, 0);
        size.assign(n + 1, 0);
        for (int i = 1; i <= n; i++)
        {
            leader[i] = i;
            size[i] = 1;
        }
    }
    int FindLeader(int a)
    {
        if (leader[a] == a)
            return a;
        return leader[a] = FindLeader(leader[a]); //Path Compression
    }
    void Merge(int a, int b)
    {
        a = FindLeader(a), b = FindLeader(b);
        if (a == b)
            return; //a and b are in the same connected component
        leader[b] = a;
        ll previousSizea = size[a];
        size[a] += size[b];
        ans += (size[a] * (size[a] - 1)) / 2 - (previousSizea * (previousSizea - 1)) / 2 - (size[b] * (size[b] - 1)) / 2;
    }
};
bool cmp(vi &e1, vi &e2)
{
    return e1[2] < e2[2];
}
int main()
{
    setIO();
    int n, m;
    cin >> n >> m;
    vvi edge(n - 1, vi(3)), queries(m, vi(2));
    vl out(m);

    for (int i = 0; i < n - 1; i++)
    {
        int u, v, w;
        cin >> u >> v >> w;
        edge[i][0] = u, edge[i][1] = v, edge[i][2] = w; //edge[i] stores {first endpoint,
        //second endpoint,weight of the edge}
    }
    sort(edge.begin(), edge.end(), cmp);

    for (int i = 0; i < m; i++)
    {
        cin >> queries[i][0];
        queries[i][1] = i; //queries[i] stores {weight of the ith query, index of the
        //ith query}
    }

    sort(queries.begin(), queries.end());

    DSU ds(n);

    int pos = 0; //pos stores the index of the last added edge
    //from the edge list
    for (int i = 0; i < m; i++)
    {
        //queries[i - 1][0] < queries[i][0]
        //this means we add edges which have a weight <= queries[i][0]
        for (; pos < n - 1; pos++)
        {
            if (edge[pos][2] <= queries[i][0])
            {
                ds.Merge(edge[pos][0], edge[pos][1]);
            }
            else
                break; //because the edges are sorted in increasing order
        }
        out[queries[i][1]] = ans; //queries[i][1] stores the index of the ith query
    }

    for (int i = 0; i < m; i++)
        cout << out[i] << " ";
    return 0;
}