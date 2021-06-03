//RECURSIVE VERSION

// #include <bits/stdc++.h>
// #include <stdio.h>
// #define rep(i, n) for (int i = 0; i < n; i++)
// #define rrep(i, a, b) for (int i = a; i >= b; i--)
// #define rep1(i, n) for (int i = 1; i <= n; i++)
// #define fo(i, a, n) for (int i = a; i <= n; i++)
// #define repll(i, a, n) for (lli i = a; i <= n; i++)
// #define mkp make_pair
// #define pb emplace_back
// #define ff first
// #define ss second
// #define ll long long
// #define lli long long int
// #define ii int, int
// #define pii pair<int, int>
// #define pll pair<long, long>
// #define plli pair<long long int, long long int>
// #define vi vector<int>
// #define vvi vector<vector<int>>
// #define vlli vector<long long int>
// #define vpii vector<pair<int, int>>
// #define vplli vector<pair<long long int, long long int>>
// #define vvlli vector<vector<long long int>>
// #define MAXLL 1e18
// #define endl '\n'
// #define sp ' '
// #define dsort(v) sort(v.begin(), v.end(), greater<int>())
// #define asort(v) sort(v.begin(), v.end())
// #define uniq(v) v.erase(unique(v.begin(), v.end()), v.end())
// #define all(v) v.begin(), v.end()
// #define umap unordered_map
// #define uset unordered_set
// #define sz(x) ((int)(x).size())
// #define yes cout << "YES\n"
// #define no cout << "NO\n"
// #define pr(x) cout << x
// #define prsp(x) cout << x << sp
// #define prln(x) cout << x << endl
// #define fastio ios_base::sync_with_stdio(0), cout.tie(0), cin.tie(0)
// #define read(a, n) \
//     rep(i, n)      \
//             cin >> \
//         a[i];
// using namespace std;
// const int mod = 1000000007;
// #define int long long int
// const int N = 2e5 + 5;
// int dp[N][3][2];
// int n, a[N];

// int getAns(int i, int not_open_or_open_or_closed, int st)
// {
//     if (i >= n)
//     {
//         // have started reversing but haven't ended it yet
//         if (not_open_or_open_or_closed == 1)
//             return -1e18;
//         return 0;
//     }
//     int &ans = dp[i][not_open_or_open_or_closed][st];
//     if (ans != -1)
//         return ans;

//     //if i haven't started reversing yet
//     if (not_open_or_open_or_closed == 0)
//     {
//         //keep going without starting to reverse
//         ans = (i % 2 == 0) * a[i] + getAns(i + 1, 0, st);

//         //start the reversing of array from here,so value at odd index will be considered not even index
//         ans = max(ans, (i % 2) * a[i] + getAns(i + 1, 1, i % 2));
//     }
//     //if i have already started reversing
//     else if (not_open_or_open_or_closed == 1)
//     {
//         //keep going
//         ans = (i % 2) * a[i] + getAns(i + 1, 1, st);

//         //end reversing here
//         if (st != (i % 2))
//             ans = max(ans, (i % 2) * a[i] + getAns(i + 1, 2, i % 2));
//     }
//     //i have ended the reversing ,so i have no choice but to keep going like that
//     else
//         ans = (i % 2 == 0) * a[i] + getAns(i + 1, 2, st);
//     return ans;
// }
// int32_t main()
// {
//     fastio;
//     int t = 1;
//     cin >> t;
//     while (t--)
//     {
//         cin >> n;
//         rep(i, n) cin >> a[i];
//         rep(i, n + 1)
//             rep(j, 3)
//                 rep(k, 2)
//                     dp[i][j][k] = -1;

//         int ans = getAns(0, 0, 0);
//         prln(ans);
//     }
// }

/*
EDITORIAL-:

Solution: Since we are changing at most one subsegment, we need to keep track of those changes, simultaneously while maintaining the maximum sum. Say, we need to update the range [l, r) (I'm deliberately using the notation with right endpoint open, you'll see why). This range will partition the sequence into three sub-ranges: [1, l) (the range to the left of updated range), [l, r) (the updated range), and [r, n + 1) (the range to the right of updated range). For each of these three sub-ranges, we'll maintain one dp-array (this explains why there are dp[][0], dp[][1], dp[][2]). Now onto the second dimension.

1. The Left Part: dp[i][0] is the maximum sum that you get when i is in the left part. To maintain this, we just follow the definition of the sum(if i is even, we include it, otherwise, we discard it):
dp[i + 1][0] = dp[i][0] + (i % 2 == 0) ∗ a[i];

2. The Middle Part: dp[i][1] is the maximum sum that you get when i is in a segment that we intend to reverse. Note that it isn't necessary that the segment must start at i, it can be anywhere in-between. Now since reversing odd length ranges doesn't benefit even a penny, we'll simply ignore them and increment i by 2 for this array as we make transitions. To maintain this, we'll just take the maximum of dp[i - 2][0] (meaning the middle segment starts at i) and dp[i - 2][1] (it started somewhere earlier in the past but it continues still). The cost at this index just depends on the parity of i (as with everything else in this question apparently): if i is even, we keep element at i + 1 (since that'll be odd, and if we don't keep it we'd be ignoring it when we make the next jump of 2), otherwise, we simply keep the element at i:
dp[i + 2][1] = max(dp[i][0], dp[i][1]) + (i % 2 == 0) ? a[i + 1] : a[i];

3. The Right Part: dp[2][i] is the maximum sum that you get when i is in the segment where the reversal has already happened. It could either happen at this index or has already been sometime back in the past (or probably it never happened or never will be). To maintain it is to simply take the maximum of all these three possibilities. And the cost again depends on the parity of i: if it's odd, ignore it (because either it has been taken care of by the last dp[1][ ], meaning i = r or it's strictly in the right so it meets ignorance there too). If it's even, it's included nevertheless. Notice that the cost is exactly similar to the left part (as it should be).
dp[i+1][2] = max(dp[i][0], dp[i][1], dp[i][2]) + (i % 2 == 0) ∗ a[i];

Finally, the answer is just the maximum of dp[n][0], dp[n][1], and dp[n][2] depending on arguments that I believe you can pretty easily come up with now :)
*/

#include <bits/stdc++.h>
#include <stdio.h>
#define rep(i, n) for (int i = 0; i < n; i++)
#define rrep(i, a, b) for (int i = a; i >= b; i--)
#define rep1(i, n) for (int i = 1; i <= n; i++)
#define fo(i, a, n) for (int i = a; i <= n; i++)
#define repll(i, a, n) for (lli i = a; i <= n; i++)
#define mkp make_pair
#define pb emplace_back
#define ff first
#define ss second
#define ll long long
#define lli long long int
#define ii int, int
#define pii pair<int, int>
#define pll pair<long, long>
#define plli pair<long long int, long long int>
#define vi vector<int>
#define vvi vector<vector<int>>
#define vlli vector<long long int>
#define vpii vector<pair<int, int>>
#define vplli vector<pair<long long int, long long int>>
#define vvlli vector<vector<long long int>>
#define MAXLL 1e18
#define endl '\n'
#define sp ' '
#define dsort(v) sort(v.begin(), v.end(), greater<int>())
#define asort(v) sort(v.begin(), v.end())
#define uniq(v) v.erase(unique(v.begin(), v.end()), v.end())
#define all(v) v.begin(), v.end()
#define umap unordered_map
#define uset unordered_set
#define sz(x) ((int)(x).size())
#define yes cout << "YES\n"
#define no cout << "NO\n"
#define pr(x) cout << x
#define prsp(x) cout << x << sp
#define prln(x) cout << x << endl
#define fastio ios_base::sync_with_stdio(0), cout.tie(0), cin.tie(0)
#define read(a, n) \
    rep(i, n)      \
            cin >> \
        a[i];
using namespace std;
const int mod = 1000000007;

/*
This idea can be transformed to solve such problems in which you need to apply some function to some small number of subsegments (of course, under some constraints on functions). State of our dynamic programming is dpi,j where i∈[0;n] and j∈[0;2]. dpi,0 denotes the answer on the prefix of length i if we didn't start reversing the subarray, dpi,1 denotes the answer if we started reversing the subarray but didn't end it and dpi,2
denotes the answer if we ended reversing the subarray. Transitions are pretty easy:

dpi+1,0=max(dpi+1,0,dpi,0+[i%2==0?ai:0]);
dpi+2,1=max(dpi+2,1,max(dpi,0,dpi,1)+[i%2==0?ai+1:ai]);
dpi+1,2=max(dpi+1,2,max(dpi,0,dpi,1,dpi,2)+[i%2==0?ai:0]);

The value x?y:z
is just a ternary if statement. If x is true then return y otherwise return z

The answer is max(dpn,0,dpn,1,dpn,2)
.
*/

//HERE WE ARE DOING i+2 BECAUSE WE KNOW THAT IF I IS ODD THIS WILL CONTRIBUTE TO OUR ANSWER AND i+1 IS EVEN AND IT WILL NOT CONTRIBUTE ANYTHING SO THATS WHY WE JUMP TO i+2 ,SIMILARLY FOR i==EVEN WE DONT TAKE a[i] INTO CONSIDERATION BUT a[i+1]

int32_t main()
{
    fastio;
    int t = 1;
    cin >> t;
    while (t--)
    {
        int n;
        cin >> n;
        vector<int> a(n);
        for (auto &it : a)
            cin >> it;
        vector<vector<long long>> dp(n + 1, vector<long long>(3));
        for (int i = 0; i < n; ++i)
        {
            dp[i + 1][0] = max(dp[i + 1][0], dp[i][0] + (i & 1 ? 0 : a[i]));
            if (i + 2 <= n)
                dp[i + 2][1] = max(dp[i + 2][1], max(dp[i][0], dp[i][1]) + (i & 1 ? a[i] : a[i + 1]));
            dp[i + 1][2] = max(dp[i + 1][2], max({dp[i][0], dp[i][1], dp[i][2]}) + (i & 1 ? 0 : a[i]));
        }
        cout << max({dp[n][0], dp[n][1], dp[n][2]}) << endl;
    }
}