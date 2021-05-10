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

void prettyPrint(int A)
{
    int n = 2 * A - 2;
    vector<vector<int>> a(n + 1, vector<int>(n + 1));
    int top = 0, bottom = n, left = 0, right = n;
    while (top <= bottom and left <= right)
    {
        for (int i = 0; i < 4; i++)
        {
            if (i == 0) //L->R
            {
                for (int j = left; j <= right; j++)
                {
                    a[top][j] = A;
                }
                top++;
            }
            if (i == 1) //U->D
            {
                for (int j = top; j <= bottom; j++)
                {
                    a[j][right] = A;
                }
                right--;
            }
            if (i == 2) //R->L
            {
                for (int j = right; j >= left; j--)
                {
                    a[bottom][j] = A;
                }
                bottom--;
            }
            if (i == 3) //D->U
            {
                for (int j = bottom; j >= top; j--)
                {
                    a[j][left] = A;
                }
                left++;
            }
        }
        A--;
    }
    fo(i, 0, n)
    {
        fo(j, 0, n)
        {
            prsp(a[i][j]);
        }
        cout << endl;
    }
}
void solve()
{
    int n;
    cin >> n;
    prettyPrint(n);
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
