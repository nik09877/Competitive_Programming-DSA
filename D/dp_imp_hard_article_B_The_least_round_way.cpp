#include <bits/stdc++.h>
#define REP(i, n) for (int i = 1; i <= n; i++)
#define mod 1000000007
#define pb push_back
#define ff first
#define ss second
#define ii pair<int, int>
#define vi vector<int>
#define vii vector<ii>
#define lli long long int
#define INF 1000000000
#define endl '\n'
const double PI = 3.141592653589793238460;
typedef std::complex<double> Complex;
typedef std::valarray<Complex> CArray;

using namespace std;
int dp[1010][1010][2];
char path[1010][1010][2];
int n;

void printPath(int idx, int n)
{
    int x = 1;
    int y = 1;

    while (1)
    {
        if (x == n && y == n)
            break;

        if (x == n)
        {
            while (y < n)
                cout << "R", y++;
        }
        else if (y == n)
        {
            while (x < n)
                cout << "D", x++;
        }
        else
        {
            char ch = path[x][y][idx];
            cout << ch;

            if (ch == 'R')
            {
                y++;
            }
            else
            {
                x++;
            }
        }
    }
}

int getCnt(int num, int div)
{
    int cnt = 0;
    while (num > 0 && (num % div == 0))
        cnt++, num /= div;

    return cnt;
}
int main()
{
    int num;
    bool hasZero = false;
    ii pathToZero;

    cin >> n;
    REP(i, n)
    REP(j, n)
    {
        cin >> num;
        int x = getCnt(num, 2);
        int y = getCnt(num, 5);

        if (!num)
        {
            hasZero = true, pathToZero = {i, j};
            dp[i][j][0] = 1;
            dp[i][j][1] = 1;
        }
        else
        {
            dp[i][j][0] = x;
            dp[i][j][1] = y;
        }
    }

    for (int i = 1; i <= n; i++)
        dp[i][n + 1][0] = dp[n + 1][i][0] = dp[i][n + 1][1] = dp[n + 1][i][1] = INF;
    dp[n][n + 1][0] = dp[n + 1][n][0] = dp[n][n + 1][1] = dp[n + 1][n][1] = 0;

    for (int i = n; i >= 1; i--)
    {
        for (int j = n; j >= 1; j--)
        {
            // minimize 2
            if (dp[i][j + 1][0] < dp[i + 1][j][0])
            {
                dp[i][j][0] += dp[i][j + 1][0];
                path[i][j][0] = 'R';
            }
            else
            {
                dp[i][j][0] += dp[i + 1][j][0];
                path[i][j][0] = 'D';
            }

            // minimize 5
            if (dp[i][j + 1][1] < dp[i + 1][j][1])
            {
                dp[i][j][1] += dp[i][j + 1][1];
                path[i][j][1] = 'R';
            }
            else
            {
                dp[i][j][1] += dp[i + 1][j][1];
                path[i][j][1] = 'D';
            }
        }
    }

    if (hasZero && (min(dp[1][1][0], dp[1][1][1]) >= 1))
    {
        int x = pathToZero.ff;
        int y = pathToZero.ss;

        cout << 1 << endl;
        for (int i = 1; i < x; i++)
            cout << "D";

        for (int i = 1; i < y; i++)
            cout << "R";

        for (int i = x; i < n; i++)
            cout << "D";

        for (int i = y; i < n; i++)
            cout << "R";
    }
    else
    {
        int x = dp[1][1][0];
        int y = dp[1][1][1];
        cout << min(x, y) << endl;

        if (x <= y)
        {
            printPath(0, n);
        }
        else
        {
            printPath(1, n);
        }
    }
}
