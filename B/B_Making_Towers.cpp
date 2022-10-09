#include "bits/stdc++.h"

using namespace std;

#define ll long long
const int MAXN = 100100;

int t, n;
vector<int> a[MAXN];

int solve(int x)
{

    if (!a[x].size())
        return 0;

    int curr = a[x][0];
    int ans = 1;

    for (int i : a[x])
    {
        if ((i & 1) != (curr & 1))
        {
            ans++;
            curr = i;
        }
    }

    return ans;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    cin >> t;
    while (t--)
    {

        cin >> n;

        for (int i = 1; i <= n; i++)
            a[i].clear();

        for (int i = 1; i <= n; i++)
        {
            int x;
            cin >> x;
            a[x].push_back(i);
        }

        for (int i = 1; i <= n; i++)
            cout << solve(i) << " \n"[i == n];
    }
}