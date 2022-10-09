#include <bits/stdc++.h>

using namespace std;

void solve()
{
    int n;
    cin >> n;
    int a[n];
    int index_of_max_val = 0;
    for (int i = 0; i < n; i++)
    {
        cin >> a[i];
        index_of_max_val = (a[i] > a[index_of_max_val] ? i : index_of_max_val);
    }
    vector<int> ans(n);
    ans[0] = a[index_of_max_val];
    a[index_of_max_val] = 0;
    int gcd_so_far = ans[0];
    for (int i = 1; i < n; i++)
    {
        int target_index = 0, mx_gcd = 0;
        for (int j = 0; j < n; j++)
            if (a[j] && __gcd(a[j], gcd_so_far) > mx_gcd)
            {
                mx_gcd = __gcd(a[j], gcd_so_far);
                target_index = j;
            }
        ans[i] = a[target_index];
        gcd_so_far = mx_gcd;
        a[target_index] = 0;
    }
    for (int i = 0; i < n; i++)
        cout << ans[i] << ' ';
    cout << '\n';
}

int main()
{
    int t;
    cin >> t;
    while (t--)
        solve();
    return 0;
}