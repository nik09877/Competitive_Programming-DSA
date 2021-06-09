// #include <bits/stdc++.h>
// #include <unordered_map>

// using namespace std;
// /*
// EDITORIAL
// Firstly you make two types of edges, {1, 2} and {3, 4 ,5 ,6}, and you can see that with edges {1, 2} you can only continue on the line that you are, going to the next column, and with edges {3 ,4 ,5, 6} you go to the next column changing your line (see the picture above).

// If there is a path, then there is only one of them, by the "nature" of the edges, so the complexity is O(n).
// */
// int n;
// int visited[2][2 * 100007];
// int a[2][2 * 100007];

// int q;
// char t;
// //dir is the direction we need to go
// void dfs(int r, int c, char dir)
// {
//     if (r < 0 || r > 1 || c < 0 || c > n || visited[r][c] == q)
//         return;
//     visited[r][c] = q;
//     if (c == n)
//         return;
//     if ((a[r][c] == 0 || a[r][c] == 1))
//     {
//         if (dir == 'R')
//         {
//             dfs(r, c + 1, 'R');
//         }
//     }
//     else if (dir == 'R')
//     {
//         dfs(r + 1, c, 'U');
//         dfs(r - 1, c, 'D');
//     }
//     else if (dir == 'U')
//     {
//         dfs(r, c + 1, 'R');
//     }
//     else if (dir == 'D')
//     {
//         dfs(r, c + 1, 'R');
//     }
// }
// int main()
// {
//     cin >> q;

//     while (q > 0)
//     {
//         cin >> n;
//         for (int j = 0; j < 2; j++)
//             for (int i = 0; i < n; i++)
//             {
//                 cin >> t;
//                 int temp = t - '1';
//                 a[j][i] = temp;
//             }
//         dfs(0, 0, 'R');
//         if (visited[1][n] == q)
//             cout << "YES" << endl;
//         else
//             cout << "NO" << endl;
//         q--;
//     }

//     return 0;
// }

#include <bits/stdc++.h>
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
#define fastio ios_base::sync_with_stdio(0), cin.tie(0)
#define re(a, n)   \
    rep(i, n)      \
            cin >> \
        a[i];
using namespace std;

// EDITORIAL
//  you can see that with edges {1, 2} you can only continue on the line that you are, going to the next column, and with edges {3 ,4 ,5, 6} you go to the next column changing your line
void solve()
{
    int n;
    string s[2];
    cin >> n;
    cin >> s[0] >> s[1];
    vector<vector<bool>> dp(2, vector<bool>(n + 1, false));

    dp[0][0] = true;
    rep(i, n)
    {
        //move right without changing row
        if (s[0][i] <= '2')
        {
            dp[0][i + 1] = dp[0][i + 1] || dp[0][i];
        }
        //move right without changing row
        if (s[1][i] <= '2')
        {
            dp[1][i + 1] = dp[1][i + 1] || dp[1][i];
        }

        //the only way to move right or down is by changing line and to change line we need {3,4,5,6} on both rows
        else if (s[0][i] > '2' and s[1][i] > '2')
        {
            //IMP OBSERVATION
            dp[0][i + 1] = dp[0][i + 1] || dp[1][i];
            dp[1][i + 1] = dp[1][i + 1] || dp[0][i];
        }
    }
    if (dp[1][n])
        yes;
    else
        no;
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