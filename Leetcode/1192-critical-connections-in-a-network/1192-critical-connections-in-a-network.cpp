class Solution
{
    public:

        int dp[100005], lvl[100005];
    bool vis[100005];
    vector<int> g[100005];

    vector<vector < int>> bridges;

    void dfs(int node, int level, int par = -1)
    {
        dp[node] = lvl[node] = level;
        vis[node] = true;
        for (auto child: g[node])
        {
            if (child == par) continue;
            else if (vis[child] == true)
            {
                dp[node] = min(dp[node], lvl[child]);
            }
            else
            {
                dfs(child, level + 1, node);
                dp[node] = min(dp[node], dp[child]);
                if (dp[child] > lvl[node])
                {
                    bridges.push_back({ node,
                        child });
                }
            }
        }
    }
    vector<vector < int>> criticalConnections(int n, vector<vector < int>> &connections)
    {
        for (int i = 0; i < n; i++)
            dp[i] = lvl[i] = INT_MAX, vis[i] = false;
        bridges.clear();
        for (auto x: connections)
        {
            g[x[0]].push_back(x[1]);
            g[x[1]].push_back(x[0]);
        }
        dfs(0, 0);
        return bridges;
    }
};