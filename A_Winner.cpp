#include <bits/stdc++.h>
using namespace std;
using lli = long long int;
using ulli = unsigned long long int;
using ld = long double;
//---------------------------------------------------------------------------------------------------------------->
#define nl cout<<endl
#define Solve ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0); solve();
#define Solves ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0); lli test;cin>>test;while(test--){solve();}
#define mem(a,val) memset( a,  val,  sizeof(a) )
#define sci std::cout<<std::scientific;
#define fix std::cout<<std::fixed;
#define loop0(i,n) for(lli i=0;i<n;i++)
#define loop1(i,n) for(lli i=1;i<=n;i++)
#define sqr(n) ( n * n )
#define max3(a,b,c) max(a,max(b,c))
#define min3(a,b,c) min(a,min(b,c))
#define ub(a,n,x) upper_bound(a,a+n,x)-a
#define lb(a,n,x) lower_bound(a,a+n,x)-a
#define search(a,n,x) binary_search(a,a+n,x)
#define setprecision(i) cout<<fixed<<setprecision(i)
#define in insert
#define len size()
#define pb push_back
#pragma GCC optimize("O3")
#define rr0 return 0;
#define rr1 return 1;
//-------------------------------------------------------------------->
typedef pair<lli, lli> pii;
typedef pair<string, lli> psi;
typedef pair<lli, string> pis;
typedef pair<string, string> pss;
typedef vector<lli> vi;
typedef vector<lli>::iterator vit;
typedef vector<string> vs;
typedef vector<string>::iterator vst;
typedef vector<pii> vii;
typedef vector<pii>::iterator viit;
typedef vector<vi> vvi;
typedef vector<vi>::iterator vvit;
typedef map<lli,lli> mpii;
typedef map<lli,lli>::iterator mpiit;
typedef map<string,lli> mpsi;
typedef map<string,lli>::iterator mpsit;
typedef map<string,pii> mpsii;
typedef map<string,pii>::iterator mpsiit;
typedef map<string,string> mpss;
typedef map<string,string>::iterator mpsst;
typedef map<string,lli> mpsi;
typedef map<string,lli>::iterator mpsit;
typedef set<lli> seti;
typedef set<char> setc;
typedef multiset<lli> mseti;
//------------------------------------------------------------------------------>
template<class x>x mod(x a){fix return fmod(a,1000000007);}
template<class x,class y>x max(x a,y b){return (a>b)?a:b;}
template<class x,class y>x min(x a,y b){return (a<b)?a:b;}
template<class x,class y>x LOG(x n,y r){return (n>r-1)?1+LOG(n/r,r):0;}
//-------------------------------------------------------------------------------->
bool isprime(lli n);
bool ispalin(lli num);
//-------------------------------------------------------------------------------->
lli __lcm(lli a, lli b); 
lli power(lli x,lli y);
lli digitsum(lli n);
lli fact(lli n);
lli npr(lli n, lli r);
lli ncr(int n, int r);
lli evensum(lli n);
lli oddsum(lli n);
//------------------------------------------------------------------------------->
void countSort(lli arr[], lli n, lli exp);
void radixsort(lli arr[], lli n);
void print(lli arr[], lli n);
void sorts(string &str);
void primeFactors(int n);
//------------------------------------------------------------------------------->
string abc=" abcdefghijklmnopqrstuvwxyz";
string ABC=" ABCDEFGHIJKLMNOPQRSTUVWXYZ";
lli numascii[10]={48,49,50,51,52,53,54,55,56,57};
lli mini=1000000000000000007;
lli maxi=-10000000000000000;
lli ctr=0;
lli hash[1000007]={0};
ld pi = 3.1415926535897932384626433832795;
//---------------------------------------------------------------------------------------->
 
 
void solve()
{
	lli n;
	cin>>n;
	string ss;
	string s[n];
	lli x[n];
	mpsi mp,mp2;
	mpsit it;
	loop0(i,n)
	{
		cin>>s[i]>>x[i];
		mp[s[i]]+=x[i];
	}
	loop0(i,n)
	{
		maxi=max(maxi,mp[s[i]]);
	}
	lli i;
	for(i=0;mp[s[i]]<maxi||(mp2[s[i]]+=x[i])<maxi;i++);
    { 
		cout<<s[i];
	}
	
	
}
 
 
 
//-------------------------------------------------------------------------------------------->
int main()
{
	//setprecision(12);
	Solve
	rr0
}
 
 
 
 
/*
|
|
|
|
|
|
|
|
|
|
|
|
|
|
|
|
|
  
*/
/*void heapify(lli a[], lli i, lli n){
    lli l = 2*i+1;
    lli r = 2*i+2;
    lli largest = i;
    if (l < n && a[l] > a[i]) largest = l;
    if (r < n && a[r] > a[l]) largest = r;
    if (largest != i){
        lli tmp = a[i]; a[i] = a[largest]; a[largest] = tmp;
        heapify(a, largest, n);
    }
}
void heapsort(lli a[], lli n)
{
    for (lli i = n/2-1; i>=0; i--)
    heapify(a, i, n);
    for (lli i = n-1; i>0; i--)
    {
        lli tmp = a[0]; a[0] = a[i]; a[i] = tmp;
        heapify(a, 0, i);
    }
}*/
//-------------------------------------------------------------------------->
bool isprime(lli n)
{
    bool prime[n + 1];
    memset( prime , true, sizeof(prime));
    for (int p = 2; p * p <= n; p++) {
        if (prime[p] == true) {
            for (int i = p * p; i <= n; i += p)
                prime[i] = false;
        }
    }
    if(n==1)
        return false;
    else if (prime[n])
        return true;
    else
        return false;
}
 
bool ispalin(lli num)
{
    bool flag=false;
    lli digit,rev=0,n=num;
    do
     {
         digit = num % 10;
         rev = (rev * 10) + digit;
         num = num / 10;
     } while (num != 0);
     if(rev==n)
     flag=true;
     return flag;
}
// -------------------------------------------------------------------------->
 
lli __lcm(lli a, lli b)  
{  
return (a*b)/__gcd(a, b);  
}
 
lli power(lli x,lli y) 
{ 
	lli temp; 
	if( y == 0) 
		return 1; 
	temp = pow(x, y/2); 
	if (y%2 == 0) 
		return temp*temp; 
	else
		return x*temp*temp; 
}
lli digitsum(lli n)
{
    lli c=0;
    while(n>0)
    {
        c++;
        n/=10;
    }
    return c;
}
lli fact(lli n) 
{ 
    if (n <= 1) 
        return 1; 
    return n * fact(n - 1); 
}  
lli ncr(int n, int r) 
{ 
    long long p = 1, k = 1; 
    if (n - r < r) 
        r = n - r; 
  
    if (r != 0) { 
        while (r) { 
            p *= n; 
            k *= r; 
            lli m = __gcd(p, k); 
            p /= m; 
            k /= m; 
            n--; 
            r--; 
        } 
    } 
    else
        p = 1; 
    return p;
} 
lli npr(lli n, lli r) 
{ 
    return fact(n) / fact(n - r); 
} 
lli evensum(lli n)
{
	return (n/2*(n/2+1));
}
lli oddsum(lli n)
{
	return (((n+1)/2)*((n+1)/2));
}
//------------------------------------------------------------------------>
void countSort(lli arr[], lli n, lli exp) 
{ 
	lli output[n];
	lli i, count[10] = {0}; 
	for (i = 0; i < n; i++) 
		count[ (arr[i]/exp)%10 ]++; 
	for (i = 1; i < 10; i++) 
		count[i] += count[i - 1]; 
	for (i = n - 1; i >= 0; i--) 
	{ 
		output[count[ (arr[i]/exp)%10 ] - 1] = arr[i]; 
		count[ (arr[i]/exp)%10 ]--; 
	} 
	for (i = 0; i < n; i++) 
		arr[i] = output[i]; 
} 
void radixsort(lli arr[], lli n) 
{
    lli mx = arr[0]; 
	for (lli i = 1; i < n; i++) 
		if (arr[i] > mx) 
			mx = arr[i];
	lli m =mx;
	for (lli exp = 1; m/exp > 0; exp *= 10) 
		countSort(arr, n, exp); 
} 
void print(lli arr[], lli n) 
{ 
    for (lli i = 0; i < n; i++) 
        cout << arr[i] << " "; 
} 
void sorts(string &str)
{
	sort(str.begin(), str.end());
}
void primeFactors(int n) 
{ 
    while (n % 2 == 0) { 
        printf("%d ", 2); 
        n = n / 2; 
    } 
    for (int i = 3; i <= sqrt(n); i = i + 2) { 
        while (n % i == 0) { 
            printf("%d ", i); 
            n = n / i; 
        } 
    } 
    if (n > 2) 
        printf("%d ", n); 
} 