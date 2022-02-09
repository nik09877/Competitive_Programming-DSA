#include <bits/stdc++.h>
using namespace std;
#define in(x) \
    int x;    \
    cin >> x;
#define sin(s) \
    string s;  \
    cin >> s;
#define ll long long
#define lin(x) \
    ll x;      \
    cin >> x;
#define vi vector<int>
#define vll vector<ll>
#define si set<int>
#define pb push_back
#define re(i, n) for (int i = 0; i < n; i++)
#define pe(i, a, b) for (ll i = a; i <= b; i++)
#define rre(i, n) for (int i = n - 1; i > -1; i--)
#define mp make_pair
#define pll pair<ll, ll>
#define pii pair<int, int>
#define endl "\n"
//#define pi acos(-1)
#define FAST                          \
    ios_base::sync_with_stdio(false); \
    cin.tie(0);                       \
    cout.tie(0);
#define fio                           \
    freopen("input.txt", "r", stdin); \
    freopen("output.txt", "w", stdout);
#define ninf -INT_MAX
#define inf 100000000000000000
#define x first
#define y second
#define mod 1000000007
#define MOD 1000000007

int main()
{
    in(t) while (t--)
    {
        in(n) int a[n];
        int cnt[n + 1] = {};
        re(i, n)
        {
            cin >> a[i];
            cnt[a[i]]++;
        }
        vector<int> v;
        int ind = 0;
        while (ind < n)
        {
            int mex;
            pe(i, 0, n)
            {
                if (!cnt[i])
                {
                    mex = i;
                    break;
                }
            }
            set<int> s;
            pe(j, ind, n - 1)
            {
                if (a[j] < mex)
                {
                    s.insert(a[j]);
                    cnt[a[j]]--;
                }
                if (s.size() == mex)
                {
                    ind = j + 1;
                    break;
                }
            }
            v.pb(mex);
        }

        cout << v.size() << endl;
        for (auto x : v)
            cout << x << " ";
        cout << endl;
    }
    return 0;
}