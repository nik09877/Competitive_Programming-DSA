
#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define FAST1 ios_base::sync_with_stdio(false);
#define FAST2 cin.tie(NULL);
#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define FAST1 ios_base::sync_with_stdio(false);
#define FAST2 cin.tie(NULL);

ll power(ll x, ll y, ll mod)
{
    if (y == 0)
        return 1;
    ll val = power(x, y / 2, mod);
    if (y % 2 == 1)
        return (val * val * x) % mod;
    return (val * val) % mod;
}
ll gcd(ll a, ll b)
{
    while (b)
    {
        ll c = b;
        b = a % b;
        a = c;
    }
    return a;
}
void solve()
{
    ll n, a, b;
    cin >> n >> a >> b;
    if (b == 1)
    {
        cout << "Yes" << endl;
        return;
    }
    if (a == 1)
    {
        if ((n - 1) % b == 0)
            cout << "Yes" << endl;
        else
            cout << "No" << endl;
        return;
    }
    ll flag = 0;
    ll f = 1;
    while (f <= n)
    {
        if ((n - f) % b == 0)
            flag = 1;
        f *= a;
    }
    if (flag)
        cout << "Yes" << endl;
    else
        cout << "No" << endl;
}

int32_t main()
{
    FAST1;
    FAST2;
    ll t = 1;
    cin >> t;
    while (t--)
    {
        solve();
    }
}

// ll n, a, b;
// cin >> n >> a >> b;
// vector<ll> v;
// v.push_back(1 * a);
// v.push_back(1 + b);
// ll s = 3;
// ll flag = 0;
// for (ll i = 1; i < s; i++)
// {

//     if (i & 1)
//     {
//         v.push_back(v[i] * a);
//         v.push_back(v[i] + b);
//         if (v[i] * a == n || v[i] + b == n)
//         {
//             flag = 1;
//             break;
//         }
//     }
//     else
//     {
//         v.push_back(v[i] * a);
//         v.push_back(v[i] + b);
//         if (v[i] + b == n || v[i] + b == n)
//         {
//             flag = 1;
//             break;
//         }
//     }
//     if (v[i] > n)
//         break;
//     s = v.size();
// }
// if (flag)
//     cout << "YES" << endl;
// else
//     cout << "NO" << endl;