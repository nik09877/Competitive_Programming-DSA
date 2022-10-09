#include <bits/stdc++.h>
int t, n, flg;
char c[60][60];
int main()
{
    scanf("%d", &t);
    while (t--)
    {
        flg = 0;
        scanf("%d", &n);
        for (int i = 0; i < n; i++)
            scanf("%s", c[i]);
        for (int i = 0; i < n - 1; i++)
            for (int j = 0; j < n - 1; j++)
                if (c[i][j] == '1' && c[i + 1][j] == '0' && c[i][j + 1] == '0')
                    flg = 1;
        printf(flg ? "NO\n" : "YES\n");
    }
    return 0;
}