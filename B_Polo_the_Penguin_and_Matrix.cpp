#include <bits/stdc++.h>
using namespace std;
typedef long long l;
int main()
{
    l n, m, d;
    cin >> n >> m >> d;
    n *= m;
    l a[n];
    for (l i = 0; i < n; ++i)
        cin >> a[i];
    sort(a, a + n);
    l md = n / 2, move = 0;
    for (l i = 0; i < n; ++i)
    {
        if (abs(a[md] - a[i]) % d != 0)
        {
            cout << "-1" << endl;
            exit(0);
        }
        move += abs(a[md] - a[i]) / d;
    }
    cout << move << endl;
}