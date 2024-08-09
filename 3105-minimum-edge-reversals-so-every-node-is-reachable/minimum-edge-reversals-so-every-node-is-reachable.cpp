class Solution {
public:
vector<pair<int,int>>g[100005];
int dp[100005];
vector<int>res;

void dfs(int node,int par){
    for(auto c:g[node]){
        auto [child,cost] = c;
        if(child==par)
            continue;
        dfs(child,node);
        dp[node]+=dp[child] + cost;
    }
}

void dfs1(int node,int par){
    for(auto c:g[node]){
        auto [child,cost] = c;
        if(child==par)
            continue;        
        res[child] = (res[node] - dp[child] - cost) + dp[child] + (cost^1);
        dfs1(child,node);
    }    
}
    vector<int> minEdgeReversals(int n, vector<vector<int>>& edges) {
        for(auto e:edges){
            int u = e[0];
            int v = e[1];
            g[u].push_back({v,0});
            g[v].push_back({u,1});
        }
        res.resize(n);
        dfs(0,-1);
        res[0] = dp[0];
        dfs1(0,-1);
        // for(int i=0;i<n;i++)
        // cout<<i<<" -> "<<dp[i]<<endl;

        return res;
    }
};