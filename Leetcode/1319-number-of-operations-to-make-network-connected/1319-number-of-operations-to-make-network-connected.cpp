class Solution {
public:
    vector<int>g[100005];
    bool vis[100005];
    
    void dfs(int node){
        vis[node] = true;
        for(auto child:g[node]){
            if(vis[child])
                continue;
            dfs(child);
        }
    }
    int makeConnected(int n, vector<vector<int>>& edges) {
        for(int i=0;i<n;i++)
            g[i].clear(),vis[i]=false;
        for(auto e:edges){
            g[e[0]].push_back(e[1]);
            g[e[1]].push_back(e[0]);
        }
        int cc_cnt=0;
        for(int i=0;i<n;i++){
            if(vis[i]==false)
            {
                cc_cnt++;
                dfs(i);
            }
        }
        if(edges.size() < (n-1))
            return -1;
        return cc_cnt-1;
    }
};