
#include <bits/stdc++.h>
using namespace std;
int main()
{
    string s;
    cin >> s;
    int k = s.find('0');
    (k == -1) ? s.erase(0, 1) : s.erase(k, 1);
    cout << s;
}