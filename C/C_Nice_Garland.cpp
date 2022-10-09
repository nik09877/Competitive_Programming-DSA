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

    vector<int> p(3);
    iota(p.begin(), p.end(), 0);

    string colors = "RGB";
    string res = "";
    int ans = 1e9;

    do
    {
        string t;
        int cnt = 0;
        for (int i = 0; i < n; ++i)
        {
            t += colors[p[i % 3]];
            cnt += t[i] != s[i];
        }
        if (ans > cnt)
        {
            ans = cnt;
            res = t;
        }
    } while (next_permutation(p.begin(), p.end()));

    cout << ans << endl
         << res << endl;

    return 0;
}