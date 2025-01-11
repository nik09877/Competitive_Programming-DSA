class Solution {
public:
    int dx[4]= {0,1,0,-1};
    int dy[4] = {1,0,-1,0};
    int minimumObstacles(vector<vector<int>>& grid) {
        int n = grid.size(),m=grid[0].size();
        vector<vector<int>>cost(n,vector<int>(m,INT_MAX-1));
        if(grid[0][0]==1)
            cost[0][0]=1;
        else 
            cost[0][0]=0;
        priority_queue<pair<int,pair<int,int>>,vector<pair<int,pair<int,int>>>,greater<pair<int,pair<int,int>>>>pq;
        pq.push({cost[0][0],{0,0}});
        while(!pq.empty()){
            int cur_cost = pq.top().first;
            int x = pq.top().second.first;
            int y = pq.top().second.second;
            pq.pop();
            if(x==n-1 and y==m-1)
                break;
            
            for(int k=0;k<4;k++){
                int new_x = x+dx[k];
                int new_y = y+dy[k];
                if(new_x>=0 and new_x<n and new_y>=0 and new_y<m and cur_cost+grid[new_x][new_y] < cost[new_x][new_y]){
                    cost[new_x][new_y] = cur_cost+grid[new_x][new_y];
                    pq.push({cost[new_x][new_y],{new_x,new_y}});
                }
            }
        }
        return cost[n-1][m-1];
    }
};