#include<bits/stdc++.h>
#define REP(i,n) for (int i = 1; i <= n; i++)
#define mod 1000000007
#define pb push_back
#define ff first
#define ss second
#define ii pair<int,int>
#define vi vector<int>
#define vii vector<ii>
#define lli long long int
#define INF 1000000000
#define endl '\n'
const double PI = 3.141592653589793238460;
typedef std::complex<double> Complex;
typedef std::valarray<Complex> CArray;
using namespace std;

lli power(lli a , lli n)
{
	lli res = 1;
	a %= mod;

	while(n)
	{
		if(n & 1) res = (res * a) % mod;

		n >>= 1;
		a = (a * a) % mod;
	}

	return res;
}
int n;
int ar[100001];

bool isValid(int m)
{
	for(int i=2;i<=m;i++)
	if(ar[i] - ar[i-1] < ar[m]) return false;
	
	return true;
}

int getAns()
{
	int L = 1;
	int R = n;
	int res = 1;
	
	while(L <= R)
	{
		int mid = (L + R) / 2;
		
		if(isValid(mid)) L = mid + 1 , res = max(res , mid);
		else			 R = mid - 1;
	}
	
	return res;
}
int main()
{
	int t;
	cin>>t;
	
	while(t--)
	{
		cin>>n;
		REP(i , n) cin>>ar[i];
		
		sort(ar + 1 , ar + n + 1);
		
		cout<<getAns()<<endl;
	}
}


