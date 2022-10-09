#include <bits/stdc++.h>
using namespace std;
#define endl "\n"
#define fo(i, s, e) for (i = s; i < e; i++)
#define rfo(i, s, e) for (i = s; i > e; i--)
#define LL long long int
const LL MOD = 1e9 + 7;
#define pb push_back
#define pob pop_back()
#define sp " "
#define ff first
#define ss second
#define sz(x) ((LL)x.size())
#define TIME cerr << "Time Taken:" << (float)clock() / CLOCKS_PER_SEC * 1000 << "ms" << endl
//  When something is important enough, you do it even if the odds are not in your favor.
/*
Key Idea:

Binary search over the answer and check if given x
, it is possible to form a subsequence of length at least k such that either all elements at odd indices or even indices are ≤x

.

Solution:

Let us binary search over the answer and fix if the answer comes from elements at odd or even indices in the subsequence. Suppose we want to find if there exists a subsequence of length at least k
such that the elements at odd indices are ≤x

. We will construct the subsequence greedily.

Let's iterate on the array from left to right. Suppose we are at index i
in the array and the current length of the subsequence formed is l. If l is odd, the next added element would be at an even index. In this case, we do not care about what this element is as we only want elements at odd indices to be ≤x. So, in this case, we add ai to the subsequence. If l is even, then the next added element would be at an odd index, so, it must be ≤x. If ai≤x, we can add ai to the subsequence, otherwise we do not add ai to the subsequence and continue to the next element in a

.

Note that we can do a similar greedy construction for elements at even indices. If the length of the subsequence formed is ≥k
(either by construction from odd indices or even indices), then the answer can be equal to x and we can reduce the upper bound of the binary search otherwise we increase the lower bound.
*/
LL check(LL a[], LL n, LL k, LL mx)
{
    LL i, j, f = 0;
    LL tot = 0, turn = 0;
    fo(i, 0, n)
    {
        if (turn == 0)
        {
            if (a[i] <= mx)
            {
                tot++;
                turn ^= 1;
            }
        }
        else
        {
            tot++;
            turn ^= 1;
        }
    }
    if (tot >= k)
        f = 1;

    tot = 0, turn = 0;
    fo(i, 0, n)
    {
        if (turn == 0)
        {
            tot++;
            turn ^= 1;
        }
        else
        {
            if (a[i] <= mx)
            {
                tot++;
                turn ^= 1;
            }
        }
    }
    // if(mx==2) cout<<tot<<endl;
    if (tot >= k)
        f = 1;
    return f;
}
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    LL test = 1; // cin>>test;
    while (test--)
    {
        LL n, k, i, j;
        cin >> n >> k;
        LL a[n];
        fo(i, 0, n) cin >> a[i];
        LL l = 1, r = 1e9, ans;
        while (l <= r)
        {
            LL mid = (l + r) / 2;
            if (check(a, n, k, mid))
            {
                ans = mid;
                r = mid - 1;
            }
            else
                l = mid + 1;
        }
        cout << ans;
    }

    return 0;
}