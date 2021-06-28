#include <iostream>
#include <cstdint>

using namespace std;

// https://codeforces.com/problemset/problem/785/C

int main()
{
    ios_base::sync_with_stdio(false);
    int64_t n, m;
    cin >> n >> m;
    if (n <= m)
    {
        cout << n << endl;
    }
    else
    {
        n -= m;
        int64_t l = 0, r = 2e9;
        while (l < r)
        {
            int64_t m = (l + r) / 2;
            int64_t val = m * (m + 1) / 2;
            if (val >= n)
            {
                r = m;
            }
            else
            {
                l = m + 1;
            }
        }
        cout << l + m << endl;
    }
    return 0;
}