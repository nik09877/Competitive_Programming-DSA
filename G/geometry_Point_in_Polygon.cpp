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
};

void solve()
{
    int n, m;
    cin >> n >> m;
    vector<Point> polygon(n);
    rep(i, n)
    {
        polygon[i].READ();
    }

    for (int rep = 0; rep < m; rep++)
    {
        Point p;
        p.READ();
        Point out = {p.x + 1, 3000000001};
        int cnt = 0;
        bool is_on_boundary = false;
        for (int i = 0; i < n; i++)
        {
            int j = i == n - 1 ? 0 : i + 1;
            if (p.segment_contains(polygon[i], polygon[j], p))
            {
                is_on_boundary = true;
                break;
            }
            if (p.isIntersecting(p, out, polygon[i], polygon[j]))
            {
                cnt++;
            }
        }
        if (is_on_boundary)
        {
            cout << "BOUNDARY\n";
        }
        else if (cnt % 2 == 0)
        {
            cout << "OUTSIDE\n";
        }
        else
            cout << "INSIDE\n";
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
    while (t--)
    {
        solve();
    }
}
