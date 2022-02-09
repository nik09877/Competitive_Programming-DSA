#include <bits/stdc++.h>

using namespace std;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int tt;
    cin >> tt;
    while (tt--)
    {
        int l, r, k;
        cin >> l >> r >> k;
        if (l == r)
        {
            if (l == 1)
            {
                cout << "NO\n";
                continue;
            }
            else
            {
                cout << "YES\n";
                continue;
            }
        }
        int even = r / 2 - (l - 1) / 2;
        int odd = r - l + 1 - even;
        cout << (odd > k ? "NO\n" : "YES\n");
    }
    return 0;
}