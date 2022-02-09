#include <iostream>
#include <fstream>
#include <string>
#include <sstream>
#include <iomanip>

#include <algorithm>
#include <list>
#include <vector>
#include <stack>
#include <deque>
#include <queue>
#include <set>
#include <map>
#include <bitset>
#include <numeric>

#include <math.h>
#include <stdlib.h>
#include <assert.h>
#include <limits.h>
#include <memory.h>
#include <ctype.h>
#include <string.h>
using namespace std;

typedef long long lint;

#define elin '\n'

#define rep(i, a, n) for (int i = a; i <= n; i++)

#define MAX5 100005

#define MOD7 1000000007

lint addm(lint x, lint y, lint m)
{
    lint ans = x + y;
    if (ans >= m)
        ans -= m;
    return ans;
}

lint dp[2][2 * MAX5];

class Solution
{
public:
    void solve(std::istream &in, std::ostream &out)
    {
        int r, g;
        in >> r >> g;
        int rg = r + g;

        // find structure of max height such that h*(h+1)/2 <= r+g
        // h + h-1 + h-2 + ... + 1 = h*(h+1)/2 <= r+g
        int h = 1;
        while (true)
        {
            lint hh = h + 1;
            if (hh * (hh + 1) / 2 <= rg)
                h++;
            else
                break;
        }

        // dp[i][j] denotes the no of ways we can build the structure of height i such that we have used j red boxes so far

        dp[0][0] = 1;
        int t;
        rep(i, 1, h)
        {
            t = (i & 1);
            memset(dp[t], 0, sizeof(dp[t]));
            rep(j, 0, r)
            {
                // fill this level with red boxes
                if (j >= i)
                    dp[t][j] = addm(dp[t][j], dp[t ^ 1][j - i], MOD7);

                // fill this level with green boxes
                int green_boxes_used_so_far = (((i - 1) * i / 2) - j);
                int green_boxes_left_to_use = g - green_boxes_used_so_far;

                if (green_boxes_left_to_use >= i)
                    dp[t][j] = addm(dp[t][j], dp[t ^ 1][j], MOD7);
            }
        }
        lint ans = 0;
        rep(i, 0, r) ans = addm(ans, dp[t][i], MOD7);
        out << ans << elin;
        return;
    }
};

void solve(std::istream &in, std::ostream &out)
{
    out << std::setprecision(12);
    Solution solution;
    solution.solve(in, out);
}

int main()
{

    ios_base::sync_with_stdio(0);
    cin.tie(0);

    istream &in = cin;

    ostream &out = cout;

    solve(in, out);
    return 0;
}
