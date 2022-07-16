#include <bits/stdc++.h>
using namespace std;

void solve()
{
    int n;
    cin >> n;
    int a[n][n];
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            char c;
            cin >> c;
            a[i][j] = c - '0';
        }
    }
    int ans = 0;
    for (int i = 0; i < (n + 1) / 2; i++)
    {
        for (int j = 0; j < n / 2; j++)
        {
            int nowi = i, nowj = j;
            int oldnowj = nowj;
            int sum = a[nowi][nowj];
            nowj = n - nowi - 1;
            nowi = oldnowj;
            sum += a[nowi][nowj];
            oldnowj = nowj;
            nowj = n - nowi - 1;
            nowi = oldnowj;
            sum += a[nowi][nowj];
            oldnowj = nowj;
            nowj = n - nowi - 1;
            nowi = oldnowj;
            sum += a[nowi][nowj];
            ans += min(sum, 4 - sum);
        }
    }
    cout << ans << endl;
}

int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        solve();
    }
    return 0;
}