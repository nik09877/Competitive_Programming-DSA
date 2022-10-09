#include <bits/stdc++.h>

using namespace std;
/*
Note that if 2·ai ≤ ai + 1, then it doesn't make sense to buy any bottles of type i + 1 — it won't ever be worse to buy two bottles of type i instead. In this case let's assume that we actually have an option to buy a bottle of type i + 1 at the cost of 2·ai and replace ai + 1 with min(ai + 1, 2·ai). Let's do this for all i from 1 to n - 1 in increasing order.

Now for all i it's true that 2·ai ≥ ai + 1. Note that now it doesn't make sense to buy more than one bottle of type i if i < n. Indeed, in this case it won't ever be worse to buy a bottle of type i + 1 instead of two bottles of type i. From now on, we'll only search for options where we buy at most one bottle of every type except the last one.

Suppose that we had to buy exactly L liters of lemonade, as opposed to at least L. Note that in this case the last n - 1 bits of L uniquely determine which bottles of types less than n we have to buy. Indeed, if L is odd, then we have to buy a bottle of type 0, otherwise we can't do that. By the same line of thought, it's easy to see that bit j in the binary representation of L is responsible for whether we should buy a bottle of type j. Finally, we have to buy exactly ⌊ L / 2n - 1⌋ bottles of type n.

But what to do with the fact that we're allowed to buy more than L liters? Suppose we buy M > L liters. Consider the highest bit j in which M and L differ. Since M > L, the j-th bit in M is 1, and the j-th bit in L is 0. But then all bits lower than the j-th in M are 0 in the optimal answer, since these bits are responsible for the "extra" bottles — those for which we spend money for some reason, but without which we would still have M > L.

Thus, here is the overall solution. Loop over the highest bit j in which M differs from L. Form the value of M, taking bits higher than the j-th from L, setting the j-th bit in M to 1, and bits lower than the j-th to 0. Calculate the amount of money we have to pay to buy exactly M liters of lemonade. Take the minimum over all j.

The complexity of the solution is O(n) or O(n2), depending on the implementation.
*/
int main()
{
    int n, L;
    scanf("%d %d", &n, &L);
    vector<int> c(n);
    for (int i = 0; i < n; i++)
    {
        scanf("%d", &c[i]);
    }
    for (int i = 0; i < n - 1; i++)
    {
        c[i + 1] = min(c[i + 1], 2 * c[i]);
    }
    long long ans = (long long)4e18;
    long long sum = 0;
    for (int i = n - 1; i >= 0; i--)
    {
        int need = L / (1 << i);
        sum += (long long)need * c[i];
        L -= need << i;
        ans = min(ans, sum + (L > 0) * c[i]);
    }
    cout << ans << endl;
    return 0;
}