#include <bits/stdc++.h>
using namespace std;
#define intl long long int
intl dp[1000][5000];
//!Given a String "x=y" make x==y using minimum pluses
//! ex-> "111=12" 1+11 == 12 so ans=1 plus is required

intl min_plus(string &x, intl y, intl idx)
{

    if (y < 0)
        return INT_MAX;

    if (idx == x.length())
        return (y == 0 ? 0 : INT_MAX);

    if (dp[idx][y] != -1)
    {
        return dp[idx][y];
    }

    intl ans = INT_MAX;
    for (intl i = idx; i < min(idx + 4, (intl)x.length()); i++)
    {

        intl num = stoi(x.substr(idx, i - idx + 1));

        if (i < x.length() - 1)
        {
            ans = min(ans, min_plus(x, y - num, i + 1) + 1);
        }
        else
        {
            ans = min(ans, min_plus(x, y - num, i + 1));
        }
    }

    return dp[idx][y] = ans;
}

int main()
{
    memset(dp, -1, sizeof dp);

    string x;
    cin >> x;

    intl i = 0;
    while (x[i] != '=')
        i++;

    intl n = x.size();
    string x1 = x.substr(0, i);
    intl y = stoi(x.substr(i + 1, n - i));

    intl ans = min_plus(x1, y, 0);
    if (ans == INT_MAX)
        cout << -1;
    else
        cout << ans;

    return 0;
}