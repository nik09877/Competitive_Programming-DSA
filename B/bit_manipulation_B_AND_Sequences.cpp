#include <bits/stdc++.h>
using namespace std;
//!EDITORIAL
// Consider an arbitrary sequence b1,b2,…,bn. First let us define the arrays AND_pref and AND_suf of length n where AND_prefi=b1&b2&…&bi and AND_sufi=bi&bi+1&…&bn .

// According to the definition of good sequence:

// AND_pref1=AND_suf2 which means b1=b2&b3&…&bn .

// Now AND_pref2≤AND_pref1=AND_suf2≤AND_suf3. Also according to definition of good sequence, AND_pref2=AND_suf3. This means that b1=AND_pref2=AND_suf3. Similarly, for all i from 1 to n, we get AND_prefi=b1 and AND_sufi=b1.

// Therefore for the sequence to be good, b1=bn and the bi must be a super mask of b1 for all i from 2 to n−1.

// Initially, we have an array a1,a2,…,an. Let the minimum value among these elements be x. Let the number of elements that have the value of x be cnt.

// In order to rearrange the elements of a1,a2,…,an to a good sequence, we need to have cnt≥2 and the remaining elements need to be a super mask of x. If we don't meet this criterion, then the answer is 0. Else the answer will be (cnt⋅(cnt−1)⋅(n−2)!)%(109+7).
void solveTestCase()
{
    int MOD = 1e9 + 7;
    int n;
    cin >> n;
    vector<int> a(n);
    for (int i = 0; i < n; i++)
        cin >> a[i];

    int min1 = *min_element(a.begin(), a.end());
    int cnt = 0;

    for (int x : a)
    {
        if (min1 == x)
            cnt++;
        if ((min1 & x) != min1)
        {
            printf("0\n");
            return;
        }
    }

    int fact = 1;
    for (int i = 1; i <= n - 2; i++)
        fact = (1LL * fact * i) % MOD;
    int ans = (1LL * cnt * (cnt - 1)) % MOD;
    ans = (1LL * ans * fact) % MOD;
    printf("%d\n", ans);
}

int main()
{
    int tests;
    cin >> tests;
    while (tests--)
        solveTestCase();
    return 0;
}