#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const ll INF = 1e9 + 7;
const ll MOD = 998244353;
typedef pair<ll, ll> ii;
#define iii pair<ll, ii>
#define f(i, a, b) for (int i = a; i < b; i++)
#define pb push_back
#define vll vector<ll>
#define F first
#define S second
#define all(x) (x).begin(), (x).end()
int main(void)
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int t;
    cin >> t;
    while (t--)
    {
        ll n;
        cin >> n;
        char c;
        cin >> c;
        string s;
        cin >> s;
        vector<int> ans;
        bool ok = true;
        for (auto x : s)
        {
            if (x != c)
            {
                ok = false;
            }
        }
        if (!ok)
        {
            f(i, 1, n + 1)
            {
                ok = true;
                f(j, i, n + 1)
                {
                    ok &= (s[j - 1] == c);
                    j += i - 1;
                }
                if (ok)
                {
                    ans.pb(i);
                    break;
                }
            }
            if (!ok)
            {
                ans.pb(n);
                ans.pb(n - 1);
            }
        }
        cout << ans.size() << "\n";
        for (auto x : ans)
        {
            cout << x << " ";
        }
        cout << "\n";
    }
}