#include <bits/stdc++.h>

using namespace std;

int main()
{
    int t, n;
    string s;
    cin >> t;
    while (t--)
    {
        cin >> n >> s;
        int ct = 0, cm = 0;
        bool ok = 1;
        for (int i = 0; i < n; i++)
        {
            if (s[i] == 'T')
                ct++;
            if (s[i] == 'M')
                cm++;
            if (cm > ct || ct - cm > n / 3)
            {
                //cout<<"NO"<<endl;
                ok = 0;
                break;
            }
        }

        if (ok && cm * 2 == ct)
            cout << "YES" << endl;
        else
            cout << "NO" << endl;
    }
}
