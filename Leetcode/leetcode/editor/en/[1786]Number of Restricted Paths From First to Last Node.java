//import java.util.*;
//There is an undirected weighted connected graph. You are given a positive 
//integer n which denotes that the graph has n nodes labeled from 1 to n, and an 
//array edges where each edges[i] = [ui, vi, weighti] denotes that there is an edge 
//between nodes ui and vi with weight equal to weighti. 
//
// A path from node start to node end is a sequence of nodes [z0, z1, z2, ..., 
//zk] such that z0 = start and zk = end and there is an edge between zi and zi+1 
//where 0 <= i <= k-1. 
//
// The distance of a path is the sum of the weights on the edges of the path. 
//Let distanceToLastNode(x) denote the shortest distance of a path between node n 
//and node x. A restricted path is a path that also satisfies that 
//distanceToLastNode(zi) > distanceToLastNode(zi+1) where 0 <= i <= k-1. 
//
// Return the number of restricted paths from node 1 to node n. Since that 
//number may be too large, return it modulo 10⁹ + 7. 
//
// 
// Example 1: 
// 
// 
//Input: n = 5, edges = [[1,2,3],[1,3,3],[2,3,1],[1,4,2],[5,2,2],[3,5,1],[5,4,10
//]]
//Output: 3
//Explanation: Each circle contains the node number in black and its 
//distanceToLastNode value in blue. The three restricted paths are:
//1) 1 --> 2 --> 5
//2) 1 --> 2 --> 3 --> 5
//3) 1 --> 3 --> 5
// 
//
// Example 2: 
// 
// 
//Input: n = 7, edges = [[1,3,1],[4,1,2],[7,3,4],[2,5,3],[5,6,1],[6,7,2],[7,5,3]
//,[2,6,4]]
//Output: 1
//Explanation: Each circle contains the node number in black and its 
//distanceToLastNode value in blue. The only restricted path is 1 --> 3 --> 7.
// 
//
// 
// Constraints: 
//
// 
// 1 <= n <= 2 * 10⁴ 
// n - 1 <= edges.length <= 4 * 10⁴ 
// edges[i].length == 3 
// 1 <= ui, vi <= n 
// ui != vi 
// 1 <= weighti <= 10⁵ 
// There is at most one edge between any two nodes. 
// There is at least one path between any two nodes. 
// 
//
// Related Topics Dynamic Programming Graph Topological Sort Heap (Priority 
//Queue) Shortest Path 👍 1124 👎 216

//3804246
//leetcode submit region begin(Prohibit modification and deletion)
class Solution {
    int[] calcShortestDist(List<int[]>[] g, int n){
        int[] dist = new int[n+1];
        Arrays.fill(dist,Integer.MAX_VALUE);
        PriorityQueue<int[]>pq =new PriorityQueue<>((a,b)-> a[0] - b[0]);
        pq.offer(new int[]{0,n});
        while(!pq.isEmpty()){
            int[] nodeCost = pq.poll();
            int cost = nodeCost[0];
            int node = nodeCost[1];
            if(cost >= dist[node])
                continue;
            dist[node] = cost;
            for(int[] edge:g[node]){
                int child = edge[0];
                int wt = edge[1];
                if(cost + wt < dist[child]){
                    pq.offer(new int[]{cost+wt,child});
                }
            }
        }
        return dist;
    }
    void go(int node,int[] dp,int[] dist,int n,List<int[]>[]g){
        if(dp[node]!=-1)
            return;
        dp[node] = 0;
        if(node == n){
            dp[node] = 1;
            return;
        }
        for(int[] edge:g[node]){
            int child = edge[0];
            int wt = edge[1];
            if(dist[node] <= dist[child])
                continue;
            go(child,dp,dist,n,g);
            dp[node]+=dp[child];
        }
    }
    public int countRestrictedPaths(int n, int[][] edges) {
        List<int[]>[] g = new ArrayList[n+1];
        for(int i=1;i<=n;i++)
            g[i] = new ArrayList<>();
        for(int[] edge:edges){
            int a = edge[0];
            int b = edge[1];
            int wt = edge[2];
            g[a].add(new int[]{b,wt});
            g[b].add(new int[]{a,wt});
        }
        int[] dist = calcShortestDist(g,n);

        int[] numWays = new int[n+1];
        Arrays.fill(numWays,-1);
        go(1,numWays,dist,n,g);
        return numWays[1];
    }
}
//leetcode submit region end(Prohibit modification and deletion)
