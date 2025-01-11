import java.util.*;

class Solution {
    void dfs(int node, int par, int[] subtree, int[] dp, List<Integer>[] g) {
        subtree[node] = 1;
        for (int child : g[node]) {
            if (child == par)
                continue;
            dfs(child, node, subtree, dp, g);
            subtree[node] += subtree[child];
            dp[node] += dp[child] + subtree[child];
        }
    }

    void dfs1(int node, int par, int[] subtree, int[] dp, int[] ans, List<Integer>[] g) {
        for (int child : g[node]) {
            if (child == par)
                continue;
            ans[child] = dp[child] + (ans[node] - dp[child] - subtree[child]) + (subtree[0] - subtree[child]);
            dfs1(child, node, subtree, dp, ans, g);
        }
    }

    public int[] sumOfDistancesInTree(int n, int[][] edges) {
        int[] subtree = new int[n];
        int[] dp = new int[n];
        @SuppressWarnings("unchecked")
        List<Integer>[] g = new ArrayList[n];
        for (int i = 0; i < n; i++)
            g[i] = new ArrayList<>();
        for (int[] edge : edges) {
            int a = edge[0];
            int b = edge[1];
            g[a].add(b);
            g[b].add(a);
        }
        dfs(0, -1, subtree, dp, g);
        int[] ans = new int[n];
        ans[0] = dp[0];
        dfs1(0, -1, subtree, dp, ans, g);
        return ans;
    }
}