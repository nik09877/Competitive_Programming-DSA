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

///---------------Functions---------------------///
int gcd(int a, int b)
{
    if (a == 0)
        return b;
    return gcd(b % a, a);
}
int lcm(int a, int b)
{
    return (a * b) / __gcd(a, b);
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
int ceil(int numerator, int denominator)
{
    return (numerator + denominator - 1) / denominator;
}
bool isPrime(int N)
{
    for (int i = 2; i * i <= N; ++i)
    {
        if (N % i == 0)
            return false;
    }
    return true;
}
int cbrt(int x) //cuberoot
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

///---------------custom_hash---------------------///
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
    // umap<lli, lli, custom_hash> mp;
};

///---------------variables---------------------///
const int dx[4] = {-1, 1, 0, 0};
const int dy[4] = {0, 0, -1, 1};
int XX[] = {-1, -1, -1, 0, 0, 1, 1, 1};
int YY[] = {-1, 0, 1, -1, 1, -1, 0, 1};
const int mod = 1000000007;
class Point
{
public:
    lli x, y;
    void READ()
    {
        cin >> x >> y;
    }
    //shft the Point
    void operator-=(const Point &p)
    {
        x -= p.x;
        y -= p.y;
    }
    Point operator-(const Point &p) const
    {
        return Point{x - p.x, y - p.y};
    }

    //cross product
    lli operator*(const Point &p) const
    {
        return (x * p.y - p.x * y);
    }
    //cross product with respect to a point
    lli triangle(Point &p1, Point &p2)
    {
        return ((p1 - *this) * (p2 - *this));
    }

    bool isIntersecting(Point p1, Point p2, Point p3, Point p4)
    {
        // two segment are parallel
        if ((p2 - p1) * (p4 - p3) == 0)
        {
            // if((p2 - p1) * (p3 - p1) != 0) {
            if (p1.triangle(p2, p3) != 0)
            {
                return false;
            }
            // check if two bounding boxes intersect
            for (int rep = 0; rep < 2; ++rep)
            {
                // rectangle A on left from rectangle B   or   A below rectangle B
                if (max(p1.x, p2.x) < min(p3.x, p4.x) || max(p1.y, p2.y) < min(p3.y, p4.y))
                {
                    return false;
                }
                swap(p1, p3);
                swap(p2, p4);
            }
            return true;
        }
        for (int rep = 0; rep < 2; ++rep)
        {
            long long sign1 = (p2 - p1) * (p3 - p1);
            long long sign2 = (p2 - p1) * (p4 - p1);
            if ((sign1 < 0 && sign2 < 0) || (sign1 > 0 && sign2 > 0))
            {
                // segment B is on left or right from line A
                return false;
            }
            swap(p1, p3);
            swap(p2, p4);
        }
        return true;
    }
    lli twicePolygonArea(vector<Point> &a)
    {
        lli twiceArea = 0;
        lli n = (lli)a.size();
        repll(i, 0, n - 1)
        {
            twiceArea += (a[i] * a[i + 1 == n ? 0 : i + 1]);
        }
        return abs(twiceArea);
    }
    bool segment_contains(Point &a, Point &b, Point &c)
    {
        if (a.triangle(b, c) != 0)
            return false;
        return (min(a.x, b.x) <= c.x && c.x <= max(a.x, b.x) && min(a.y, b.y) <= c.y && c.y <= max(a.y, b.y));
    }
    //with respect to a point so call the function using the first point
    bool on_same_line_with(Point &a, Point &b)
    {
        //three points are on the same line if their slopes are equal
        return (a.y - this->y) * (b.x - this->x) == (b.y - this->y) * (a.x - this->x);
    }
} gun;
void solve()
{
    int n, cnt(0);
    cin >> n;
    gun.READ();
    vector<Point> p(n);
    vector<bool> vis(n, false);
    rep(i, n)
    {
        p[i].READ();
    }
    rep(i, n)
    {
        bool good = false;
        if (!vis[i])
        {
            fo(j, i + 1, n - 1)
            {
                if (gun.on_same_line_with(p[i], p[j]))
                {
                    vis[j] = true;
                    good = true;
                }
            }
        }
        if (good)
            vis[i] = true, cnt++;
    }
    rep(i, n)
    {
        if (!vis[i])
            cnt++;
    }
    prln(cnt);
    return;
}
int32_t main()
{
    fastio;
    int t = 1;
    while (t--)
    {
        solve();
    }
}