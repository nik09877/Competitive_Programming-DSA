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
#define BLOCK 555
#define fastio ios_base::sync_with_stdio(0), cout.tie(0), cin.tie(0)
#define read(a, n) \
    rep(i, n)      \
            cin >> \
        a[i];
using namespace std;
const int mod = 1000000007;

struct query
{
    int l;
    int r;
    int i;
};
query Q[300001];
int ar[300001], ans[300001];
int freq[300001];

int freq_Of_freq[300001];
int mx_freq = 0;

bool comp(query a, query b)
{
    if (a.l / BLOCK != b.l / BLOCK)
        return a.l / BLOCK < b.l / BLOCK;

    return a.r < b.r;
}

void add(int pos)
{
    int preF = freq[ar[pos]];
    freq[ar[pos]]++;
    int currF = freq[ar[pos]];

    freq_Of_freq[preF]--;
    freq_Of_freq[currF]++;

    mx_freq = max(mx_freq, currF);
}

void remove(int pos)
{
    int preF = freq[ar[pos]];
    freq[ar[pos]]--;
    int currF = freq[ar[pos]];

    freq_Of_freq[preF]--;
    freq_Of_freq[currF]++;

    while (freq_Of_freq[mx_freq] == 0)
        mx_freq--;
}

int main()
{
    int n, q;
    cin >> n >> q;
    for (int i = 0; i < n; i++)
        cin >> ar[i];

    for (int i = 0; i < q; i++)
    {
        cin >> Q[i].l >> Q[i].r;
        Q[i].i = i, Q[i].l--, Q[i].r--;
    }

    sort(Q, Q + q, comp);
    int ML = 0, MR = -1;
    for (int i = 0; i < q; i++)
    {
        int L = Q[i].l;
        int R = Q[i].r;

        while (ML > L)
            ML--, add(ML);

        while (MR < R)
            MR++, add(MR);

        while (ML < L)
            remove(ML), ML++;

        while (MR > R)
            remove(MR), MR--;

        int total = Q[i].r - Q[i].l + 1;
        int rem = total - mx_freq;
        int half = (total + 1) / 2;

        if (mx_freq <= half)
            ans[Q[i].i] = 1;
        else
        {
            ans[Q[i].i] = total - 2 * rem;
        }
    }

    for (int i = 0; i < q; i++)
        cout << ans[i] << '\n';
}