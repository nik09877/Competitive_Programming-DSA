#include <bits/stdc++.h>

using namespace std;

// Any balanced bracket sequence must begin with '(' and end with ')'. Therefore, a and b must agree in the first and last positions, so we require s1=sn=1

// or a solution doesn't exist.

// The total number of open brackets in a
// and b must be n, which is even. Each 1 bit in s creates an even number of open brackets and each 0 bit creates an odd number of open brackets. Therefore, there must be an even number of 0 bits, or a solution doesn't exist. Note that the number of 1

// bits also must be even.

// Assuming these conditions hold, let's construct a solution. Suppose there are k
// positions where si=1. We will make the first k2 positions open in both a and b, and we will make the last k2 positions closed in both a and b. Then, the 0 bits in s will alternate between which string gets the open bracket.

void solve()
{
    int n;
    string s;
    cin >> n >> s;
    int cnt = 0;
    for (int i = 0; i < n; i++)
    {
        cnt += (s[i] == '1');
    }
    if (cnt % 2 == 1 || s[0] == '0' || s.back() == '0')
    {
        cout << "NO\n";
        return;
    }
    string a, b;
    int k = 0;
    bool flip = false;
    for (int i = 0; i < n; i++)
    {
        if (s[i] == '1')
        {
            a.push_back(2 * k < cnt ? '(' : ')');
            b.push_back(a.back());
            k++;
        }
        else
        {
            a.push_back(flip ? '(' : ')');
            b.push_back(flip ? ')' : '(');
            flip = !flip;
        }
    }
    cout << "YES\n"
         << a << '\n'
         << b << '\n';
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    int te;
    cin >> te;
    while (te--)
        solve();
}