#include <bits/stdc++.h>

using namespace std;

int main()
{
#ifdef _DEBUG
    freopen("input.txt", "r", stdin);
//	freopen("output.txt", "w", stdout);
#endif

    int q;
    cin >> q;
    while (q--)
    {
        int n;
        long long k;
        string s;
        cin >> n >> k >> s;
        string res;
        int cnt = 0;
        bool printed = false;
        for (int i = 0; i < n; ++i)
        {
            if (s[i] == '0')
            {
                if (cnt <= k)
                {
                    res += '0';
                    k -= cnt;
                }
                else
                {
                    res += string(cnt - k, '1');
                    res += '0';
                    res += string(k, '1');
                    res += s.substr(i + 1);
                    cout << res << endl;
                    printed = true;
                    break;
                }
            }
            else
            {
                ++cnt;
            }
        }

        if (!printed)
        {
            res += string(cnt, '1');
            cout << res << endl;
        }
    }

    return 0;
}