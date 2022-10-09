/*

You are given an array ‘Arr’ of ‘N’ integers. A pair of indices [L,R] is said to be special if and only the size of the subarray from L to R is even, and the following condition is satisfied:

Arr[L] xor Arr[L+1] … xor Arr[mid] = Arr[mid+1] xor Arr[mid+2] … xor Arr[R]
where  ‘mid’ = (R-L+1)/2 and ‘xor’ represents the bitwise XOR operator.

Your task is to calculate the number of special pairs in the array.

*/

#include <bits/stdc++.h>
using namespace std;
const int mod = 1000000007;

// if even index length of [L,R] is even if even-odd+1 ie
// for even R , L should be odd and vice versa

int specialPairs(int n, vector<int> a)
{
    int ans = 0;
    map<int, vector<int>> odd, even;
    vector<int> pre(n);
    pre[0] = a[0];
    for (int i = 1; i < n; i++)
    {
        pre[i] = pre[i - 1] ^ a[i];
    }
    even[a[0]].push_back(0);
    for (int i = 1; i < n; i++)
    {
        if (pre[i] == 0 and (i + 1) % 2 == 0)
        {
            int m = (i + 1) / 2;
            int left = pre[m];
            int right = pre[i] ^ pre[m];
            if (left == right)
                ans++;
        }
        if (i & 1)
        {
            int target = pre[i];
            for (auto idx : odd[target])
            {
                int l = idx + 1, r = i;
                if (l < r)
                {
                    int m = (r - l + 1) / 2;
                    int left = pre[m] ^ (l - 1 >= 0 ? pre[l - 1] : 0);
                    int right = pre[r] ^ pre[m];
                    if (left == right)
                        ans++;
                }
            }
            odd[pre[i]].push_back(i);
        }
        else
        {
            int target = pre[i];
            for (auto idx : even[target])
            {
                int l = idx + 1, r = i;
                if (l < r)
                {
                    int m = (r - l + 1) / 2;
                    int left = pre[m] ^ (l - 1 >= 0 ? pre[l - 1] : 0);
                    int right = pre[r] ^ pre[m];
                    if (left == right)
                        ans++;
                }
            }
            even[pre[i]].push_back(i);
        }
    }
    return ans;
}

int32_t main()
{
    int t = 1;
    cin >> t;
    while (t--)
    {
        int n;
        cin >> n;
    }
}