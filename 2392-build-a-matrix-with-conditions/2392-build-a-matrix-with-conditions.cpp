class Solution {
public:
    bool dfs(int node,vector<int>& col,vector<unordered_set<int>>& g){
        col[node] = 1;
        for(auto child:g[node]){
            if(col[child]==0){
                if(dfs(child,col,g))
                    return true;
            }
            else if(col[child]==1)
                return true;
        }
        col[node]=2;
        return false;
    }
    vector<vector<int>> buildMatrix(int k, vector<vector<int>>& rowConditions, vector<vector<int>>& colConditions) {
        unordered_map<int,int>row,col;
        vector<unordered_set<int>>rg(k+1),cg(k+1);
        vector<int>rin(k+1,0),c_in(k+1,0);
        
        for(auto x:rowConditions){
            int a = x[0],b=x[1];
            if(rg[a].count(b)==0){
                rg[a].insert(b);
                rin[b]++;
            }
        }
        for(auto x:colConditions){
            int a = x[0],b=x[1];
            if(cg[a].count(b)==0){
                cg[a].insert(b);
                c_in[b]++;
            }
        }
        
        //check cycle in row and col
        vector<int>rcol(k+1,0),ccol(k+1,0);
        for(int i=1;i<=k;i++){
            if(rcol[i]==0){
                if(dfs(i,rcol,rg))
                    return {};
            }
        }
        for(int i=1;i<=k;i++){
            if(ccol[i]==0){
                if(dfs(i,ccol,cg))
                    return {};
            }
        }
        
        vector<vector<int>>ans(k,vector<int>(k,0));
        queue<int>q;
        
        int row_id=0;
        for(int i=1;i<=k;i++)
            if(rin[i]==0)
                q.push(i);
        
        while(q.size()){
            int node = q.front();
            // cout<<node<<" ";
            q.pop();
            row[node] = row_id++;
            for(auto child:rg[node]){
                rin[child]--;
                if(rin[child]==0)
                    q.push(child);
            }
        }
        // cout<<endl;
        // cout<<rin[3]<<" "<<rin[2];
        // cout<<endl;
        int col_id=0;
        for(int i=1;i<=k;i++)
            if(c_in[i]==0)
                q.push(i);
        while(q.size()){
            int node = q.front();
            // cout<<node<<" ";
            q.pop();
            col[node] = col_id++;
            for(auto child:cg[node]){
                c_in[child]--;
                if(c_in[child]==0)
                    q.push(child);
            }
        }
        
        for(int i=1;i<=k;i++){
            if(row.find(i)==row.end())
                row[i] = row_id++;
            if(col.find(i)==col.end())
                col[i] = col_id++;
        }
        for(int i=1;i<=k;i++){
            ans[row[i]][col[i]] = i;
        }
        return ans;
    }
};