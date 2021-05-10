// #include <bits/stdc++.h>
// #include <stdio.h>
// #define rep(i, n) for (int i = 0; i < n; i++)
// #define rrep(i, a, b) for (int i = a; i >= b; i--)
// #define rep1(i, n) for (int i = 1; i <= n; i++)
// #define fo(i, a, n) for (int i = a; i <= n; i++)
// #define repll(i, a, n) for (lli i = a; i <= n; i++)
// #define mkp make_pair
// #define pb emplace_back
// #define ff first
// #define ss second
// #define ll long long
// #define lli long long int
// #define ii int, int
// #define pii pair<int, int>
// #define pll pair<long, long>
// #define plli pair<long long int, long long int>
// #define vi vector<int>
// #define vvi vector<vector<int>>
// #define vlli vector<long long int>
// #define vpii vector<pair<int, int>>
// #define vplli vector<pair<long long int, long long int>>
// #define vvlli vector<vector<long long int>>
// #define MAXLL 1e18
// #define endl '\n'
// #define sp ' '
// #define dsort(v) sort(v.begin(), v.end(), greater<int>())
// #define asort(v) sort(v.begin(), v.end())
// #define uniq(v) v.erase(unique(v.begin(), v.end()), v.end())
// #define all(v) v.begin(), v.end()
// #define umap unordered_map
// #define uset unordered_set
// #define sz(x) ((int)(x).size())
// #define yes cout << "YES\n"
// #define no cout << "NO\n"
// #define pr(x) cout << x
// #define prsp(x) cout << x << sp
// #define prln(x) cout << x << endl
// #define fastio ios_base::sync_with_stdio(0), cout.tie(0), cin.tie(0)
// #define read(a, n) \
//     rep(i, n)      \
//             cin >> \
//         a[i];
// using namespace std;

// vi adj[200005];
// int type[200005];
// int col[200005];
// bool vis[200005];
// int ans = INT_MIN;

// void dfs(int node)
// {
//     vis[node] = true;
//     int par_col = col[node];
//     int colour = 1;
//     for (int child : adj[node])
//     {
//         if (!vis[child])
//         {
//             if (type[child] == type[node])
//             {
//                 col[child] = par_col;
//                 dfs(child);
//             }
//             else
//             {
//                 while (colour == par_col)
//                     colour++;

//                 col[child] = colour;
//                 dfs(child);
//             }
//         }
//         ans = max(ans, colour);
//     }
// }
// void solve()
// {
//     int n;
//     ans = INT_MIN;
//     cin >> n;
//     rep1(i, n)
//     {
//         cin >> type[i];
//         adj[i].clear();
//         col[i] = 0;
//         vis[i] = false;
//     }
//     rep1(i, n)
//     {
//         int x = i, y = i + 1;
//         if (x == n)
//             y = 1;
//         adj[x].pb(y);
//         adj[y].pb(x);
//     }
//     if (n % 2 == 0)
//     {
//         prln(2);
//         rep1(i, n)
//         {
//             if (i & 1)
//                 prsp(1);
//             else
//                 prsp(2);
//         }
//         cout << endl;
//         return;
//     }
//     col[1] = 1;
//     ans = 1;
//     dfs(1);

//     if (type[1] != type[n] and col[1] == col[n])
//     {
//         if (type[n - 1] != type[n])
//         {
//             ans++;
//             col[n] = 3;
//         }
//         else
//             col[n] = 2;
//     }

//     prln(ans);
//     rep1(i, n) prsp(col[i]);
//     cout << endl;
//     return;
// }
// int32_t main()
// {
//     fastio;
//     int t = 1;
//     cin >> t;
//     while (t--)
//     {
//         solve();
//     }
// }

//!EDITORIAL
// The answer to this problem is at most 3. Let's prove it by construction.

//     Firstly,
//     if all ti are equal then the answer is 1. Otherwise, there are at least two different values in the array t so the answer is at least 2. If n is even then the answer is always 2 because you can color figures in the following way : [ 1, 2, 1, 2,…, 1, 2 ].If n is odd then consider two cases.The first case is when some pair of adjacent figures have the same type.Then the answer is 2 because you can merge these two values into one and get the case of even n.Otherwise, all pairs of adjacent figures have different types and if you consider this cyclic array as a graph(cycle of length n) then you can notice that it isn't bipartite so you need at least 3 colors to achieve the answer (color all vertices in such a way that any two adjacent vertices have different colors). And the answer looks like [1,2,1,2,…,1,2,3].
#include <bits/stdc++.h>

using namespace std;

int solve()
{
    int n;
    cin >> n;
    vector<int> a(n);
    for (int i = 0; i < n; ++i)
    {
        cin >> a[i];
    }

    if (count(a.begin(), a.end(), a[0]) == n)
    {
        cout << 1 << endl;
        for (int i = 0; i < n; ++i)
        {
            cout << 1 << " ";
        }
        cout << endl;
        return 0;
    }

    if (n % 2 == 0)
    {
        cout << 2 << endl;
        for (int i = 0; i < n; ++i)
        {
            cout << i % 2 + 1 << " ";
        }
        cout << endl;
        return 0;
    }

    for (int i = 0; i < n; ++i)
    {
        if (a[i] == a[(i + 1) % n])
        {
            vector<int> ans(n);
            for (int j = 0, pos = i + 1; pos < n; ++pos, j ^= 1)
            {
                ans[pos] = j + 1;
            }
            for (int j = 0, pos = i; pos >= 0; --pos, j ^= 1)
            {
                ans[pos] = j + 1;
            }
            cout << 2 << endl;
            for (int pos = 0; pos < n; ++pos)
            {
                cout << ans[pos] << " ";
            }
            cout << endl;
            return 0;
        }
    }

    cout << 3 << endl;
    for (int i = 0; i < n - 1; ++i)
    {
        cout << i % 2 + 1 << " ";
    }
    cout << 3 << endl;
    return 0;
}

int main()
{
#ifdef _DEBUG
    freopen("input.txt", "r", stdin);
//	freopen("output.txt", "w", stdout);
#endif

    int q;
    cin >> q;
    for (int qq = 0; qq < q; qq++)
    {
        solve();
    }

    return 0;
}