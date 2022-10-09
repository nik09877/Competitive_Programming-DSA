#include <bits/stdc++.h>
#include <stdio.h>
#define rep(i, n) for (int i = 0; i < n; i++)
#define rrep(i, a, b) for (int i = a; i >= b; i--)
#define rep1(i, n) for (int i = 1; i <= n; i++)
#define fo(i, a, n) for (int i = a; i <= n; i++)
#define repll(i, a, n) for (lli i = a; i <= n; i++)
#define mkp make_pair
#define pb push_back
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
#define fastio ios_base::sync_with_stdio(0), cout.tie(0), cin.tie(0)
#define read(a)       \
    for (auto &i : a) \
        cin >> i;
using namespace std;
const int mod = 1000000007;

/*
    1-find primes less than equal to n
    2-create undirected graph p <-> (p * i) for all 1 <= i <= n/p
    3-find size of each connected component
    4-store them as {size_of_cc,root} and sort them in descending order
    5-store {freq,char} in max heap
    6-now maintain a char ans[n+1] array
    7-if freq is >= size_of_cc do dfs and update ans[node] = char
    8-update max heap
    9-else it is not possible to create a permutation
*/

// step 6
char ans[1005], s[1005];
vi g[1005];
bitset<1005> vis;

void dfs(int node, int &cc_cnt)
{
    cc_cnt++;
    vis[node] = 1;

    for (auto child : g[node])
    {
        if (vis[child] == 1)
            continue;
        dfs(child, cc_cnt);
    }
}
void dfs2(int node, char color)
{
    vis[node] = 1;
    ans[node] = color;

    for (auto child : g[node])
    {
        if (vis[child] == 1)
            continue;
        dfs2(child, color);
    }
}
void solve()
{
    int n;
    string temp;
    cin >> temp;
    n = sz(temp);
    fo(i, 1, n) s[i] = temp[i - 1];

    // step 1
    vi primes;
    bitset<1005> isPrime;
    for (int i = 2; i * i <= n; i++)
    {
        if (isPrime[i] == 0)
        {
            for (int j = i * i; j <= n; j += i)
                isPrime[j] = 1;
        }
    }
    for (int i = 2; i <= n; i++)
        if (isPrime[i] == 0)
            primes.pb(i);

    // step 2
    for (auto p : primes)
    {
        for (int a = p, b = p + p; b <= n; b += p)
        {
            g[a].pb(b);
            g[b].pb(a);
            a = b;
        }
    }

    // step 3
    vpii connected_components;
    for (int i = 1; i <= n; i++)
    {
        if (vis[i] == 0)
        {
            int cc_cnt = 0;
            dfs(i, cc_cnt);
            connected_components.push_back({cc_cnt, i});
        }
    }

    // step 4
    sort(connected_components.rbegin(), connected_components.rend());

    // step 5
    priority_queue<pair<int, char>> pq;
    vi cnt(26, 0);
    for (int i = 1; i <= n; i++)
        cnt[s[i] - 'a']++;
    for (int i = 0; i < 26; i++)
    {
        if (cnt[i] == 0)
            continue;
        pq.push({cnt[i], 'a' + i});
    }

    // step 7
    vis.reset();
    for (auto it : connected_components)
    {
        int cc_sz = it.ff;
        int node = it.ss;

        int freq = pq.top().ff;
        char color = pq.top().ss;

        pq.pop();

        if (freq < cc_sz)
        {
            cout << "NO\n";
            return;
        }

        freq -= cc_sz;
        pq.push({freq, color});

        dfs2(node, color);
    }
    cout << "YES\n";
    for (int i = 1; i <= n; i++)
        cout << ans[i];
    return;
}
int32_t main()
{
    fastio;
    solve();
}