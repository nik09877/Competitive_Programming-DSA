#pragma GCC optimize("Ofast")
#pragma GCC target("avx,avx2,fma")
#pragma GCC optimization("unroll-loops")
#include <bits/stdc++.h>
#define rep(i, n) for (int i = 0; i < n; i++)
#define rrep(i, a, b) for (int i = a; i >= b; i--)
#define rep1(i, n) for (int i = 1; i <= n; i++)
#define fo(i, a, n) for (int i = a; i <= n; i++)
#define mkp make_pair
#define pb push_back
#define ff first
#define ss second
#define ll long long
#define ii int, int
#define pii pair<int, int>
#define vi vector < int>
#define vvi vector<vector < int>>
#define vpii vector<pair<int, int>>
#define MAXLL 1e18
#define endl '\n'
#define sp ' '
#define dsort(v) sort(v.rbegin(), v.rend())
#define asort(v) sort(v.begin(), v.end())
#define uniq(v) v.erase(unique(v.begin(), v.end()), v.end())
#define all(v) v.begin(), v.end()
#define umap unordered_map
#define uset unordered_set
#define sz(x)((int)(x).size())
#define yes cout << "YES\n"
#define no cout << "NO\n"
#define pr(x) cout << x
#define prsp(x) cout << x << sp
#define prln(x) cout << x << endl
using namespace std;
const int mod = 1e9 + 7;

class Solution
{
    public:
        int ans;
        int dx[4] = { 0,
            1,
            0,
            -1
        };
    int dy[4] = { 1,
        0,
        -1,
        0
    };
    bool isValid(int &x, int &y, vvi &a)
    {
        int n = a.size();
        if (x < 0 or x >= n or y < 0 or y >= n)
            return false;
        if (a[x][y] != 1)
            return false;
        return true;
    }
    void dfs(int i, int j, vvi &a, umap<ii> &cc_size, int &cur_cc_no)
    {
        a[i][j] = cur_cc_no;
        cc_size[cur_cc_no] += 1;
        ans=max(ans,cc_size[cur_cc_no]);
        
        for (int k = 0; k < 4; k++)
        {

            int new_i = i + dx[k];
            int new_j = j + dy[k];
            if (isValid(new_i, new_j, a))
                dfs(new_i, new_j, a, cc_size, cur_cc_no);
        }
        return;
    }
    int largestIsland(vector<vector < int>> &a)
    {
        int n = a.size();
        int cur_cc_no = 2;
        umap<int, int> cc_size;
        ans=0;
        rep(i, n)
        {
            rep(j, n)
            {
                if (a[i][j] == 1)
                {
                    dfs(i, j, a, cc_size, cur_cc_no);
                    cur_cc_no++;
                }
            }
        }
        
        rep(i,n){
            rep(j,n){
                if(a[i][j]==0){
                    int temp_ans=1;
                    uset<int>st;
                    rep(k,4){
                        int new_i = i + dx[k];
                        int new_j = j + dy[k];
                        if(new_i>=0 and new_i<n and new_j>=0 and new_j<n)
                            st.insert(a[new_i][new_j]);
                    }
                    for(auto cc:st)
                        temp_ans+=cc_size[cc];
                    ans=max(ans,temp_ans);
                }
            }
        }
        return ans;
    }
};