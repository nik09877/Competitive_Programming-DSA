#include <bits/stdc++.h>
#define rep(i, n) for (int i = 0; i < n; i++)
#define rrep(i, a, b) for (int i = a; i >= b; i--)
#define rep1(i, n) for (int i = 1; i <= n; i++)
#define fo(i, a, n) for (int i = a; i <= n; i++)
#define mkp make_pair
#define pb emplace_back
#define ff first
#define ss second
#define ll long long
#define ii int, int
#define pii pair<int, int>
#define vi vector<int>
#define vvi vector<vector<int>>
#define vpii vector<pair<int, int>>
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
#define yes cout << "Yes\n"
#define no cout << "No\n"
#define pr(x) cout << x
#define prsp(x) cout << x << sp
#define prln(x) cout << x << endl
#define fastio ios_base::sync_with_stdio(0), cin.tie(0)
#define re(a, n)   \
    rep(i, n)      \
            cin >> \
        a[i];
using namespace std;
const int mod = 1000000007;

// typedef int64_t ll;
// typedef long long ll;
// typedef pair<ll, ll> lll;
// typedef pair<ll, int> lli;
// typedef pair<int, int> ii;

#define EL printf("\n")
#define OK printf("OK")
#define ep emplace_back
#define fillchar(a, x) memset(a, x, sizeof(a))
#define FOR(i, l, r) for (int i = l; i <= r; i++)
#define FORD(i, r, l) for (int i = r; i >= l; i--)

const int base = 1e9;
typedef vector<int> BigInt;

void Set(BigInt &a)
{
    while (a.size() > 1 && a.back() == 0)
        a.pop_back();
}

void Print(BigInt a)
{
    Set(a);
    printf("%d", (a.size() == 0) ? 0 : a.back());
    FORD(i, a.size() - 2, 0)
    printf("%09d", a[i]);
    EL;
}

BigInt Integer(string s)
{
    BigInt ans;
    if (s[0] == '-')
        return ans;
    if (s.size() == 0)
    {
        ans.pb(0);
        return ans;
    }
    while (s.size() % 9 != 0)
        s = '0' + s;
    for (int i = 0; i < s.size(); i += 9)
    {
        int v = 0;
        for (int j = i; j < i + 9; j++)
            v = v * 10 + (s[j] - '0');
        ans.insert(ans.begin(), v);
    }
    Set(ans);
    return ans;
}

BigInt Integer(char c[])
{
    string s = "";
    FOR(i, 0, strlen(c) - 1)
    s = s + c[i];
    return Integer(s);
}

BigInt Integer(ll x)
{
    string s = "";
    while (x > 0)
        s = char(x % 10 + '0') + s, x /= 10;
    return Integer(s);
}

BigInt Integer(int x)
{
    return Integer((ll)x);
}

void operator>>(istream &in, BigInt &a)
{
    string s;
    getline(cin, s);
    a = Integer(s);
}

void operator<<(ostream &out, BigInt a)
{
    Print(a);
}

bool operator<(BigInt a, BigInt b)
{
    Set(a);
    Set(b);
    if (a.size() != b.size())
        return (a.size() < b.size());
    FORD(i, a.size() - 1, 0)
    if (a[i] != b[i])
        return (a[i] < b[i]);
    return false;
}

bool operator>(BigInt a, BigInt b)
{
    return (b < a);
}

bool operator==(BigInt a, BigInt b)
{
    return (!(a < b) && !(b < a));
}

bool operator<=(BigInt a, BigInt b)
{
    return (a < b || a == b);
}

bool operator>=(BigInt a, BigInt b)
{
    return (b < a || b == a);
}

bool operator<(BigInt a, int b)
{
    return (a < Integer(b));
}

bool operator>(BigInt a, int b)
{
    return (a > Integer(b));
}

bool operator==(BigInt a, int b)
{
    return (a == Integer(b));
}

bool operator>=(BigInt a, int b)
{
    return (a >= Integer(b));
}

bool operator<=(BigInt a, int b)
{
    return (a <= Integer(b));
}

BigInt max(BigInt a, BigInt b)
{
    if (a > b)
        return a;
    return b;
}

BigInt min(BigInt a, BigInt b)
{
    if (a < b)
        return a;
    return b;
}

BigInt operator+(BigInt a, BigInt b)
{
    Set(a);
    Set(b);
    BigInt ans;
    int carry = 0;
    FOR(i, 0, max(a.size(), b.size()) - 1)
    {
        if (i < a.size())
            carry += a[i];
        if (i < b.size())
            carry += b[i];
        ans.pb(carry % base);
        carry /= base;
    }
    if (carry)
        ans.pb(carry);
    Set(ans);
    return ans;
}

BigInt operator+(BigInt a, int b)
{
    return a + Integer(b);
}

BigInt operator++(BigInt &a)
{ // ++a
    a = a + 1;
    return a;
}

void operator+=(BigInt &a, BigInt b)
{
    a = a + b;
}

void operator+=(BigInt &a, int b)
{
    a = a + b;
}

BigInt operator-(BigInt a, BigInt b)
{
    Set(a);
    Set(b);
    BigInt ans;
    int carry = 0;
    FOR(i, 0, a.size() - 1)
    {
        carry += a[i] - (i < b.size() ? b[i] : 0);
        if (carry < 0)
            ans.pb(carry + base), carry = -1;
        else
            ans.pb(carry), carry = 0;
    }
    Set(ans);
    return ans;
}

BigInt operator-(BigInt a, int b)
{
    return a - Integer(b);
}

void operator--(BigInt &a)
{ // --a
    a = a - 1;
}

void operator-=(BigInt &a, BigInt b)
{
    a = a + b;
}

void operator-=(BigInt &a, int b)
{
    a = a - b;
}

BigInt operator*(BigInt a, BigInt b)
{
    Set(a);
    Set(b);
    BigInt ans;
    ans.assign(a.size() + b.size(), 0);
    FOR(i, 0, a.size() - 1)
    {
        ll carry = 0ll;
        for (int j = 0; j < b.size() || carry > 0; j++)
        {
            ll s = ans[i + j] + carry + (ll)a[i] * (j < b.size() ? (ll)b[j] : 0ll);
            ans[i + j] = s % base;
            carry = s / base;
        }
    }
    Set(ans);
    return ans;
}

BigInt operator*(BigInt a, int b)
{
    return a * Integer(b);
}

void operator*=(BigInt &a, BigInt b)
{
    a = a * b;
}

void operator*=(BigInt &a, int b)
{
    a = a * b;
}

BigInt operator/(BigInt a, BigInt b)
{
    Set(a);
    Set(b);
    // if (b == Integer(0))
    //     return Integer("-1");
    BigInt ans, cur;
    FORD(i, a.size() - 1, 0)
    {
        cur.insert(cur.begin(), a[i]);
        int x = 0, L = 0, R = base;
        while (L <= R)
        {
            int mid = (L + R) >> 1;
            if (b * Integer(mid) > cur)
            {
                x = mid;
                R = mid - 1;
            }
            else
                L = mid + 1;
        }
        cur = cur - Integer(x - 1) * b;
        ans.insert(ans.begin(), x - 1);
    }
    Set(ans);
    return ans;
}
void solve()
{
    int anum1, anum2;
    cin >> anum1 >> anum2;
    if (anum2 % 2)
    {
        no;
        return;
    }
    while (anum2 % 2 == 0)
        anum2 /= 2;
    if (anum2 > 1)
    {
        no;
        return;
    }
    yes;
}
BigInt operator/(BigInt a, int b)
{
    Set(a);
    BigInt ans;
    ll cur = 0ll;
    FORD(i, a.size() - 1, 0)
    {
        cur = (cur * (ll)base + (ll)a[i]);
        ans.insert(ans.begin(), cur / b);
        cur %= b;
    }
    Set(ans);
    return ans;
}

void operator/=(BigInt &a, BigInt b)
{
    a = a / b;
}

void operator/=(BigInt &a, int b)
{
    a = a / b;
}

BigInt operator%(BigInt a, BigInt b)
{
    Set(a);
    Set(b);
    // if (b == Integer(0))
    //     return Integer("0");
    BigInt ans;
    FORD(i, a.size() - 1, 0)
    {
        ans.insert(ans.begin(), a[i]);
        int x = 0, L = 0, R = base;
        while (L <= R)
        {
            int mid = (L + R) >> 1;
            if (b * Integer(mid) > ans)
            {
                x = mid;
                R = mid - 1;
            }
            else
                L = mid + 1;
        }
        ans = ans - Integer(x - 1) * b;
    }
    Set(ans);
    return ans;
}

int operator%(BigInt a, int b)
{
    Set(a);
    if (b == 0)
        return -1;
    int ans = 0;
    FORD(i, a.size() - 1, 0)
    ans = (ans * (base % b) + a[i] % b) % b;
    return ans;
}

void operator%=(BigInt &a, BigInt b)
{
    a = a % b;
}

void operator%=(BigInt &a, int b)
{
    a = a % Integer(b);
}

BigInt gcd(BigInt a, BigInt b)
{
    Set(a);
    Set(b);
    while (b > Integer(0))
    {
        BigInt r = a % b;
        a = b;
        b = r;
    }
    Set(a);
    return a;
}

BigInt lcm(BigInt a, BigInt b)
{
    return (a * b / gcd(a, b));
}

BigInt sqrt(BigInt a)
{
    BigInt x0 = a, x1 = (a + 1) / 2;
    while (x1 < x0)
    {
        x0 = x1;
        x1 = (x1 + a / x1) / 2;
    }
    return x0;
}

BigInt pow(BigInt a, BigInt b)
{
    if (b == Integer(0))
        return Integer(1);
    BigInt tmp = pow(a, b / 2);
    if (b % 2 == 0)
        return tmp * tmp;
    return tmp * tmp * a;
}

BigInt pow(BigInt a, int b)
{
    return pow(a, (Integer(b)));
}

int log(int n, BigInt a)
{ // log_n(a)
    Set(a);
    int ans = 0;
    while (a > Integer(1))
    {
        ans++;
        a /= n;
    }
    return ans;
}
bool sortbysec(pii a, pii b)
{
    return a.ss < b.ss;
}

int32_t main()
{
    fastio;
    int t = 1;
    cin >> t;
    while (t--)
    {
        solve();
    }
}
