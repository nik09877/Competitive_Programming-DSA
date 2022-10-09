#include <stdio.h>
#include <stdlib.h>
#include <iostream>
#include <vector>
#include <algorithm>
#include <fstream>
#include <queue>
#include <deque>
#include <iomanip>
#include <cmath>
#include <set>
#include <stack>
#include <map>
#include <unordered_map>

#define FOR(i, n) for (int i = 0; i < n; i++)
#define FORE(i, a, b) for (int i = a; i <= b; i++)
#define ll long long
#define ld long double
//#define int ll
//#define int short
#define vi vector<int>
#define pb push_back
#define ff first
#define ss second
#define ii pair<int, int>
#define iii pair<int, ii>
#define iiii pair<iii, int>
#define pll pair<ll, ll>
#define plll pair<ll, pll>
//#define mp make_pair
#define vv vector
#define endl '\n'

using namespace std;

const int MAXN = 200 * 1000 + 5;
const int MAXT = 263 * 1000;

// if s[i]!=s[i-1]
// 2 choices
// take it or not take it
// dp[i]=max(dp[i-1],dp[i-2]+1);

void solve()
{
    string s;
    cin >> s;
    int n = s.size();
    int dp[n];
    dp[0] = 0;
    FOR(i, n)
    {
        if (i == 0)
            continue;
        else if (i == 1)
        {
            if (s[i] == s[i - 1])
                dp[1] = 0;
            else
                dp[1] = 1;
        }
        else
        {
            if (s[i] == s[i - 1])
            {
                dp[i] = dp[i - 1];
            }
            else
            {
                dp[i] = max(dp[i - 1], dp[i - 2] + 1);
            }
        }
    }
    cout << dp[n - 1] << endl;
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int t;
    cin >> t;
    while (t--)
        solve();
    return 0;
}