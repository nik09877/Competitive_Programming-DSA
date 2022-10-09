#include <iostream>
using namespace std;
const int MAX = 1000100;
int a[MAX];
int main()
{
    ios::sync_with_stdio(false);
    int n;
    cin >> n;
    for (int i = 0; i < n; i++)
    {
        int x;
        cin >> x;
        a[x]++;
    }
    int ans = 0;
    for (int i = 0; i < MAX - 1; i++)
    {
        a[i + 1] += a[i] / 2;
        a[i] %= 2;
        ans += a[i];
    }
    cout << ans << endl;
    return 0;
}