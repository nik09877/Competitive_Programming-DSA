#include <iostream>
#include <vector>
#include <algorithm>
#include <numeric>

using namespace std;

const int64_t INF = 1e17;
inline int64_t mul(int64_t a, int64_t b)
{
    return (INF / a > b ? a * b : INF);
}

inline int64_t add(int64_t a, int64_t b)
{
    return (a + b >= INF ? INF : a + b);
}

int main()
{
    int n;
    cin >> n;

    vector<int> a(n);
    for (int &x : a)
        cin >> x;
    sort(a.begin(), a.end());

    if (n <= 2)
    {
        cout << a[0] - 1 << endl;
    }
    else
    {
        int64_t ans = accumulate(a.begin(), a.end(), 0ll) - n;

        for (int x = 1;; ++x)
        {
            int64_t curPow = 1, curCost = 0;
            for (int i = 0; i < n; ++i)
            {
                curCost = add(curCost, abs(a[i] - curPow));
                curPow = mul(curPow, x);
            }

            if (curPow == INF || curPow / x > ans + a[n - 1])
                break;
            ans = min(ans, curCost);
        }

        cout << ans << endl;
    }
}