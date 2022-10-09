#include <bits/stdc++.h>

using namespace std;

void dbg_out() { cerr << endl; }
template <typename Head, typename... Tail>
void dbg_out(Head H, Tail... T)
{
    cerr << ' ' << H;
    dbg_out(T...);
}
#define dbg(...) cerr << "(" << #__VA_ARGS__ << "):", dbg_out(__VA_ARGS__)

using ll = long long;

template <typename S, typename T>
void smax(S &a, const T &b)
{
    if (a < b)
        a = b;
}
template <typename S, typename T>
void smin(S &a, const T &b)
{
    if (a > b)
        a = b;
}

#define rng_init mt19937 rng(chrono::steady_clock::now().time_since_epoch().count())
#define rng_seed(x) mt19937 rng(x)
#define all(x) (x).begin(), (x).end()
#define sz(x) (int)(x).size()
// #define int long long

const int MXN = 1e5 + 5, INF = 1e9 + 5;
int N;
string A[MXN];

bool isPalin(const string &s)
{
    for (int i = 0; i < sz(s) / 2; i++)
        if (s[i] != s[sz(s) - i - 1])
            return false;

    return true;
}

bool check()
{
    map<string, bool> present;
    map<string, bool> present_2;

    for (int i = 0; i < N; i++)
    {
        string rev = A[i];
        reverse(all(rev));
        if (present[rev])
            return true;
        if (present_2[A[i]])
            return true;

        if (sz(A[i]) == 3)
        {
            string cur2 = "";
            cur2 += A[i][1];
            cur2 += A[i][0];
            present_2[cur2] = true;

            string cur = "";
            cur += A[i][2];
            cur += A[i][1];

            if (present[cur])
                return true;
        }

        present[A[i]] = true;
    }

    return false;
}

void solve()
{
    cin >> N;

    for (int i = 0; i < N; i++)
        cin >> A[i];

    for (int i = 0; i < N; i++)
    {
        if (isPalin(A[i]))
        {
            cout << "YES\n";
            return;
        }
    }

    if (check())
    {
        cout << "YES\n";
        return;
    }

    cout << "NO\n";
}

signed main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int TC = 1;
    cin >> TC;
    while (TC--)
        solve();
}