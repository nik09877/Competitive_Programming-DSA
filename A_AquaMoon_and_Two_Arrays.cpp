#include <bits/stdc++.h>
using namespace std;
#define endl "\n"
#define fo(i, s, e) for (i = s; i < e; i++)
#define rfo(i, s, e) for (i = s; i > e; i--)
#define LL long long int
const LL MOD = 1e9 + 7;
#define pb push_back
#define pob pop_back()
#define sp " "
#define ff first
#define ss second
#define sz(x) ((LL)x.size())
#define TIME cerr << "Time Taken:" << (float)clock() / CLOCKS_PER_SEC * 1000 << "ms" << endl
//  When something is important enough, you do it even if the odds are not in your favor.

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
#ifdef somujena
    freopen("/home/somujena/competitive/input.txt", "r", stdin);
    freopen("/home/somujena/competitive/output.txt", "w", stdout);
#endif
    LL test = 1;
    cin >> test;
    while (test--)
    {
        LL n, i, j;
        cin >> n;
        LL a[n], b[n];
        fo(i, 0, n) cin >> a[i];
        fo(i, 0, n) cin >> b[i];
        std::vector<LL> m, p;
        fo(i, 0, n)
        {
            if (a[i] > b[i])
            {
                while (b[i] < a[i])
                    m.pb(i + 1), b[i]++;
            }
            else if (a[i] < b[i])
            {
                while (a[i] < b[i])
                    p.pb(i + 1), a[i]++;
            }
        }
        if (sz(p) == sz(m))
        {
            cout << sz(p) << endl;
            fo(i, 0, sz(p)) cout << m[i] << sp << p[i] << endl;
        }
        else
            cout << -1 << endl;
    }
    TIME;
    return 0;
}