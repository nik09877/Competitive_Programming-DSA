#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const ll INF = 1e9 + 7;
const ll MOD = 998244353;
typedef pair<ll, ll> ii;
#define iii pair<ll, ii>
#define f(i, a, b) for (ll i = a; i < b; i++)
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
        ll n, k;
        cin >> n >> k;
        ll p = 1;
        ll ans = 0;
        f(j, 0, 31)
        {
            if (k & (1 << j))
            {
                ans = (ans + p) % INF;
            }
            p *= n;
            p %= INF;
        }
        cout << ans << "\n";
    }
}