#include <bits/stdc++.h>
using namespace std;

#define IOS                  \
    ios::sync_with_stdio(0); \
    cin.tie(0);              \
    cout.tie(0);
#define endl "\n"
#define Max(x, y, z) max(x, max(y, z))
#define Min(x, y, z) min(x, min(y, z))
#define pb push_back
#define mp make_pair
#define ff first
#define ss second
#define trace1(x) cerr << #x << ": " << x << endl
#define trace2(x, y) cerr << #x << ": " << x << " | " << #y << ": " << y << endl
#define trace3(x, y, z) cerr << #x << ":" << x << " | " << #y << ": " << y << " | " << #z << ": " << z << endl
#define trace4(a, b, c, d) cerr << #a << ": " << a << " | " << #b << ": " << b << " | " << #c << ": " << c << " | " << #d << ": " << d << endl
#define trace5(a, b, c, d, e) cerr << #a << ": " << a << " | " << #b << ": " << b << " | " << #c << ": " << c << " | " << #d << ": " << d << " | " << #e << ": " << e << endl
#define trace6(a, b, c, d, e, f) cerr << #a << ": " << a << " | " << #b << ": " << b << " | " << #c << ": " << c << " | " << #d << ": " << d << " | " << #e << ": " << e << " | " << #f << ": " << f << endl

typedef long long ll;
typedef long double ld;
typedef unsigned long long ull;
typedef pair<long long, long long> pll;
typedef vector<int> vi;
typedef vector<vi> vvi;
typedef vector<long long> vll;
typedef vector<vll> vvll;
typedef vector<char> vc;
typedef vector<vc> vvc;
typedef vector<pair<long long, long long>> vpll;
typedef vector<bool> vb;
typedef vector<vb> vvb;

#define PI 3.141592653589793
#define MOD 1000000007

template <typename T>
T gcd(T a, T b)
{
    if (a == 0)
        return b;
    return gcd(b % a, a);
}
template <typename T>
T pow(T a, T b, ll m)
{
    T ans = 1;
    while (b > 0)
    {
        if (b % 2 == 1)
            ans = (ans * a) % m;
        b /= 2;
        a = (a * a) % m;
    }
    return ans % m;
}

const long long N = 3e5;
const int offset = 1e5 + 5e4;

int main()
{
    IOS;
    string a, b;
    cin >> a >> b;
    string astore = a;
    ll sz = a.size();
    bool check = false;
    for (ll i = sz - 1; i >= 0; i--)
    {
        if (a[i] != 'z')
        {
            a[i]++;
            check = true;
            break;
        }
        else
        {
            a[i] = 'a';
        }
    }
    if (a > astore && a < b)
    {
        cout << a;
    }
    else
    {
        cout << "No such string";
    }
    return 0;
}