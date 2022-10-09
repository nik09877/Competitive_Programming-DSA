#include <cstdio>
int a[100005], b[100005];
int main()
{
    int T;
    scanf("%d", &T);
    while (T--)
    {
        int n, iq;
        scanf("%d%d", &n, &iq);
        for (int i = 1; i <= n; ++i)
            scanf("%d", &a[i]);
        int sum = 0, nq = 0;
        for (int i = n; i >= 1; --i)
        {
            if (a[i] <= nq)
                b[i] = 1;
            else if (nq < iq)
                ++nq, b[i] = 1;
            else
                b[i] = 0;
        }
        for (int i = 1; i <= n; ++i)
            printf("%d", b[i]);
        puts("");
    }
    return 0;
}