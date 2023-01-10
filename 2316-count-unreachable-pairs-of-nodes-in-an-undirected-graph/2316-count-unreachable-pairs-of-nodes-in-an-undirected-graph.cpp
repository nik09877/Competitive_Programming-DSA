class Solution {
public:
    vector<int>g[100005];
    bool vis[100005];
    int cc_size;
    void dfs(int node){
        vis[node]=true;
        cc_size++;
        for(auto child:g[node]){
            if(vis[child])
                continue;
            dfs(child);
        }
    }
    
    long long countPairs(int n, vector<vector<int>>& edges) {
        for(int i=0;i<edges.size();i++){
            int a = edges[i][0],b=edges[i][1];
            g[a].push_back(b);
            g[b].push_back(a);
        }
        vector<int>ans;
        for(int i=0;i<n;i++){
            if(vis[i]==0){
                cc_size=0;
                dfs(i);
                ans.push_back(cc_size);
            }
        }
        int sz = ans.size();
        vector<int>pre(sz);
        partial_sum(ans.begin(),ans.end(),pre.begin());
        long long res=0;
        for(int i=0;i<sz-1;i++)
            res+=(ans[i]*1ll*(pre[sz-1]-pre[i]));
        return res;
        
    }
};