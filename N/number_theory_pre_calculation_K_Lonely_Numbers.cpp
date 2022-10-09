#include<bits/stdc++.h>
using namespace std;
// #define int long long //delete if causing problems
#define F first
#define dbg(x)  cout<<#x<<" "<<x<<endl;
#define S second
#define setbit(n) __builtin_popcount(n)
#define all(x) x.begin() , x.end()
#define clr(x) memset(x,0,sizeof(x))
#define fast  ios_base::sync_with_stdio(0); cin.tie(0);
#define endl "\n" //delete if interactive
#define MOD 1000000007
const int inf = 1e18;
int power(int a, int b);

int prime[1000001];
int pre[1000005];
void seive()
{
	for (int i = 1; i <= 1000000; i++) prime[i] = 1;
	prime[1] = 0;
	for (int i = 2; i * i <= 1000000; i++)
	{
		if (prime[i])
		{
			for (int j = i * i; j <= 1000000; j = j + i)
			{

				prime[j] = 0;
			}
		}
	}

	pre[1] = 0;
	for (int i = 2; i <= 1000000; i++) {
		pre[i] = pre[i - 1];
		if (prime[i]) pre[i]++;
	}

}

signed   main()
{
	fast
	int tt = 1;
	cin >> tt;
	seive();
	while (tt--)
	{

		int n;
		cin >> n;



		int x = (int) ceil(sqrt(n + 1));
		int ans = pre[n] - pre[x - 1] + 1;
		cout << ans << '\n';
	}
	return 0;
}

int power(int a, int b)
{
	int res = 1;
	while (b)
	{
		if (b % 2) b-- , res = res * a;
		else b = b / 2 , a *= a;
	}
	return res;
}

/*
#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
#endif
*/



