#include <bits/stdc++.h>
using namespace std;

#define INF 1234567890
#define ll long long

int T;
int N;
int A[202], dp[202][404];

// Sort the dishes in the non-decreasing order of their optimal time. I claim that there is an optimal answer such that the times T for each dish go in the increasing order. That's not too hard to prove (something along the lines of if there are two dishes i and j such that ti<tj and Ti>Tj, then |ti−Ti|+|tj−Tj| is always greater than |ti−Tj|+|tj−Ti|).

// So we can use dynamic programming to solve the task. Let dp[i][T] be the minimum total unpleasant value if i dishes are processed and the current minute is T. For the transitions you can either put out the current dish i at the current minute T or wait one more minute. Notice that you'll never need more time than 2n minutes (the actual constraint is even smaller, just consider the case with all dishes times equal to n).

// So that dp works in O(n^2).
int main()
{
    scanf("%d", &T);
    while (T--)
    {
        scanf("%d", &N);
        for (int i = 1; i <= N; i++)
            scanf("%d", &A[i]);
        sort(A + 1, A + N + 1);
        for (int i = 1; i <= N; i++)
        {
            dp[i][0] = INF;
            for (int j = 1; j <= N + N; j++)
            {
                dp[i][j] = min(dp[i - 1][j - 1] + abs(A[i] - j), dp[i][j - 1]);
            }
        }
        printf("%d\n", dp[N][N + N]);
    }
    return 0;
}