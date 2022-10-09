/*given array a of length n and fibonacci series b of length n.
Find the LCS of array a which is a prefix of array b*/
#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    bool good(int len, int *a, vector<int> &b, int n)
    {
        int i = 0, j = 0;
        while (i < n and j < len)
        {
            if (a[i] == b[j])
                i++, j++;
            else
                i++;
        }
        return j == len;
    }
    int solve(int n, int a[])
    {
        vector<int> b(n);
        b[0] = 1;
        if (n > 1)
            b[1] = 1;
        for (int i = 2; i < n; i++)
            b[i] = b[i - 1] + b[i - 2];

        int l = 0, r = n, ans = 0;
        while (l <= r)
        {
            int m = (l + r) >> 1;
            if (good(m, a, b, n))
                ans = m, l = m + 1;
            else
                r = m - 1;
        }
        return ans;
    }
};

int main()
{

    return 0;
}