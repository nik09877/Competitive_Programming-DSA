class Solution
{
public:
    int dx[4] = {0, 1, 0, -1};
    int dy[4] = {1, 0, -1, 0};

    int getMax(vector<vector<int>> &a)
    {
        int mx = -1;
        for (int i = 0; i < a.size(); i++)
            for (int j = 0; j < a[0].size(); j++)
                mx = max(mx, a[i][j]);
        return mx;
    }
    bool isValid(int &x, int &y, int &sea_lvl, vector<vector<bool>> &vis, vector<vector<int>> &a, int &n, int &m)
    {
        if (x < 0 or x >= n or y < 0 or y >= m)
            return false;
        if (vis[x][y])
            return false;
        if (a[x][y] > sea_lvl)
            return false;

        return true;
    }
    void dfs(int i, int j, int &sea_lvl, vector<vector<bool>> &vis, vector<vector<int>> &a, int &n, int &m)
    {
        vis[i][j] = true;
        for (int k = 0; k < 4; k++)
        {

            int new_i = i + dx[k];
            int new_j = j + dy[k];
            if (isValid(new_i, new_j, sea_lvl, vis, a, n, m))
                dfs(new_i, new_j, sea_lvl, vis, a, n, m);
        }
        return;
    }
    bool good(int sea_lvl, vector<vector<int>> &a)
    {
        int n = a.size(), m = a[0].size();
        vector<vector<bool>> vis(n, vector<bool>(m, false));
        dfs(0, 0, sea_lvl, vis, a, n, m);
        return vis[n - 1][m - 1] == true;
    }
    int swimInWater(vector<vector<int>> &a)
    {
        int l = a[0][0], r = getMax(a);
        int ans = -1;
        while (l <= r)
        {
            int m = (l + r) / 2;
            if (good(m, a))
            {
                ans = m;
                r = m - 1;
            }
            else
                l = m + 1;
        }
        return ans;
    }
};