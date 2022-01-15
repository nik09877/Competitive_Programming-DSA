#include <bits/stdc++.h>
using namespace std;
#define sim template <class c
#define ris return *this
#define dor > debug &operator<<
#define eni(x)                                                                    \
    sim > typename enable_if<sizeof dud<c>(0) x 1, debug &>::type operator<<(c i) \
    {
sim > struct rge
{
    c b, e;
};
sim > rge<c> range(c i, c j) { return rge<c>{i, j}; }
sim > auto dud(c *x) -> decltype(cerr << *x, 0);
sim > char dud(...);
struct debug
{
#ifdef LOCAL
    ~debug()
    {
        cerr << endl;
    }
    eni(!=) cerr << boolalpha << i;
    ris;
} eni(==) ris << range(begin(i), end(i));
}
sim, class b dor(pair<b, c> d)
{
    ris << "(" << d.first << ", " << d.second << ")";
}
sim dor(rge<c> d)
{
    *this << "[";
    for (auto it = d.b; it != d.e; ++it)
        *this << ", " + 2 * (it == d.b) << *it;
    ris << "]";
}
#else
    sim dor(const c &)
    {
        ris;
    }
#endif
}
;
#define imie(x) " [" << #x ": " << (x) << "] "

// Obviously, the answer to the problem can not be greater than the minimum length among the lengths of the sub-arrays. Suppose that the minimum length of all the sub-arrays is equal to len. Then the desired array is: 0, 1, 2, 3, ..., len - 1, 0, 1, 2, 3, ... len - 1... . Not hard to make sure that mex of any subarray will be at least len.

// cycle -> 0 1 2 ... len-1 0 1 2 ...

int main()
{
    int n, m;
    scanf("%d%d", &n, &m);
    int k = n + 5;
    for (int i = 0; i < m; ++i)
    {
        int a, b;
        scanf("%d%d", &a, &b);
        k = min(k, b - a + 1);
    }
    printf("%d\n", k);
    int tmp = 0;
    for (int i = 0; i < n; ++i)
    {
        printf("%d ", tmp);
        ++tmp;
        if (tmp >= k)
            tmp = 0;
    }
    puts("");
}
