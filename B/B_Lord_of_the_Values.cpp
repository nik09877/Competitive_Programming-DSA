//Think simple yet elegant.
#include <bits/stdc++.h>
using namespace std;
#define fast                 \
    ios::sync_with_stdio(0); \
    cin.tie(0);              \
    cout.tie(0);
#define all(v) v.begin(), v.end()
#define F first
#define S second
#define ll long long
#define pb push_back
#define mp make_pair
#define pi pair<int, int>
#define REP(i, n) for (int i = 0; i < n; i++)
const int N = 2e5 + 10;
ll mod = 1e9 + 7;
const ll INF = 1e18;

void run_case()
{
    int n, i;
    cin >> n;
    vector<int> a(n);
    for (i = 0; i < n; i++)
    {
        cin >> a[i];
    }
    cout << 3 * n << "\n";
    for (i = 0; i < n - 1; i += 2)
    {
        int x = a[i];
        int y = a[i + 1];
        cout << 1 << " " << i + 1 << " " << i + 2 << "\n";
        cout << 2 << " " << i + 1 << " " << i + 2 << "\n";
        cout << 1 << " " << i + 1 << " " << i + 2 << "\n";
        cout << 1 << " " << i + 1 << " " << i + 2 << "\n";
        cout << 2 << " " << i + 1 << " " << i + 2 << "\n";
        cout << 1 << " " << i + 1 << " " << i + 2 << "\n";
    }
}

int main()
{
    fast;
    int t;
    cin >> t;
    while (t--)
    {
        run_case();
    }
}
