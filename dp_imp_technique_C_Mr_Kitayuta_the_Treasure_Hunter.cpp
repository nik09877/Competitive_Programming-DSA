#include <bits/stdc++.h>
using namespace std;
#define gc getchar_unlocked
#define fo(i, n) for (i = 0; i < n; i++)
#define Fo(i, k, n) for (i = k; k < n ? i < n : i > n; k < n ? i += 1 : i -= 1)
#define ll long long
#define si(x) scanf("%d", &x)
#define sl(x) scanf("%lld", &x)
#define ss(s) scanf("%s", s)
#define pi(x) printf("%d\n", x)
#define pl(x) printf("%lld\n", x)
#define ps(s) printf("%s\n", s)
#define pb push_back
#define mp make_pair
#define F first
#define S second
#define all(x) x.begin(), x.end()
#define clr(x) memset(x, 0, sizeof(x))
#define sortall(x) sort(all(x))
#define tr(it, a) for (auto it = a.begin(); it != a.end(); it++)
#define PI 3.1415926535897932384626
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;
typedef vector<int> vi;
typedef vector<ll> vll;
typedef vector<pii> vpii;
typedef vector<pll> vpll;
typedef vector<vi> vvi;
typedef vector<vll> vvl;
const int mod = 1000000007;
const int N = 30001;
int OFFSET = 0;
int dp[N][603], a[N];
int go(int i, int pre_jump_len)
{
    if (i >= N)
        return 0;
    int &ans = dp[i][pre_jump_len - OFFSET];
    if (ans != -1)
        return ans;

    ans = a[i];

    int other_part;
    other_part = max(go(i + pre_jump_len, pre_jump_len), go(i + pre_jump_len + 1, pre_jump_len + 1));
    if (pre_jump_len - 1 > 0)
        other_part = max(other_part, go(i + pre_jump_len - 1, pre_jump_len - 1));

    ans += other_part;
    return ans;
}
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    ll i, n, k, j, m, d, x;
    cin >> n >> d;
    fo(i, N) fo(j, 602) dp[i][j] = -1;
    if (d >= 300)
        OFFSET = d - 300;
    fo(i, n) cin >> x, a[x]++;
    cout << go(d, d) << endl;
    return 0;
}
