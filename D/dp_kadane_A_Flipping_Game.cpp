#include <bits/stdc++.h>
using namespace std;
int main()
{
    int n;
    cin >> n;
    int a[n], sum = 0, one = 0, m = INT_MIN;
    for (int i = 0; i < n; i++)
    {
        cin >> a[i];
        one += a[i];
        if (a[i])
            sum--;
        else
            sum++;
        if (sum < 0)
            sum = 0;
        m = max(m, sum);
    }
    cout << m + one;
}