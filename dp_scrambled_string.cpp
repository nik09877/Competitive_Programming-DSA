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

class Solution
{
public:
    umap<string, bool> mp;
    bool getAns(string s1, string s2)
    {
        string key = s1 + "|" + s2;

        if (s1 == s2)
            return mp[key] = true;

        if (s1.length() != s2.length())
            return mp[key] = false;

        if (mp.find(key) != mp.end())
            return mp[key];

        //check if they are anagram or not
        vector<int> hmap(26, 0);
        for (char c : s1)
        {
            hmap[c - 'a']++;
        }
        for (char c : s2)
        {
            hmap[c - 'a']--;
        }
        for (int x : hmap)
            if (x < 0)
                return false;

        int n = s1.length();

        rep1(i, n - 1)
        {
            bool g1, g2, g3, g4;

            g1 = getAns(s1.substr(0, i), s2.substr(n - i, i));
            g2 = getAns(s1.substr(i, n - i), s2.substr(0, n - i));
            if (g1 and g2)
                return mp[key] = true;

            g3 = getAns(s1.substr(0, i), s2.substr(0, i));
            g4 = getAns(s1.substr(i, n - i), s2.substr(i, n - i));
            if (g3 and g4)
                return mp[key] = true;
        }
        return mp[key] = false;
    }
};
int32_t main()
{
    fastio;
    int t = 1;
    while (t--)
    {
        string s1, s2;
        Solution a;
        cin >> s1 >> s2;
        if (a.getAns(s1, s2))
            prln("YES");
        else
            prln("NO");
    }
}