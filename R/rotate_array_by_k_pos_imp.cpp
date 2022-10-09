#include <bits/stdc++.h>
#define rep(i, n) for (int i = 0; i < n; i++)
#define rrep(i, n) for (int i = n - 1; i >= 0; i--)
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
#define pi pair<int, int>
#define vi vector<int>
#define vvi vector<vector<int>>
#define vlli vector<long long int>
#define vpi vector<pair<int, int>>
#define vvlli vector<vector<long long int>>
#define mod 1000000007
#define MAXLL 1e18
#define endl '\n'
#define dsort(v) sort(v.begin(), v.end(), greater<int>())
#define asort(v) sort(v.begin(), v.end())
#define uniq(v) v.erase(unique(v.begin(), v.end()), v.end())
#define all(v) v.begin(), v.end()
#define umap unordered_map
#define uset unordered_set
#define fastio ios_base::sync_with_stdio(0), cout.tie(0), cin.tie(0)
#define input(a)      \
    for (auto &i : a) \
        cin >> i;
using namespace std;

//right shift
/*
    reverse(0,k-1)
    reverse(k,n-1)
    reverse(0,n-1)
*/
//left shift elements in blocks,rather than shifting one by one
void leftRotate(int arr[], int d, int n)
{
    /* To handle if d >= n */
    d = d % n;
    int g_c_d = __gcd(d, n);
    for (int i = 0; i < g_c_d; i++)
    {
        /* move i-th values of blocks */
        int temp = arr[i];
        int j = i;

        while (1)
        {
            int k = j + d;
            if (k >= n)
                k = k - n;

            if (k == i)
                break;

            arr[j] = arr[k];
            j = k;
        }
        arr[j] = temp;
    }
}
//inefficient
void solve()
{
    int n, k, temp;
    cin >> n >> k;
    int a[n];
    for (int i = 0; i < n; i++)
        cin >> a[i];
    while (k--)
    {
        int i;
        temp = a[n - 1];
        for (i = n - 1; i >= 1; i--)
        {
            a[i] = a[i - 1];
        }
        a[i] = temp;
    }
    for (int i = 0; i < n; i++)
    {
        cout << a[i] << " ";
    }
    cout << endl;
    return;
}
int main()
{
    fastio;
    int t = 1;
    cin >> t;
    while (t--)
    {
        solve();
    }
    return 0;
}