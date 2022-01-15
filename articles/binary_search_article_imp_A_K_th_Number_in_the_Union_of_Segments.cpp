#pragma GCC optimize("Ofast")
#pragma GCC target("avx,avx2,fma")
#pragma GCC optimization("unroll-loops")
#include <bits/stdc++.h>
#define rep(i, n) for (int i = 0; i < n; i++)
#define rrep(i, a, b) for (int i = a; i >= b; i--)
#define rep1(i, n) for (int i = 1; i <= n; i++)
#define fo(i, a, n) for (int i = a; i <= n; i++)
#define mkp make_pair
#define pb emplace_back
#define ff first
#define ss second
#define ll long long
#define ii int, int
#define pii pair<int, int>
#define vi vector<int>
#define vvi vector<vector<int>>
#define vpii vector<pair<int, int>>
#define MAXLL 1e18
#define endl '\n'
#define sp ' '
#define dsort(v) sort(v.begin(), v.end(), greater<int>())
#define asort(v) sort(v.begin(), v.end())
#define uniq(v) v.erase(unique(v.begin(), v.end()), v.end())
#define all(v) v.begin(), v.end()
#define umap unordered_map
#define uset unordered_set
#define sz(x) ((int)(x).size())
#define yes cout << "YES\n"
#define no cout << "NO\n"
#define pr(x) cout << x
#define prsp(x) cout << x << sp
#define prln(x) cout << x << endl
#define TIME cerr << "Time Taken:" << (float)clock() / CLOCKS_PER_SEC * 1000 << "ms" << endl
#define fastio ios_base::sync_with_stdio(0), cin.tie(0)
#define re(a, n)   \
    rep(i, n)      \
            cin >> \
        a[i];
using namespace std;

/*
If you do not sacrifice for what you want, What you want becomes the sacrifice.
1-Brute Force (complete search)(bitmask)(Number theory)
2-greedy sorting two pointer
3-Binary Search
4-dp
5-prefix sum
6-graph,bit manipulation(dependency)
7-segment tree (fenwick tree)

1-try going backward if given find A to B ,you find B to A
2-try out small test cases or do brute force solutions to find pattern
3- dont get stuck on only one approach
*/
#define int long long int
const int mod = 1000000007;

int n, k;
vpii a;

// Is it monotonic?
// no of elements less than x can be atmost k ie (cnt <= k) and no of elements less than x+1 will be > k ,so
// we found our break point and we just have to find the maximum x such that no. of elements less than x are <=k

// If there are only two arrays , do binary search on the number of elements to be included from one array so that the elements from other array are choosen automatically
bool good(int x)
{
    int cnt = 0;
    rep(i, n)
    {
        if (a[i].ff >= x)
            continue;
        // check if segment is completely < x or partially
        cnt += min(x - a[i].ff, a[i].ss - a[i].ff + 1);
    }
    return cnt <= k;
}
void solve()
{
    int l = 3e9, r = -3e9;
    cin >> n >> k;
    a.resize(n);
    rep(i, n)
    {
        cin >> a[i].ff >> a[i].ss;
        l = min(l, a[i].ff), r = max(r, a[i].ss);
    }
    int ans = -3e9;
    while (l <= r)
    {
        int m = (l + r) >> 1;
        if (good(m))
        {
            ans = m;
            l = m + 1;
        }
        else
            r = m - 1;
    }
    prln(ans);
    return;
}
int32_t main()
{
    fastio;
    int t = 1;
    // cin >> t;
    while (t--)
    {
        solve();
    }
    // #ifndef ONLINE_JUDGE
    //     TIME;
    // #endif
}

double findMedianSortedArrays(vector<int> &nums1, vector<int> &nums2)
{
    if (nums2.size() < nums1.size())
        return findMedianSortedArrays(nums2, nums1);
    int n1 = nums1.size();
    int n2 = nums2.size();
    int low = 0, high = n1;

    while (low <= high)
    {
        int cut1 = (low + high) >> 1;
        int cut2 = (n1 + n2 + 1) / 2 - cut1;

        int left1 = cut1 == 0 ? INT_MIN : nums1[cut1 - 1];
        int left2 = cut2 == 0 ? INT_MIN : nums2[cut2 - 1];

        int right1 = cut1 == n1 ? INT_MAX : nums1[cut1];
        int right2 = cut2 == n2 ? INT_MAX : nums2[cut2];

        if (max(left1, left2) <= min(right1, right2))
        {
            if ((n1 + n2) % 2 == 0)
                return (max(left1, left2) + min(right1, right2)) / 2.0;
            else
                return max(left1, left2);
        }
        else if (left1 > right2)
        {
            high = cut1 - 1;
        }
        else
        {
            low = cut1 + 1;
        }
    }
    return 0.0;
}

int kthElement(int arr1[], int arr2[], int n, int m, int k)
{
    if (n > m)
        return kthElement(arr2, arr1, m, n, k);

    // minimum k-m elements need to be included
    // example-> k = 8 and n=4,m=6 , so minimum 2 elements from arr1
    // need to be included

    int l = max(0ll, k - m), r = min(n, k);
    while (l <= r)
    {
        int cut1 = (l + r) >> 1;
        int cut2 = k - cut1;

        int l1 = cut1 == 0 ? INT_MIN : arr1[cut1 - 1];
        int l2 = cut2 == 0 ? INT_MIN : arr2[cut2 - 1];
        int r1 = cut1 == n ? INT_MAX : arr1[cut1];
        int r2 = cut2 == m ? INT_MAX : arr2[cut2];

        // if(l1 <= r2 && l2 <= r1) {
        //     return max(l1, l2);
        // }
        if (max(l1, l2) <= min(r1, r2))
        {
            return max(l1, l2);
        }
        else if (l1 > r2)
        {
            r = cut1 - 1;
        }
        else
        {
            l = cut1 + 1;
        }
    }
    return -1;
}

bool ok(int mid, vector<vector<int>> &a, int n, int m, int total)
{
    int cnt = 0;
    for (int i = 0; i < n; i++)
    {
        cnt += lower_bound(a[i].begin(), a[i].end(), mid) - a[i].begin();
    }
    return cnt <= ((total) / 2);
}
int findMedian(vector<vector<int>> &a)
{
    int n = a.size();
    int m = a[0].size();
    int l = INT_MAX, r = INT_MIN, ans = -1, total = n * m;
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            l = min(l, a[i][j]);
            r = max(r, a[i][j]);
        }
    }
    while (l <= r)
    {
        int mid = (l + r) >> 1;
        if (ok(mid, a, n, m, total))
        {
            ans = mid;
            l = mid + 1;
        }
        else
            r = mid - 1;
    }
    return ans;
}