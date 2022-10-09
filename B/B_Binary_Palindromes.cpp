#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define ull unsigned long long
#define jaldi_chal                \
    ios_base::sync_with_stdio(0); \
    cin.tie(0);
#define tr(c, i) for (auto i = (c).begin(); i != (c).end(); i++)
#define REP(i, k) for (ll i = 0; i < k; i++)
#define REW(i, a, b) for (ll i = a; i <= b; i++)
#define MOD 1000000007
#define F first
#define dbg(x) cout << #x << " " << x << endl;
#define S second
#define inf 1e10
#define endl "\n"
#define setbit(n) __builtin_popcount(n)
#define all(x) x.begin(), x.end()
#define clr(x) memset(x, 0, sizeof(x))
ll power(ll a, ll b);

int main()
{

#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif
    jaldi_chal
        ll t = 1,
           i;
    cin >> t;
    while (t--)
    {
        ll n;
        cin >> n;
        ll cnt = 0;
        ll ans = 0;
        string s;
        ll flag = 0;

        REW(i, 1, n)
        {
            cin >> s;
            if (s.size() % 2)
            {
                ans++;

                flag = 1;
            }
            else
            {
                ll count = 0;

                for (ll i = 0; i < s.size(); i++)
                {
                    if (s[i] == '1')
                        count++;
                }

                if (count % 2 == 0)
                    ans++;
                else
                    cnt++;
            }
        }

        if (cnt % 2 == 0)
            ans += cnt;
        else
        {
            if (flag)
                ans += cnt;
            else
                ans += cnt - 1;
        }

        cout << ans << endl;
    }

    return 0;
}

ll power(ll a, ll b)
{
    ll res = 1;
    while (b)
    {
        if (b % 2)
            b--, res = res * a;
        else
            b = b / 2, a *= a;
    }
    return res;
}