#include <bits/stdc++.h>
using namespace std;
#define pb push_back
#define ppb pop_back
#define pf push_front
#define ppf pop_front
#define all(x) (x).begin(), (x).end()
#define sz(x) (int)((x).size())
#define int long long
#define M 1000000007
#define MM 998244353
#define fr first
#define sc second
#define pii pair<int, int>
#define rep(i, a, b) for (int i = a; i < b; i++)
#define mem1(a) memset(a, -1, sizeof(a))
#define mem0(a) memset(a, 0, sizeof(a))
#define ppc __builtin_popcount

template <typename T1, typename T2>
istream &operator>>(istream &in, pair<T1, T2> &a)
{
    in >> a.fr >> a.sc;
    return in;
}
template <typename T1, typename T2>
ostream &operator<<(ostream &out, pair<T1, T2> a)
{
    out << a.fr << " " << a.sc;
    return out;
}
template <typename T>
pair<T, T> operator+=(pair<T, T> &a, pair<T, T> b)
{
    a.fr += b.fr;
    a.sc += b.sc;
    return a;
}
template <typename T>
pair<T, T> operator-=(pair<T, T> &a, pair<T, T> b)
{
    a.fr -= b.fr;
    a.sc -= b.sc;
    return a;
}
template <typename T>
pair<T, T> operator+(pair<T, T> a, pair<T, T> b)
{
    a.fr += b.fr;
    a.sc += b.sc;
    return a;
}
template <typename T>
pair<T, T> operator-(pair<T, T> a, pair<T, T> b)
{
    a.fr -= b.fr;
    a.sc -= b.sc;
    return a;
}
template <typename T, typename T1>
T amax(T &a, T1 b)
{
    if (b > a)
        a = b;
    return a;
}
template <typename T, typename T1>
T amin(T &a, T1 b)
{
    if (b < a)
        a = b;
    return a;
}

const int N = 0;

int flag;
set<int> g[26];
int vis[26];
string ans;
void dfs(int z, int p)
{
    vis[z] = 1;
    ans.pb((char)('a' + z));
    for (int x : g[z])
    {
        if (x == p)
            continue;
        if (vis[x])
        {
            flag = 1;
            return;
        }
        dfs(x, z);
        if (flag == 1)
            return;
    }
}

void solve()
{
    flag = 0;
    rep(i, 0, 26)
    {
        g[i].clear();
        vis[i] = 0;
    }
    ans.clear();
    string s;
    cin >> s;
    rep(i, 1, sz(s))
    {
        int x = s[i] - 'a';
        int y = s[i - 1] - 'a';
        g[x].insert(y);
        g[y].insert(x);
    }
    rep(i, 0, 26)
    {
        //deg[node]>2
        if (sz(g[i]) > 2)
        {
            cout << "NO\n";
            return;
        }
        //if not in graph add it to ans
        if (sz(g[i]) == 0)
            ans.pb((char)('a' + i));
        if (sz(g[i]) == 1 && !vis[i])
        {
            dfs(i, i);
            if (flag == 1)
            {
                cout << "NO\n";
                return;
            }
        }
    }
    if (sz(ans) < 26)
    {
        cout << "NO\n";
        return;
    }
    cout << "YES\n"
         << ans << "\n";
}
signed main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    int t = 1;
    cin >> t;
    while (t--)
        solve();
    return 0;
}
