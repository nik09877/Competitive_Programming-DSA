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
#define int long long int
const int mod = 1000000007;

/*
1-> use merge sort
2-> use ordered_set
3-> use coordinate compression + segment tree + point update + range sum query ( find number of elements in a given range)
*/
class Solution2
{
    /*
    Given an integer array nums, return the number of reverse pairs in the array.
    A reverse pair is a pair (i, j) where 0 <= i < j < nums.length and nums[i] > 2 * nums[j].
    */
public:
    // using vi = vector<int>;
    int n, ans;

    void merge(int l, int m, int r, vi &a)
    {
        vi temp;
        int cnt = 0, i = l, j = m + 1;

        // count answer
        for (; i <= m; i++)
        {
            while (j <= r and a[i] * 1ll > 2 * 1ll * a[j])
                j++, cnt++;
            ans += cnt;
        }

        i = l, j = m + 1;

        while (i <= m and j <= r)
        {
            if (a[i] <= a[j])
            {
                temp.push_back(a[i]);
                i++;
            }
            else
            {
                temp.push_back(a[j]);
                j++;
            }
        }
        while (i <= m)
            temp.push_back(a[i++]);
        while (j <= r)
            temp.push_back(a[j++]);
        for (int idx = l; idx <= r; idx++)
            a[idx] = temp[idx - l];
        return;
    }
    void mergeSort(int l, int r, vi &a)
    {
        if (l < r)
        {
            int m = (l + r) / 2;
            mergeSort(l, m, a);
            mergeSort(m + 1, r, a);
            merge(l, m, r, a);
        }
    }
    int reversePairs(vector<int> &a)
    {
        n = a.size(), ans = 0;
        mergeSort(0, n - 1, a);
        return ans;
    }
};

class Solution
{
public:
    // merge sort [l,r) is considered here
    vector<int> countSmaller(vector<int> &nums)
    {
        // new array
        vector<pair<int, int>> arr;
        vector<int> count(nums.size(), 0);

        for (int i = 0; i < nums.size(); i++)
        {
            arr.push_back({nums[i], i});
        }

        merge_with_inversions(0, nums.size(), arr, count);
        return count;
    }

    // merge with couting inversions

    void merge_with_inversions(int start, int end, vector<pair<int, int>> &arr, vector<int> &count)
    {
        if (start < end && end - start > 1)
        {
            int mid = start + (end - start) / 2;

            merge_with_inversions(start, mid, arr, count);
            merge_with_inversions(mid, end, arr, count);

            vpii ans;
            int i = start, j = mid;

            int inversions = 0;
            while (i < mid && j < end)
            {
                if (arr[i].first <= arr[j].first)
                {
                    ans.push_back(arr[i]);
                    count[arr[i].second] += inversions;
                    i++;
                }
                else
                {
                    // we have an inversion here
                    // element of second array is smaller than first so increment its value
                    ans.push_back(arr[j]);
                    inversions++;
                    j++;
                }
            }
            // as the left block elements are left that means the right block elements are smaller than the current remaining elements,so add the inversion count
            while (i < mid)
            {
                ans.push_back(arr[i]);
                count[arr[i].second] += inversions;
                i++;
            }

            while (j < end)
            {
                ans.push_back(arr[j]);
                j++;
            }

            // copying ans to original array
            j = 0;
            for (int i = start; i < end; i++)
            {
                arr[i] = ans[j];
                j++;
            }
        }
    }
};

void solve()
{
    int n;
    cin >> n;
    return;
}
int32_t main()
{
    fastio;
    int t = 1;
    cin >> t;
    while (t--)
    {
        solve();
    }
    // #ifndef ONLINE_JUDGE
    //     TIME;
    // #endif
}