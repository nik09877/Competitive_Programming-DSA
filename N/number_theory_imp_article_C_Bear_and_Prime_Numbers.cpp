#include <bits/stdc++.h>
#define REP(i, n) for (int i = 1; i <= n; i++)
#define mod 1000000007
#define pb push_back
#define ff first
#define ss second
#define ii pair<int, int>
#define vi vector<lli>
#define vii vector<ii>
#define lli long long int
#define endl '\n'
using namespace std;
vi pre(10000001, 0);
int cnt[10000001];

void sieve()
{
    vector<bool> isPrime(10000001, false);

    for (int i = 2; i <= 10000000; i++)
        if (isPrime[i] == 0)
        {
            for (lli j = i; j <= 10000000; j += i)
                pre[i] += cnt[j], isPrime[j] = 1;
        }

    for (int i = 1; i <= 10000000; i++)
        pre[i] += pre[i - 1];
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);

    int n, m, x, l, r;
    cin >> n;
    REP(i, n)
    cin >> x, cnt[x]++;

    sieve();
    cin >> m;
    REP(i, m)
    {
        cin >> l >> r;
        l = min(10000000, l);
        r = min(10000000, r);
        cout << pre[r] - pre[l - 1] << '\n';
    }
}
