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
#define endl '\n'
using namespace std;
char cell[501][501];
int res[501][501], n, m, k, rem = 0;
int dx[] = {-1, 0, 1, 0};
int dy[] = {0, 1, 0, -1};
int vis[501][501];

bool isValid(int x, int y)
{
    if (x < 1 || y < 1 || x > n || y > m)
        return false;

    if (vis[x][y] > 0 || cell[x][y] == '#')
        return false;
    return true;
}

void dfs(int x, int y)
{
    if (rem == k)
        return;
    vis[x][y] = rem, rem--;

    for (int i = 0; i < 4; i++)
        if (isValid(x + dx[i], y + dy[i]))
            dfs(x + dx[i], y + dy[i]);
}

int main()
{
    cin >> n >> m >> k;
    REP(i, n)
    {
        REP(j, m)
        {
            cin >> cell[i][j];
            if (cell[i][j] == '.')
                rem++;
        }
    }

    REP(i, n)
    REP(j, m) if (cell[i][j] == '.')
    {
        dfs(i, j);
        break;
    }

    REP(i, n)
    {
        REP(j, m)
        {
            if (cell[i][j] == '#')
                cout << "#";

            else if (vis[i][j] > 0)
                cout << ".";
            else
                cout << "X";
        }
        cout << endl;
    }
}
