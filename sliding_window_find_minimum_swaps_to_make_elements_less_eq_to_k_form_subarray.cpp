//Code
#include <bits/stdc++.h>
using namespace std;

//Function that returns minimum swaps required to bring elements less than equal to k together.
int get_min_swaps(vector<int> &arr, int n, int k)
{
    //count the number of elements less than equal to k.
    int less_equal_cnt = 0;
    for (int i = 0; i < n; i++)
        if (arr[i] <= k)
            less_equal_cnt++;

    //l denotes the left boundary of sliding window.
    //r denotes the right boundary of sliding window.
    //greater_cnt denotes the number of elements greater than k present in the current sliding window.
    int l = 0, r = 0, greater_cnt = 0, ans = n;

    for (; r < less_equal_cnt; r++)
        if (arr[r] > k)
            greater_cnt++;

    //move the sliding window until we have processed the whole array.
    for (; r <= n; l++, r++)
    {
        //update the answer
        ans = min(ans, greater_cnt);

        //break out of the loop if we have processed the whole array.
        if (r == n)
            break;

        //add the contribution of the current sliding window to the greater_cnt.
        if (arr[r] > k)
            greater_cnt++;

        //remove the contribution of the previous sliding window from the greater_cnt.
        if (arr[l] > k)
            greater_cnt--;
    }
    return ans;
}
int main()
{

    //n is the size of the array
    int n, k;

    //read n and k
    cin >> n >> k;

    vector<int> arr(n);
    //read the input array
    for (int i = 0; i < n; i++)
        cin >> arr[i];

    //get minimum swaps
    int ans = get_min_swaps(arr, n, k);

    //print the answer
    cout << "The minimum number of swaps required is " << ans;
    return 0;
}