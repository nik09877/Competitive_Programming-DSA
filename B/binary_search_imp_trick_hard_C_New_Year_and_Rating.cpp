#include <bits/stdc++.h>
using namespace std;

#define IOS                  \
    ios::sync_with_stdio(0); \
    cin.tie(0);              \
    cout.tie(0);
#define endl "\n"
#define int long long

const int N = 2e5 + 5;

int n, final_rating;
int c[N], d[N];

int check(int cur_rating)
{
    int currentdiv;
    for (int i = 1; i <= n; i++)
    {
        currentdiv = 1;
        if (cur_rating < 1900)
            currentdiv = 2;
        if (d[i] != currentdiv)
        {
            if (currentdiv == 2) //Increase
                return 0;
            else //Decrease
                return -1;
        }
        cur_rating += c[i];
    }
    final_rating = cur_rating;
    return 1;
}

// Trick
// if using (find minimum value)-: while(l<r) if(good)h=m; else l=m+1 then use m=(l+r)>>1;

// else use(find max value) m = (l+r+1)/2;
// only works in while(l<r) because at end l==r

int binsearch(int lo, int hi)
{
    while (lo < hi)
    {
        int mid = (lo + hi + 1) >> 1;
        if (check(mid) == -1)
        {
            hi = mid - 1;
        }
        else if (check(mid) == 0)
        {
            lo = mid + 1;
        }
        else
            lo = mid;
    }
    return lo;
}

int32_t main()
{
    IOS;
    cin >> n;
    int check1 = 0;
    for (int i = 1; i <= n; i++)
    {
        cin >> c[i] >> d[i];
        check1 |= (d[i] == 2);
    }
    //if no div-2 infinity
    if (!check1)
    {
        cout << "Infinity";
        return 0;
    }
    // binary search on initial rating
    int ans = binsearch(-1e8, 1e8);
    if (check(ans) == 1)
        cout << final_rating;
    else
        cout << "Impossible";
}