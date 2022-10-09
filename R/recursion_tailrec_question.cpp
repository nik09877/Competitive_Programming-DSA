#include <bits/stdc++.h>
using namespace std;

int fib(int n, int a, int b)
{
    if (n == 0 || n == 1)
        return b;
    return fib(n - 1, b, a + b);
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int t;
    cin >> t;
    while (t--)
    {
        int n;
        cin >> n;
        cout << fib(n, 1, 1) << endl;
    }
}