#include <cstring>
#include <iostream>
#include <vector>

using namespace std;

// I will describe the most intuitive solution.Naturally, looking at the constraints as well as at the output that is required, we can store a 3 - state dp : dp[n][k][2].Here, dp[n][k][d] indicates the total number of particles(at the end of the simulation) when one particle of decay age k hits the n - th plane in the direction d.(d is either 0 or 1, and indicates the direction(left / right) in which the particle is going)
// There can be two directions, N planes and maximum decay age is K.So, this dp requires 2×1000×1000×4 bytes ≈24MB which is well within our memory constraints.

//?Solution details How to update the DP states
//  If k = 1,
//  the value of dp[n][1][d] for any n or d is obviously 1(as no copies are produced).
//  So,let us consider a particle P with k > 1. This particle P produces a copy P′ going in the opposite direction.We can count the number of particles produced by P′ as dp[n - 1][k - 1][1 - d], as it hits the previous plane with a smaller decay age and in the opposite direction.Moreover, the particle P itself hits the next plane and continues to produce more stuff.We can calculate its number of particles produced as dp[n + 1][k][d], as it hits the next plane with the same decay age and the same direction !

//     Finally,
//          we can combine these two values to get the value of dp[n][k][d].

const int N = 1001;
const int K = 1001;

int n, k;
const int mod = 1e9 + 7;

int dp[N][K][2];

int solve(int curr, int k, int dir)
{
    if (k == 1)
    {
        return 1;
    }

    if (dp[curr][k][dir] != -1)
    {
        return dp[curr][k][dir];
    }

    int ans = 2; // me and my copy

    if (dir == 1)
    {
        if (curr < n)
            ans += solve(curr + 1, k, dir) - 1;

        ans %= mod;

        if (curr > 1)
            ans += solve(curr - 1, k - 1, 1 - dir) - 1;

        ans %= mod;
        dp[curr][k][dir] = ans;
    }
    else
    {
        if (curr > 1)
            ans += solve(curr - 1, k, dir) - 1;

        ans %= mod;

        if (curr < n)
            ans += solve(curr + 1, k - 1, 1 - dir) - 1;

        ans %= mod;
        dp[curr][k][dir] = ans;
    }

    return ans;
}

int main()
{
    int t;
    cin >> t;

    while (t--)
    {
        cin >> n >> k;
        memset(dp, -1, sizeof(dp));
        cout << solve(1, k, 1) << endl;
    }
}