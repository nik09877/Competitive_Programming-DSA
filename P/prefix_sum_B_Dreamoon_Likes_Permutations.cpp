#include <bits/stdc++.h>
#define int long long
using namespace std;

signed main()
{
    ios ::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    int t;
    cin >> t;

    while (t--)
    {
        int n;
        cin >> n;

        vector<int> a(n + 1);
        int all = 0;
        for (int i = 1; i <= n; i++)
            cin >> a[i], all += a[i];

        int sum = 0;
        vector<pair<int, int>> ans;
        vector<int> raz_pref(n + 1, 0), raz_suf(n + 2, 0);

        map<int, int> cnt1, cnt2;

        for (int i = 1; i <= n; i++)
        {
            raz_pref[i] += raz_pref[i - 1];
            if (cnt1[a[i]] == 0)
            {
                raz_pref[i]++;
            }
            cnt1[a[i]]++;
        }

        for (int i = n; i >= 1; i--)
        {
            raz_suf[i] += raz_suf[i + 1];
            if (cnt2[a[i]] == 0)
            {
                raz_suf[i]++;
            }
            cnt2[a[i]]++;

            //cout << "raz_suf " << i << " " << raz_suf[i]<<'\n';
        }

        for (int l1 = 1; l1 < n; l1++)
        {
            sum += a[l1];
            if (raz_pref[l1] == l1 && raz_suf[l1 + 1] == n - l1 && sum == l1 * (l1 + 1) / 2 && (all - sum) == (n - l1) * (n - l1 + 1) / 2)
            {
                ans.push_back({l1, n - l1});
            }
        }

        cout << (int)ans.size() << '\n';
        for (auto u : ans)
            cout << u.first << " " << u.second << '\n';
    }
}