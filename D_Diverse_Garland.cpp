#include <bits/stdc++.h>

using namespace std;

int main()
{
#ifdef _DEBUG
    freopen("input.txt", "r", stdin);
//	freopen("output.txt", "w", stdout);
#endif

    int n;
    string s;
    cin >> n >> s;

    int ans = 0;
    for (int i = 0; i < n; ++i)
    {
        int j = i;
        while (j < n && s[i] == s[j])
        {
            ++j;
        }
        string q = "RGB";
        q.erase(q.find(s[i]), 1);
        if (j < n)
            q.erase(q.find(s[j]), 1);
        for (int k = i + 1; k < j; k += 2)
        {
            ++ans;
            s[k] = q[0];
        }
        i = j - 1;
    }

    cout << ans << endl
         << s << endl;

    return 0;
}