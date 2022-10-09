#include <bits/stdc++.h>

using namespace std;

int main()
{
#ifdef _DEBUG
    freopen("input.txt", "r", stdin);
//	freopen("output.txt", "w", stdout);
#endif

    int t;
    cin >> t;
    while (t--)
    {
        int n;
        string x;
        cin >> n >> x;
        string a(n, '0'), b(n, '0');
        for (int i = 0; i < n; ++i)
        {
            if (x[i] == '1')
            {
                a[i] = '1';
                b[i] = '0';
                for (int j = i + 1; j < n; ++j)
                {
                    b[j] = x[j];
                }
                break;
            }
            else
            {
                a[i] = b[i] = '0' + (x[i] - '0') / 2;
            }
        }
        cout << a << endl
             << b << endl;
    }

    return 0;
}