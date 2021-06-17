// Striver_79
// Youtube: takeUforward
// Practice is the only key to improve

#include <algorithm>
#include <bits/stdc++.h>
#include <unordered_map>
#include <unordered_set>
using namespace std;
#define mod (int)998244353
#define MOD (int)1e9 + 7
// Big two primes
#define X 1001100011100001111ll
#define all(a) a.begin(), a.end()
#define for0(i, n) for (int i = 0; i < n; i++)
#define for1(i, n) for (int i = 1; i <= n; i++)
#define loop(i, a, b) for (int i = a; i < b; i++)
#define bloop(i, a, b) for (int i = a; i >= b; i--)
#define tc(t) \
    int t;    \
    cin >> t; \
    while (t--)
#define int long long
#define ll long long
#define pb emplace_back
#define fio ios_base::sync_with_stdio(false), cin.tie(NULL), cout.tie(NULL)
#define in(x) scanf("%d", &x)
#define rr return 0
#define prec(n) fixed << setprecision(n)
#define maxpq priority_queue<int>
#define minpq priority_queue<int, vector<int>, greater<int>>
#define inf (int)(1e18)
#define ini(a, i) memset(a, i, sizeof(a))
#define vi vector<int>
#define fi first
#define se second
#define kitna se
#define endl "\n"
#define pii pair<int, int>
#define vii vector<pi>
const int MAXN = (int)((1e5) + 100);
int gcd(int a, int b)
{
    if (a == 0)
        return b;
    return gcd(b % a, a);
}
int max(int a, int b)
{
    if (a > b)
        return a;
    else
        return b;
}
int min(int a, int b)
{
    if (a < b)
        return a;
    else
        return b;
}
void pr(int x) { cout << x; }
void prl(int x) { cout << x << endl; }
// typedef tree<pii, null_type, less<pii>, rb_tree_tag, tree_order_statistics_node_update> Set;
//bool isPrime(int N){ for(int i=2;i*i<=N;++i){if(N%i==0) return false;}return true;}
int cbrt(int x)
{
    int lo = 1, hi = min(2000000ll, x);
    while (hi - lo > 1)
    {
        int mid = (lo + hi) / 2;
        if (mid * mid * mid < x)
        {
            lo = mid;
        }
        else
            hi = mid;
    }
    if (hi * hi * hi <= x)
        return hi;
    else
        return lo;
}
const int dx[4] = {-1, 1, 0, 0};
const int dy[4] = {0, 0, -1, 1};
int XX[] = {-1, -1, -1, 0, 0, 1, 1, 1};
int YY[] = {-1, 0, 1, -1, 1, -1, 0, 1};
const int N = (int)(2 * 1e5 + 10);

int findcount(int r, int lcm, int b)
{
    int div = r / lcm;
    int prod = div * lcm;
    int tot = r;
    if (div != 0)
    {
        tot -= min(b, r - prod + 1);
        tot -= (div - 1) * b;
    }
    return tot;
}

signed main()
{
    fio;
    int T = 1;
    cin >> T;

    while (T--)
    {
        int a, b, q;
        cin >> a >> b >> q;

        if (a > b)
            swap(a, b);
        int lc = a * b;
        int gg = gcd(a, b);
        lc /= gg;

        while (q--)
        {
            int l, r;
            cin >> l >> r;

            if ((gcd(a, b) == b) || (r < b))
            {
                cout << 0 << " ";
                continue;
            }

            int cnt = findcount(r, lc, b);

            l = max(l, b);
            if (l > 1)
                cnt -= findcount(l - 1, lc, b);
            cout << cnt << " ";
        }
        cout << endl;
    }
}
