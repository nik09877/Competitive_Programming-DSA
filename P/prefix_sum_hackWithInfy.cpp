#include <bits/stdc++.h>
using namespace std;

//!given an array you have to get sum x ,but u can only take values from either ends ,find minimum values required to get sum x

int minimumWithdrawal(vector<int> a, int x)
{
    long long int sum = 0;
    int n = (int)a.size();
    for (int val : a)
        sum += val;
    if (sum < x)
        return -1;
    else if (sum == x)
        return n;

    long long int pre[n], suf[n];
    map<long long int, int> pre_map, suf_map;
    int pre_ans = INT_MAX, suf_ans = INT_MAX;

    pre[0] = a[0];
    if (pre[0] == x)
        pre_ans = min(pre_ans, 1);
    pre_map[pre[0]] = 0;
    for (int i = 1; i < n; i++)
    {
        pre[i] = a[i] + pre[i - 1];
        pre_map[pre[i]] = i;
        if (pre[i] == x)
            pre_ans = min(pre_ans, i + 1);
    }

    suf[n - 1] = a[n - 1];
    if (suf[n - 1] == x)
        suf_ans = min(suf_ans, 1);
    suf_map[suf[n - 1]] = n - 1;
    for (int i = n - 2; i >= 0; i--)
    {
        suf[i] = a[i] + suf[i + 1];
        if (suf[i] == x)
            suf_ans = min(suf_ans, -(i) + n);
        suf_map[suf[i]] = i;
    }

    for (int i = 0; i < n; i++)
    {
        if (suf_map.find(x - pre[i]) != suf_map.end())
        {
            if (suf_map[x - pre[i]] > i)
            {
                int total_el = i + 1 - suf_map[x - pre[i]] + n;
                pre_ans = min(pre_ans, total_el);
            }
        }
    }

    for (int i = n - 1; i >= 0; i--)
    {
        if (pre_map.find(x - suf[i]) != pre_map.end())
        {
            if (pre_map[x - suf[i]] < i)
            {
                int total_el = -i + n + pre_map[x - suf[i]] + 1;
                suf_ans = min(suf_ans, total_el);
            }
        }
    }

    int ans = min(pre_ans, suf_ans);
    if (ans == INT_MAX)
        return -1;
    return ans;
}
int main()
{
    int N;
    cin >> N;
    vector<int> ATM(N);
    for (int j = 0; j < N; j++)
    {
        cin >> ATM[j];
    }
    int X;
    cin >> X;
    int result;
    result = minimumWithdrawal(ATM, X);
    cout << result;
    return 0;
}