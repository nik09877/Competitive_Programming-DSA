#include <bits/stdc++.h>
#define len(s) (int)s.size()
using namespace std;
using ll = long long;

void solve()
{
    int n, k;
    cin >> n >> k;
    vector<ll> a(n);
    ll sum = 0;
    for (int i = 0; i < n; i++)
    {
        cin >> a[i];
        sum += a[i] / k;
        a[i] = a[i] % k;
    }
    sort(a.begin(), a.end(), [](int x, int y)
         { return x > y; });

    for (int i = 0, j = n - 1; i < j; i++, j--)
    {
        while (a[i] + a[j] < k && i < j)
            j--;
        if (i == j)
            break;
        sum++;
    }
    cout << sum << endl;
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