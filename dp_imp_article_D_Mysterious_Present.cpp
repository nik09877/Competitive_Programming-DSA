#include <bits/stdc++.h>
#define REP(i, n) for (int i = 1; i <= n; i++)
#define mod 1000000007
#define pb push_back
#define ff first
#define ss second
#define ii pair<int, int>
#define vi vector<int>
#define vii vector<ii>
#define lli long long int
#define INF 1000000000
#define endl '\n'
const double PI = 3.141592653589793238460;
typedef std::complex<double> Complex;
typedef std::valarray<Complex> CArray;

using namespace std;
struct envelop
{
    int w;
    int h;
    int idx;
};
envelop ar[5001];

bool comp(envelop a, envelop b)
{
    return a.w > b.w;
}

// dp[i] denotes max answer ending at i

int main()
{
    int n, w, h;
    cin >> n >> w >> h;

    REP(i, n)
    {
        cin >> ar[i].w >> ar[i].h, ar[i].idx = i;
    }

    sort(ar + 1, ar + n + 1, comp);

    vi dp(n + 1);
    vi pre(n + 1);

    for (int i = 1; i <= n; i++)
    {
        int mx = 0;
        int preEle = i;

        for (int j = 1; j < i; j++)
        {
            if (ar[j].w > ar[i].w && ar[j].h > ar[i].h && dp[j] > mx)
                mx = dp[j], preEle = j;
        }
        dp[i] = mx + 1;
        pre[i] = preEle;
    }

    int ans = 0;
    int endPoint = 0;
    for (int i = 1; i <= n; i++)
        if (ar[i].w > w && ar[i].h > h && dp[i] > ans)
            ans = dp[i], endPoint = i;

    if (ans == 0)
    {
        cout << 0;
    }
    else
    {
        cout << ans << endl;
        while (1)
        {
            cout << ar[endPoint].idx << ' ';

            if (endPoint == pre[endPoint])
                break;

            endPoint = pre[endPoint];
        }
    }
}
