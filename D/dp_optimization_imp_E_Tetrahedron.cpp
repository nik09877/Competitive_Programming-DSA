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
const int N = 1e7+2, M = N;

int dp[2][N];
int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	int i,n,k,j;
	cin >> n;
	dp[1][0] = 1;
	for(int steps = 1; steps < N; steps++){
		dp[1][steps] = (3LL*dp[0][steps-1])%mod;
		dp[0][steps] = (2LL*dp[0][steps-1] + dp[1][steps-1])%mod;
	}
	cout << dp[1][n] << endl;
	
	
	return 0;
} 

//RECURSIVE DP GIVES MEMORY LIMIT EXCEEDED DUE TO STACK OVERFLOW

// const lli mod=1e9+7;
// const int N=1e7+1;
// lli dp[2][N];
// lli getAns(lli node,lli steps){
//     if(steps==0){
//         return node==1;
//     }
//     if(dp[node][steps]!=-1)return dp[node][steps];
//     lli ans=0;
//     //starting at 1 I want to get back to 1 -> 3 * starting at 0 and not want to comeback to 0 using (steps-1) steps
//     if(node==1){
//         ans=(3*getAns(0,steps-1))%mod;
//     }
//     // starting at 0 i want to end up at 1
//     else{
//         ans=(2*getAns(0,steps-1))%mod;
//         ans=(ans+getAns(1,steps-1))%mod;
//     }
//     return dp[node][steps]=ans;
// }
// int32_t main()
// {
//     fastio;
//     lli steps;
//     cin>>steps;
//     rep(i,2)rep(j,steps+1)dp[i][j]=-1;
//     lli ans = getAns(1,steps);
//     cout<<ans;
// }