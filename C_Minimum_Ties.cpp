#include <bits/stdc++.h>
using namespace std;
typedef long long int ll;
map<char, ll> mp;

void solve()
{
    ll n, k, l;
    cin >> n;
    vector<vector<int>> mat(n + 1, vector<int>(n + 1));
    if (n % 2)
    {
        for (int i = 1; i <= n; i += 1)
        {
            int l = 0;
            for (int j = i + 1; j <= n; j++)
            {
                if (l % 2 == 0)
                {
                    mat[i][j] = 1;
                    mat[j][i] = -1;
                }
                else
                {
                    mat[i][j] = -1;
                    mat[j][i] = 1;
                }
                l++;
            }
        }
    }
    else
    {
        for (int i = 1; i <= n; i += 2)
        {
            mat[i][i + 1] = 0;
            mat[i + 1][i] = 0;
            l = 0;
            for (int j = i + 2; j <= n; j++)
            {
                if (l % 2)
                {
                    mat[i][j] = 1;
                    mat[i + 1][j] = -1;
                }
                else
                {
                    mat[i][j] = -1;
                    mat[i + 1][j] = 1;
                }
                l++;
            }
        }
    }
    for (int i = 1; i <= n; i++)
    {
        for (int j = i + 1; j <= n; j++)
        {
            cout << mat[i][j] << " ";
        }
    }
    cout << endl;
}

int main()
{
    ll t = 1;
    cin >> t;

    while (t--)
    {
        solve();
    }
    return 0;
}