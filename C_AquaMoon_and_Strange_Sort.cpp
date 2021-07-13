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
        fo(i, 0, n) cin >> a[i], b[i] = a[i];
        sort(b, b + n);
        std::map<LL, LL> m[2];
        fo(i, 0, n)
        {
            m[i % 2][b[i]]++;
        }
        LL f = 1;
        fo(i, 0, n)
        {
            if (m[i % 2][a[i]] == 0)
                f = 0;
            else
            {
                m[i % 2][a[i]]--;
            }
        }
        if (f)
            cout << "YES";
        else
            cout << "NO";
        cout << endl;
    }

    return 0;
}