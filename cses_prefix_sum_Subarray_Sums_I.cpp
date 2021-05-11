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
class chash
{
public:
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
};
//PREFIX SUM + HASHING
const int mod = 1000000007;
int32_t main()
{
    fastio;
    long long int n, k, cnt(0);
    cin >> n >> k;
    umap<lli, lli, chash> mp;
    lli currSum = 0;
    rep(i, n)
    {
        int a;
        cin >> a;
        currSum += a;
        if (currSum == k)
            cnt++;
        if (mp.find(currSum - k) != mp.end())
        {
            cnt += mp[currSum - k];
        }
        mp[currSum]++;
    }
    pr(cnt);
}

// ANOTHER METHOD TWO POINTER ON PREFIX ARRAY
// #include<bits/stdc++.h>
// using namespace std;
// const int mod = 1e9+7;
// #define ll long long
// const int mx = 2e5+5;
// int main()
// {
//     ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
//     ll n,sum;cin>>n>>sum;
//     vector<ll>v(n),presum(n,0);
//     for(int i=0;i<n;++i)
//     	cin>>v[i];
//     presum[0]=v[0];
// 	for(int i=1;i<n;++i)
// 		presum[i]=presum[i-1]+v[i];

// 	ll j=0,cnt=0;
// 	for(int i=0;i<n;++i)
// 	{
// 		if(presum[i]>sum)
// 		{
// 			while(j<i)
// 			{
// 				int p=presum[i]-presum[j];
// 				if(p==sum)
// 				{
// 					cnt++;
// 					break;
// 				}
// 				else if(p<sum)break;
// 				j++;
// 			}
// 		}
// 		else if(presum[i]==sum)
// 		{
// 			cnt++;
// 		}
// 	}
// 	cout<<cnt<<endl;
// 	return 0;
// }