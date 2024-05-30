class Solution {
public:

    vector<int> minimumTime(int n, vector<vector<int>>& edges, vector<int>& disappear) {
        //create minimumTime arr
        vector<int>minTimeToReach(n,-1);
        minTimeToReach[0] = 0;

        //create adj list
        vector<vector<pair<int,int>>>graph(n);
        for(auto edge:edges){
            int nodeA = edge[0];
            int nodeB = edge[1];
            int length = edge[2];
            graph[nodeA].push_back({nodeB,length});
            graph[nodeB].push_back({nodeA,length});
        }

        //min pq
        //node {time to reach cur node, cur node}
        priority_queue<vector<int>,vector<vector<int>>,greater<vector<int>>>priority_q;
        vector<int>time_to_reach(n,INT_MAX);
        time_to_reach[0] = 0;
        
        priority_q.push({0,0});

        while(priority_q.size()>0){
            vector<int> state = priority_q.top();
            priority_q.pop();
            int cur_node = state[1];
            int cur_time_to_reach_node = state[0];

            if(cur_time_to_reach_node > time_to_reach[cur_node] || cur_time_to_reach_node > disappear[cur_node])
                continue;
            
            for(auto edg:graph[cur_node]){
                int child_node = edg.first;
                int length_to_reach_child = edg.second;
                int time_to_reach_child = cur_time_to_reach_node + length_to_reach_child;
                if(time_to_reach_child < time_to_reach[child_node] and time_to_reach_child < disappear[child_node]){
                    time_to_reach[child_node] = time_to_reach_child;
                    priority_q.push({time_to_reach_child,child_node});
                }
            }
        }

        for(int i=1;i<n;i++){
            if(time_to_reach[i]==INT_MAX)
                continue;
            minTimeToReach[i] = time_to_reach[i];
        }
        return minTimeToReach;
    }
};