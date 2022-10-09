#include <bits/stdc++.h>
using namespace std;

//for m cheap items we need m+1 most expensive items ie total 2*m+1
bool good(int m, vector<int> &a, int n)
{
    if (2 * m + 1 > n)
        return false;

    vector<int> b;
    int down_pos = 0, peek_pos = n - (m + 1);
    for (int i = 0; i < 2 * m + 1; ++i)
    {
        if (i % 2 == 0)
        {
            b.emplace_back(a[peek_pos]);
            ++peek_pos;
        }
        else
        {
            b.emplace_back(a[down_pos]);
            ++down_pos;
        }
    }
    for (int i = 1; i < 2 * m + 1; i += 2)
    {
        if (b[i] >= b[i - 1] or b[i] >= b[i + 1])
            return false;
    }
    return true;
}
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int n;
    cin >> n;
    vector<int> a(n);
    for (int i = 0; i < n; ++i)
    {
        cin >> a[i];
    }
    sort(a.begin(), a.end());

    int l = 0, r = n + 1, ans = -1;
    while (l <= r)
    {
        int m = (l + r) / 2;
        if (good(m, a, n))
        {
            ans = m;
            l = m + 1;
        }
        else
            r = m - 1;
    }
    cout << ans << endl;
    vector<int> b;
    int down_pos = 0, peek_pos = n - (ans + 1);
    for (int i = 0; i < 2 * ans + 1; ++i)
    {
        if (i % 2 == 0)
        {
            b.emplace_back(a[peek_pos]);
            ++peek_pos;
        }
        else
        {
            b.emplace_back(a[down_pos]);
            ++down_pos;
        }
    }
    for (int i = down_pos; i < n - (ans + 1); ++i)
    {
        b.emplace_back(a[i]);
    }
    for (auto &c : b)
    {
        cout << c << " ";
    }
}