#include <bits/stdc++.h>
using namespace std;

int main()
{
    int mod = 1e9 + 7;
    int a, n;
    cin >> a >> n;
    vector<int> arr;
    for (int i = 1; i <= n; i++)
    {
        if (i == a)
            continue;
        else
            arr.push_back(i);
    }

    // if element belongs to set 1 colour it 0
    // if it belongs to set 2 colour it 1
    // else if it is a colour it 2
    vector<int> ans(n + 1, 1);
    ans[a] = 2;

    n = arr.size();

    int sum = 0;
    for (int i = 0; i < n; i++)
        sum += arr[i];
    if (sum % 2)
    {
        cout << "impossible" << endl;
        return 0;
    }
    int k = sum / 2;
    bool t[n + 1][k + 1];

    for (int i = 0; i <= k; i++)
        t[0][i] = false;
    for (int i = 0; i <= n; i++)
        t[i][0] = true;

    for (int i = 1; i <= n; i++)
        for (int j = 1; j <= k; j++)
        {
            if (arr[i - 1] <= k)
            {
                t[i][j] = t[i - 1][j - arr[i - 1]] || t[i - 1][j];
            }
            else
                t[i][j] = t[i - 1][j];
        }

    if (t[n][k] == 0)
    {
        cout << "impossible" << endl;
        return 0;
    }
    int i = n, j = k;
    while (i > 0)
    {
        if (arr[i - 1] <= j and t[i - 1][j - arr[i - 1]])
        {
            ans[arr[i - 1]] = 0;
            j -= arr[i - 1];
            i--;
        }
        else
            i--;
    }
    for (int i = 1; i < ans.size(); i++)
        cout << ans[i] << " ";
    return 0;
}