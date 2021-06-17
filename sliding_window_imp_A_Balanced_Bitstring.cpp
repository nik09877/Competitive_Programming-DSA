#include <bits/stdc++.h>
using namespace std;

//The char at i,i+k,i+2k ...  will be same ,as each substring of length k will have k-1 common elements with another substring of length k
int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        int n, k;
        cin >> n >> k;
        char str[n + 1];
        cin >> str;
        int flag = 0;
        for (int i = 0; i < k; i++)
        {
            char temp = str[i];
            int x = i + k;
            while (x < n)
            {
                if (temp == '0' && str[x] == '1')
                {
                    flag = 1;
                    break;
                }
                else if (temp == '1' && str[x] == '0')
                {
                    flag = 1;
                    break;
                }
                else if (temp == '?' && str[x] != '?')
                    temp = str[x];
                x += k;
            }
            if (flag == 1)
                break;
            str[i] = temp;
        }
        if (flag == 1)
            cout << "NO\n";
        else
        {
            flag = 0;
            int z = 0, o = 0, q = 0;
            for (int i = 0; i < k; i++)
            {
                if (str[i] == '0')
                    z++;
                else if (str[i] == '1')
                    o++;
                else
                    q++;
            }
            if (z > k / 2 || o > k / 2)
                cout << "NO\n";
            else
                cout << "YES\n";
        }
    }
}