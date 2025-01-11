package Leetcode;
/*
 * @lc app=leetcode id=1786 lang=java
 *
 * [1786] Number of Restricted Paths From First to Last Node
 */

// @lc code=start
import java.util.*;

class Solution {
    static int mod = 1000000007;

    int[] calcShortestDist(List<int[]>[] g, int n) {
        int[] dist = new int[n + 1];
        Arrays.fill(dist, Integer.MAX_VALUE);
        PriorityQueue<int[]> pq = new PriorityQueue<>((a, b) -> a[0] - b[0]);
        pq.offer(new int[] { 0, n });
        while (!pq.isEmpty()) {
            int[] nodeCost = pq.poll();
            int cost = nodeCost[0];
            int node = nodeCost[1];
            if (cost >= dist[node])
                continue;
            dist[node] = cost;
            for (int[] edge : g[node]) {
                int child = edge[0];
                int wt = edge[1];
                if (cost + wt < dist[child]) {
                    pq.offer(new int[] { cost + wt, child });
                }
            }
        }
        return dist;
    }

    void go(int node, int[] dp, int[] dist, int n, List<int[]>[] g) {
        if (dp[node] != -1)
            return;
        dp[node] = 0;
        if (node == n) {
            dp[node] = 1;
            return;
        }
        for (int[] edge : g[node]) {
            int child = edge[0];
            if (dist[node] <= dist[child])
                continue;
            go(child, dp, dist, n, g);
            dp[node] += dp[child];
            dp[node] %= mod;
        }
    }

    public int countRestrictedPaths(int n, int[][] edges) {
        @SuppressWarnings("unchecked")
        List<int[]>[] g = new ArrayList[n + 1];
        for (int i = 1; i <= n; i++)
            g[i] = new ArrayList<>();
        for (int[] edge : edges) {
            int a = edge[0];
            int b = edge[1];
            int wt = edge[2];
            g[a].add(new int[] { b, wt });
            g[b].add(new int[] { a, wt });
        }
        int[] dist = calcShortestDist(g, n);

        int[] numWays = new int[n + 1];
        Arrays.fill(numWays, -1);
        go(1, numWays, dist, n, g);
        return numWays[1];
    }
}
// @lc code=end
