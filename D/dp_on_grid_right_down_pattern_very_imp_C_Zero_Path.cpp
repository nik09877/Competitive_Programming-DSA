#include <bits/stdc++.h>
using namespace std;

#define N 1010

int grid[N][N], mn[N][N], mx[N][N];

/*

mn[i][j] denotes minimum sum ending at [i,j]
mx[i][j] denotes maximum sum ending at [i,j]

mn[n][m] and mx[n][m] will always be even , try to prove otherwise

let p1-> path such that we get min sum
let p2-> path such that we get max sum
changing path from p1 to p2 makes sum diff -2 or 0 or 2

so if 0 occurs in the range of [mn,mx] then somewhere along the way of changing path from p1 to p2
we will get sum as 0

*/
int main()
{
    int num_tests;
    cin >> num_tests;

    for (int test = 0; test < num_tests; ++test)
    {
        int n, m;
        cin >> n >> m;

        for (int i = 0; i < n; ++i)
            for (int j = 0; j < m; ++j)
                cin >> grid[i][j];

        mn[0][0] = mx[0][0] = grid[0][0];

        for (int i = 1; i < n; ++i)
            mx[i][0] = mn[i][0] = mx[i - 1][0] + grid[i][0];

        for (int j = 1; j < m; ++j)
            mx[0][j] = mn[0][j] = mx[0][j - 1] + grid[0][j];

        for (int i = 1; i < n; ++i)
            for (int j = 1; j < m; ++j)
            {
                mx[i][j] = max(mx[i - 1][j], mx[i][j - 1]) + grid[i][j];
                mn[i][j] = min(mn[i - 1][j], mn[i][j - 1]) + grid[i][j];
            }

        if (mx[n - 1][m - 1] % 2 || mn[n - 1][m - 1] > 0 || mx[n - 1][m - 1] < 0)
            cout << "NO\n";
        else
            cout << "YES\n";
    }
}