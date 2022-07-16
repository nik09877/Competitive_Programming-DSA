#include <bits/stdc++.h>

using namespace std;

int main()
{
#ifdef _DEBUG
    freopen("input.txt", "r", stdin);
//  freopen("output.txt", "w", stdout);
#endif

    int tc;
    scanf("%d", &tc);
    while (tc--)
    {
        int n;
        scanf("%d", &n);
        vector<int> h(n);
        for (auto &it : h)
        {
            scanf("%d", &it);
        }

        int mx = *max_element(h.begin(), h.end());
        long long ans = 1e18;
        for (auto need : {mx, mx + 1})
        {
            long long l = 0, r = 1e18;
            long long res = -1;
            while (l <= r)
            {
                long long mid = (l + r) >> 1;
                long long cnt1 = (mid + 1) / 2, cnt2 = mid - cnt1;
                long long need1 = 0;
                for (auto ch : h)
                {
                    long long cur = (need - ch) / 2;
                    if ((need - ch) % 2 == 1)
                    {
                        ++need1;
                    }
                    if (cnt2 >= cur)
                    {
                        cnt2 -= cur;
                    }
                    else
                    {
                        cur -= cnt2;
                        cnt2 = 0;
                        need1 += cur * 2;
                    }
                }
                if (need1 <= cnt1)
                {
                    res = mid;
                    r = mid - 1;
                }
                else
                {
                    l = mid + 1;
                }
            }
            ans = min(ans, res);
        }

        printf("%lld\n", ans);
    }

    return 0;
}