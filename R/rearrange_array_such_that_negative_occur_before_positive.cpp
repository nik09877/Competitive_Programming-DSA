//Implementation in C++
#include <bits/stdc++.h>
using namespace std;

//Comparator function.
bool comp(int a, int b)
{
    //  no need to swap
    //  (if both elements are positive)
    //  or (negative)
    //  or (they are already rearranged like we wanted)
    //  or (the element that occurs later in the array is 0 and the element that occurs first in the array is negative)
    //  or (the element that occurs in the array is greater than 0 and the element that occurs first in the array is 0).
    if ((a > 0 and b > 0) or (a < 0 and b < 0) or (a > 0 and b < 0) or (a == 0 and b < 0) or (a > 0 and b == 0))
        return false;

    // swap
    // (if the positive element occurs before the negative element)
    // or (the element that occurs later in the array is 0 and the element that occurs first in the array is positive)
    // or (the element that occurs later in the array is negative and the element that occurs first in the array is 0).
    if ((a < 0 and b > 0) or (a < 0 and b == 0) or (a == 0 and b > 0))
        return true;
    return true;
}

//Function to rearrange array.
void rearrange(vector<int> &arr)
{
    sort(arr.begin(), arr.end(), comp);
}

int main()
{
    //n is the size of the array
    int n;

    //read n
    cin >> n;

    vector<int> arr(n);
    //read the input array
    for (int i = 0; i < n; i++)
        cin >> arr[i];

    //Rearrange array
    rearrange(arr);

    //print the array
    for (int i = 0; i < n; i++)
        cout << arr[i] << " ";

    return 0;
}