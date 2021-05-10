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
    //cross product with shifting
    lli crossProduct(Point &p1, Point &p2)
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
            if (p1.crossProduct(p2, p3) != 0)
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

} p1, p2, p3, p4, p5, p6, p7, p8;

void solve()
{
    p1.READ();
    p2.READ();
    p3.READ();
    p4.READ();
    if (p1.isIntersecting(p1, p2, p3, p4))
    {
        cout << "YES\n";
    }
    else
        cout << "NO\n";
    return;
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