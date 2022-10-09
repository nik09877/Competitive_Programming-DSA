#include <bits/stdc++.h>

using namespace std;

const int N = (int)1e5 + 123;
const int C = 101;
const int P = 11;

int n, q, c;
int cnt[P][C][C];


//EDITORIAL
// The brightness of the i-th star in moment t is , where  is modulo operator.

// Let's precalc for each p = 0...С, x = 1...100, y = 1...100 cnt[p][x][y] — the number of stars with the initial brightness p in the rectangle (1; 1)-(x; y). It is calculated like calcuating of partial sums: cnt[p][x][y] = cnt[p][x - 1][y] + cnt[p][x][y - 1] - cnt[p][x - 1][y - 1] + (the number of stars in the point (x;y) with the initial brightness p).

// Then the total brightness of stars at the i-th view is , where  is the number of stars with the initial brightness p in the given rectangle. This number can be calculated using array , using the inclusion-exclusion principle: amount(p, x1, y1, x2, y2) = cnt[p][x2][y2] - cnt[p][x1 - 1][y2] - cnt[p][x2][y1 - 1] + cnt[p][x1 - 1][y1 - 1].

// Let X is the maximum coordinate. Time complexity: O(n + qc + cX2). Memory complexity: O(cX2).
int main()
{
    scanf("%d%d%d", &n, &q, &c);
    for (int i = 0; i < n; i++)
    {
        int x, y, s;
        scanf("%d%d%d", &x, &y, &s);
        cnt[s][x][y]++;
    }

    for (int p = 0; p <= c; p++)
    {
        for (int i = 1; i < C; i++)
        {
            for (int j = 1; j < C; j++)
            {
                cnt[p][i][j] += cnt[p][i - 1][j] + cnt[p][i][j - 1] - cnt[p][i - 1][j - 1];
            }
        }
    }

    for (int i = 0; i < q; i++)
    {
        int t, x1, y1, x2, y2;
        scanf("%d%d%d%d%d", &t, &x1, &y1, &x2, &y2);
        int ans = 0;
        for (int p = 0; p <= c; p++)
        {
            int brightness = (p + t) % (c + 1);
            int amount = cnt[p][x2][y2] - cnt[p][x1 - 1][y2] - cnt[p][x2][y1 - 1] + cnt[p][x1 - 1][y1 - 1];
            ans += brightness * amount;
        }
        printf("%d\n", ans);
    }

    return 0;
}