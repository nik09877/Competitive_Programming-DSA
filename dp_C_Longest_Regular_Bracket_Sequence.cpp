#include <bits/stdc++.h>
#include <stdio.h>
#define rep(i, n) for (int i = 0; i < n; i++)
#define rrep(i, a, b) for (int i = a; i >= b; i--)
#define rep1(i, n) for (int i = 1; i <= n; i++)
#define fo(i, a, n) for (int i = a; i <= n; i++)
#define repll(i, a, n) for (lli i = a; i <= n; i++)
#define mkp make_pair
#define pb push_back
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
#define fastio ios_base::sync_with_stdio(0), cout.tie(0), cin.tie(0)
#define read(a)       \
    for (auto &i : a) \
        cin >> i;
using namespace std;
const int mod = 1000000007;
struct custom_hash
{
    static uint64_t splitmix64(uint64_t x)
    {
        x += 0x9e3779b97f4a7c15;
        x = (x ^ (x >> 30)) * 0xbf58476d1ce4e5b9;
        x = (x ^ (x >> 27)) * 0x94d049bb133111eb;
        return x ^ (x >> 31);
    }

    size_t operator()(uint64_t x) const
    {
        static const uint64_t FIXED_RANDOM = chrono::steady_clock::now().time_since_epoch().count();
        return splitmix64(x + FIXED_RANDOM);
    }
    // umap<lli, lli, custom_hash> mp;
};

/*
First of all, for each closing bracket in our string let's define 2 values:

    d[j] = position of corresponding open bracket, or -1 if closing bracket doesn't belong to any regular bracket sequence.
     c[j] = position of earliest opening bracket, such that substring s(c[j], j) (both boundaries are inclusive) is a regular bracket sequence. Let's consider c[j] to be -1 if closing bracket doesn't belong to any regular bracket sequence.

It can be seen, that c[j] defines the beginning position of the longest regular bracket sequence, which will end in position j. So, having c[j] answer for the problem can be easily calculated.

Both d[j] and c[j] can be found with following algorithm, which uses stack.

    Iterate through the characters of the string.
    If current character is opening bracket, put its position into the stack.
    If current character is closing bracket, there are 2 subcases:

    Stack is empty - this means that current closing bracket doesn't have corresponding open one. Hence, both d[j] and c[j] are equal to -1.
    Stack is not empty - we will have position of the corresponding open bracket on the top of the stack - let's put it to d[j] and remove this position from the stack. Now it is obvious, that c[j] is equal at least to d[j]. But probably, there is a better value for c[j]. To find this out, we just need to look at the position d[j] - 1. If there is a closing bracket at this position, and c[d[j] - 1] is not -1, than we have 2 regular bracket sequences s(c[d[j] - 1], d[j] - 1) and s(d[j], j), which can be concatenated into one larger regular bracket sequence. So we put c[j] to be c[d[j] - 1] for this case.

    ANOTHER IDEA
    My solution uses DP. The main idea is as follows: I construct a array longest[], for any longest[i], it stores the longest length of valid parentheses which is end at i.

    And the DP idea is :

    If s[i] is '(', set longest[i] to 0,because any string end with '(' cannot be a valid one.

    Else if s[i] is ')'

        If s[i-1] is '(', longest[i] = longest[i-2] + 2

        Else if s[i-1] is ')' and s[i-longest[i-1]-1] == '(', longest[i] = longest[i-1] + 2 + longest[i-longest[i-1]-2]

    For example, input "()(())", at i = 5, longest array is [0,2,0,0,2,0], longest[5] = longest[4] + 2 + longest[1] = 6.
*/
void solve()
{
    int n, mx = 0;
    string st;
    umap<ii, custom_hash> S, E, F;
    F[0] = 1;
    cin >> st;
    n = sz(st);
    stack<int> stk;
    rep(i, n)
    {
        char c = st[i];
        if (c == '(')
        {
            stk.push(i);
        }
        else
        {
            if (stk.empty())
            {
                S[i] = E[i] = -1;
            }
            else
            {
                int idx = stk.top();
                stk.pop();
                S[i] = E[i] = idx;
                if (idx > 0 && S[idx - 1] >= 0 && st[idx - 1] == ')')
                {
                    E[i] = E[idx - 1];
                }
                int len = i - E[i] + 1;
                F[len]++;
                mx = max(mx, len);
            }
        }
    }
    cout << mx << sp << F[mx] << endl;
    return;
}
int32_t main()
{
    fastio;
    int t = 1;
    while (t--)
    {
        solve();
    }
}