#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using vb = vector<bool>;
using vvb = vector<vb>;
using vi = vector<int>;
using vvi = vector<vi>;
using vl = vector<ll>;
using vvl = vector<vl>;
using vc = vector<char>;
using vvc = vector<vc>;
using vs = vector<string>;
const ll mod = 1e9 + 7, inf = 1e18;
#define pb push_back
#define fast                      \
    ios_base::sync_with_stdio(0); \
    cin.tie(0);                   \
    cout.tie(0);
void setIO()
{
    fast;
#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif
}
int main()
{
    setIO();
    int t;
    cin >> t;
    while (t--)
    {
        int n;
        cin >> n;

        priority_queue<pair<int, int>> q;
        int ans = 0;
        for (int i = 1; i <= n; i++)
        {
            int a;
            cin >> a;
            q.push({a, i});
        }

        vector<pair<int, int>> ret;

        while ((int)q.size() >= 2)
        {
            int best1 = q.top().first, pos1 = q.top().second;
            q.pop();
            int best2 = q.top().first, pos2 = q.top().second;
            q.pop();
            if (best1 >= 1 and best2 >= 1)
            {
                q.push({best1 - 1, pos1});
                q.push({best2 - 1, pos2});
                ret.push_back({pos1, pos2});
                ans++;
            }
        }

        cout << ans << endl;

        for (auto it : ret)
            cout << it.first << " " << it.second << endl;
    }
    return 0;
}