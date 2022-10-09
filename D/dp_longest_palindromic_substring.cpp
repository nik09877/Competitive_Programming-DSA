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

class Solution
{
public:
    string longestPalindrome(string s)
    {
        //expand from i to check even and odd palindromes
        int best_len = 1, start = 0;
        int n = s.length();
        for (int i = 1; i < n; i++)
        {
            //check even
            int left = i - 1;
            int right = i;
            while (left >= 0 and right < n and s[left] == s[right])
            {
                if (right - left + 1 > best_len)
                {
                    best_len = right - left + 1;
                    start = left;
                }
                left--, right++;
            }

            //check odd
            left = i - 1;
            right = i + 1;
            while (left >= 0 and right < n and s[left] == s[right])
            {
                if (right - left + 1 > best_len)
                {
                    best_len = right - left + 1;
                    start = left;
                }
                left--, right++;
            }
        }
        return s.substr(start, best_len);
    }
};
int32_t main()
{
    fastio;
    int t = 1;
    cin >> t;
    while (t--)
    {
        int n;
        cin >> n;
    }
}