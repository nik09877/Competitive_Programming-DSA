#include <iostream>
using namespace std;
//!EDITORIAL
// For S≥2N Petya wins: let's take array [2,2,…,2,S−2(N−1)] and K=1. All the elements are strictly greater than 1, so there are no segment with sum 1 or S−1.

// Let's prove that for S<2N Petya will lose. Suppose it is not true and there exist an array and K>0 (it is obvious that K=0 is bad). Note that the condition that there is a segment with sum K or S−K is equivalent to the condition that there is a segment with sum K in cyclic array. Let's calculate prefix sums for our array, and for prefix sum M let's mark all the numbers of the form M+TS for integer T≥0. It is easy to see that numbers X and X+K cannot be marked simultaneously: otherwise there is a segment with sum K in a cyclic array. Let's consider half-interval [0;2KS). It is clear that exactly 2KN numbers are marked on this half-interval. On the other hand, we can split all the numbers from this half-interval into KS pairs with difference K: (0,K),(1,K+1),…,(K−1,2K−1),(2K,3K),(2K+1,3K+1),…(2KS−K−1,2KS−1). In every such pair no more than one number is marked, so the total number of marked numbers is bounded by KS. Therefore 2KN≤KS which means 2N≤S. Contradiction.
int main()
{
    int n, s;
    cin >> n >> s;

    if (2 * n <= s)
    {
        cout << "YES\n";
        for (int i = 0; i < n - 1; i++)
        {
            cout << 2 << ' ';
            s -= 2;
        }
        cout << s << '\n'
             << 1;
    }
    else
    {
        cout << "NO";
    }
    return 0;
}