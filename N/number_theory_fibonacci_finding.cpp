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
lli a, b, n;

void mul(lli A[3][3], lli B[3][3], lli dim)
{
    lli res[dim + 1][dim + 1];
    rep1(i, dim)
    {
        rep1(j, dim)
        {
            res[i][j] = 0;
            rep1(k, dim)
            {
                lli x = (A[i][k] * B[k][j]) % mod;
                res[i][j] = (res[i][j] + x) % mod;
            }
        }
    }
    rep1(i, dim)
    {
        rep1(j, dim)
        {
            A[i][j] = res[i][j];
        }
    }
}
void solve()
{
    cin >> a >> b >> n;
    n++; //1 based indexing
    lli A[3][3], I[3][3], F[3];

    F[1] = a, F[2] = b;

    I[1][1] = I[2][2] = 1;
    I[1][2] = I[2][1] = 0;

    A[1][1] = 0, A[1][2] = 1;
    A[2][1] = 1, A[2][2] = 1;

    n--;
    while (n > 0)
    {
        if (n % 2)
        {
            mul(I, A, 2);
            n--;
        }
        else
        {
            mul(A, A, 2);
            n /= 2;
        }
    }
    rep1(i, 2)
    {
        rep1(j, 2)
        {
            A[i][j] = I[i][j];
        }
    }
    cout << (F[1] * A[1][1] + F[2] * A[2][1]) % mod << endl;
    return;
}
int32_t main()
{
    fastio;
    int t = 1;
    cin >> t;
    while (t--)
    {
        solve();
    }
}