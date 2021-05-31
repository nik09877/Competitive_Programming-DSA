#include <bits/stdc++.h>
#define ll double
#define fr(a, b) for (int i = a; i < b; i++)
#define mod 1000000007
#define triplet pair<int, pair<int, int>>
#define fast_io                       \
    ios_base::sync_with_stdio(false); \
    cin.tie(NULL)
using namespace std;
/*EDITORIAL
First : what really matters is the number of dishes with 0, 1, 2 and 3 sushis and not the order of the dishes.
So answer for 2,1,0,2,1 is same as answer for 0,1,1,2,2.

Number of dishes with 0 sushis is easily determined by N - one - two - three, where one is the number of dishes with 1 sushi and N is the total number of dishes in the input.

Let F(x, y, z) be the expected moves needed for x dishes with 1 sushi, y with 2 and z with 3.

Now in the next move we can pick a dish with 1 sushi with a probability of x/N or p1. we can pick a dish with 2 sushi with a probability of y/N or p2. we can pick a dish with 3 sushi with a probability of z/N or p3. we can pick a dish with 0 sushi with a probability of (N - (x + y + z))/N or p0.

Now try to understand this :
F(x,y,z) = 1 + p0F(x,y,z) + p1F(x-1,y,z) + p2F(x+1,y-1,z) + p3F(x,y+1,z-1)

Here we add a 1 for the current move that we are making.
(Note : if you pick a dish with 3 sushi z decreases but y increases)

This equation now becomes :
(1 - p0) F(x,y,z) = 1 + p1F(x-1,y,z) + p2F(x+1,y-1,z) + p3*F(x,y+1,z-1)

simplifies to:
F(x,y,z) = (1+p1F(x-1,y,z) + p2F(x+1,y-1,z) + p3*F(x,y+1,z-1))/(1-p0)

This equation can be easily evaluated using dynamic programming :slight_smile:
However try and simplify the equation to minimize the number of divisions for higher precision.*/

ll dp[301][301][301];
ll solve(int one, int two, int three, int &n)
{
    if (one < 0 || two < 0 || three < 0)
        return 0;
    if (three == 0 && two == 0 && one == 0)
        return 0;

    if (dp[one][two][three] > 0)
        return dp[one][two][three];

    int remaining = one + two + three;
    ll exp_val = n + one * solve(one - 1, two, three, n) + two * solve(one + 1, two - 1, three, n) +
                 three * solve(one, two + 1, three - 1, n);

    return dp[one][two][three] = exp_val / remaining;
}

int main()
{
    int i, j, t, n, m, p, k;
    fast_io;
    cin >> n;
    int one = 0, two = 0, three = 0;
    fr(0, n)
    {
        int x;
        cin >> x;
        if (x == 1)
            one++;
        else if (x == 2)
            two++;
        else
            three++;
    }

    memset(dp, -1, sizeof dp);
    cout << fixed << setprecision(9) << solve(one, two, three, n);
    return 0;
}
