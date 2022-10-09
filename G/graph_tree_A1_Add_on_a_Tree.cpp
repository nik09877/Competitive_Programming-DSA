#include <bits/stdc++.h>
#define REP(i, n) for (int i = 1; i <= n; i++)
#define mod 1000000007
#define pb push_back
#define ff first
#define ss second
#define ii pair<int, int>
#define vi vector<int>
#define vii vector<ii>
#define lli long long int
#define INF 1000000000
#define endl '\n'
const double PI = 3.141592653589793238460;
typedef std::complex<double> Complex;
typedef std::valarray<Complex> CArray;

using namespace std;
vi ar[100001];
int main()
{
    int n, v, u;
    cin >> n;
    REP(i, n - 1)
    cin >> v >> u,
        ar[v].pb(u), ar[u].pb(v);

    REP(i, n)
    //if deg[node] ==2 then no matter what its 2 edges will have same values written on them ,so we can't make arbitary config
    if (ar[i].size() == 2)
    {
        cout << "NO";
        return 0;
    }

    cout << "YES";
}
