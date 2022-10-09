#include <bits/stdc++.h>
#include <stdio.h>
#define rep(i, n) for (int i = 0; i < n; i++)
#define rrep(i, a) for (int i = a; i >= 0; i--)
#define rep1(i, n) for (int i = 1; i <= n; i++)
#define fo(i, a, n) for (int i = a; i <= n; i++)
#define repll(i, a, n) for (lli i = a; i <= n; i++)
#define mkp make_pair
#define pb push_back
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
#define fastio ios_base::sync_with_stdio(0), cout.tie(0), cin.tie(0)
#define read(a)       \
    for (auto &i : a) \
        cin >> i;
using namespace std;
const int mod = 1000000007;
struct custom_hash
{
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
    //cross product with shifting
    lli triangle(Point &p1, Point &p2)
    {
        return ((p1 - *this) * (p2 - *this));
    }

    bool isIntersecting(Point &p1, Point &p2, Point &p3, Point &p4)
    {
        //check parallel and co-linearity
        // (p2-p1),(p4-p3) are vectors and cross product of two parallel vectors is 0
        if ((p2 - p1) * (p4 - p3) == 0)
        {
            //not co-linear
            if (p1.triangle(p2, p3) != 0)
            {
                return false;
            }
            //bounding box concept
            for (int rep = 0; rep < 2; rep++)
            {
                if (max(p1.x, p2.x) < min(p3.x, p4.x) ||
                    max(p1.y, p2.y) < min(p3.y, p4.y))
                {
                    return false;
                }
                swap(p1, p3);
                swap(p2, p4);
            }
        }
        //check if one segment is totally to the left or right of this segment
        for (int rep = 0; rep < 2; ++rep)
        {
            lli sign1 = (p2 - p1) * (p3 - p1);
            lli sign2 = (p2 - p1) * (p4 - p1);
            if ((sign1 < 0 && sign2 < 0) || (sign1 > 0 && sign2 > 0))
            {
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
} p1, p2, p3, p4, p5, p6, p7, p8;
bool comp(Point &p1, Point &p2)
{
    return mkp(p1.x, p1.y) < mkp(p2.x, p2.y);
}
void solve()
{
    int n;
    cin >> n;
    vector<Point> p(n);
    rep(i, n)
    {
        p[i].READ();
    }

    sort(all(p), comp);
    vector<Point> hull;

    for (int rep = 0; rep < 2; ++rep)
    {
        const int S = (int)hull.size();
        for (Point C : p)
        {
            while ((int)hull.size() - S >= 2)
            {
                Point A = hull.end()[-2];
                Point B = hull.end()[-1];
                if (A.triangle(B, C) <= 0)
                {
                    break;
                }
                hull.pop_back();
            }
            hull.pb(C);
        }
        hull.pop_back();
        reverse(all(p));
    }
    cout << hull.size() << endl;
    for (Point a : hull)
    {
        cout << a.x << sp << a.y << endl;
    }

    return;
}
int32_t main()
{
    fastio;
    // #ifndef ONLINE_JUDGE
    //     freopen("input.txt", "r", stdin);
    //     freopen("output.txt", "w", stdout);
    // #endif
    int t = 1;
    // cin >> t;
    while (t--)
    {
        solve();
    }
}