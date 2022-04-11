#include <bits/stdc++.h>
#define REP(i, n) for (int i = 1; i <= n; i++)
#define mod 1000000007
#define pb push_back
#define ff first
#define ss second
#define ii pair<lli, lli>
#define vi vector<int>
#define vii vector<ii>
#define lli long long int
#define endl '\n'
const double PI = 3.141592653589793238460;
typedef std::complex<double> Complex;
typedef std::valarray<Complex> CArray;

using namespace std;
const lli INF = LONG_MAX;
struct subject
{
    lli a, b;
    int ioffset, c;
};
subject sb[101];

bool comp(subject a, subject b)
{
    return a.c < b.c;
}

lli dp[51][51][101];
ii pre[51][51][101];

// dp[i][j][offset] denotes maximum score we can get if we choose jth subject and a[j].a+offset score on ith day
//  the only way we can choose jth sub and offset if there exists on i-1th day such that a[pre_sub].complexity<a[j].complexity and a[pre_sub][score]+k == a[j][score] or a[pre_sub][score]*k = a[j][score]

int main()
{
    lli n, m, k;
    cin >> n >> m >> k;

    REP(i, m)
    cin >> sb[i].a >> sb[i].b >> sb[i].c,
        sb[i].ioffset = i;

    if (n == 1)
    {
        cout << "YES" << endl;
        ii other_part = {0, -1};
        REP(i, m)
        if (sb[i].b > other_part.ss)
            other_part = {i, sb[i].b};

        cout << other_part.ff << " " << other_part.ss;
        return 0;
    }

    sort(sb + 1, sb + 1 + m, comp);

    memset(dp, -1, sizeof dp);
    for (int j = 1; j <= m; j++)
    {
        for (int offset = 0; offset <= sb[j].b - sb[j].a; offset++)
            dp[1][j][offset] = sb[j].a + offset;
    }

    ii finalRes = {0, -1};
    lli maximum = -1;

    for (int i = 2; i <= n; i++)
    {
        for (int j = i; j <= m; j++)
        {

            for (int offset = 0; offset <= sb[j].b - sb[j].a; offset++)
            {
                lli other_part = -1;
                ii tmp = {0, -1};

                lli pre_score_1 = -1, pre_score_2 = -1;
                if ((sb[j].a + offset) % k == 0)
                    pre_score_2 = (sb[j].a + offset) / k;

                if (sb[j].a + offset > k)
                    pre_score_1 = sb[j].a + offset - k;

                for (int pre_sub = 1; pre_sub < j; pre_sub++)
                {
                    if (sb[pre_sub].c == sb[j].c)
                        continue;

                    if (pre_score_1 > 0 && (pre_score_1 >= sb[pre_sub].a && pre_score_1 <= sb[pre_sub].b))
                    {
                        if (other_part < dp[i - 1][pre_sub][pre_score_1 - sb[pre_sub].a])
                            other_part = dp[i - 1][pre_sub][pre_score_1 - sb[pre_sub].a], tmp = {pre_sub, pre_score_1 - sb[pre_sub].a};
                    }

                    if (pre_score_2 > 0 && (pre_score_2 >= sb[pre_sub].a && pre_score_2 <= sb[pre_sub].b))
                    {
                        if (other_part < dp[i - 1][pre_sub][pre_score_2 - sb[pre_sub].a])
                            other_part = dp[i - 1][pre_sub][pre_score_2 - sb[pre_sub].a], tmp = {pre_sub, pre_score_2 - sb[pre_sub].a};
                    }
                }

                if (other_part == -1)
                    dp[i][j][offset] = -1;
                else
                {
                    dp[i][j][offset] = other_part + sb[j].a + offset;
                    pre[i][j][offset] = tmp;

                    if (i == n && dp[i][j][offset] > maximum)
                        finalRes = {j, offset}, maximum = dp[i][j][offset];
                }
            }
        }
    }

    if (finalRes.ss == -1)
        cout << "NO";
    else
    {
        cout << "YES" << endl;
        vii res;

        int i = n;
        while (i > 0)
        {
            res.pb({sb[finalRes.ff].ioffset, sb[finalRes.ff].a + finalRes.ss});
            int pre_sub = finalRes.ff;
            int offset = finalRes.ss;

            finalRes = pre[i][pre_sub][offset], i--;
        }

        reverse(res.begin(), res.end());
        for (ii p : res)
            cout << p.ff << " " << p.ss << endl;
    }
}
