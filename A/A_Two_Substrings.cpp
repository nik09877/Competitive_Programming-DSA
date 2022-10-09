#include <bits/stdc++.h>
using namespace std;
#define vi vector<int>
#define pb push_back

int main()
{
    // your code goes here
    string a;
    cin >> a;
    int i;
    a += '@';
    a += '@';
    vi one, two;
    bool overlap = false;
    for (i = 0; a[i] != '@'; i++)
    {
        if (a[i] == 'A' && a[i + 1] == 'B')
            one.pb(i);
        if (a[i] == 'B' && a[i + 1] == 'A')
            two.pb(i);
    }
    if (one.size() == 0 | two.size() == 0)
    {
        cout << "NO\n";
        return 0;
    }

    int x = one.front();
    int y = one.back();
    int X = two.front();
    int Y = two.back();
    if ((Y - x) >= 2 | (y - X) >= 2)
        cout << "YES\n";
    else
        cout << "NO\n";
    return 0;
}