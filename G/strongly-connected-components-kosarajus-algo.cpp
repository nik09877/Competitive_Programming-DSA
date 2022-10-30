//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends


class Solution
{
	public:
	
	vector<int>rev_g[5005],g[5005],order;
	bool vis[5005];
	
	void dfs2(int node){
	    vis[node]=true;
	    for(auto child:rev_g[node]){
	        if(vis[child])
	            continue;
	        dfs2(child);
	    }
	    return;
	}
	void dfs(int node){
	    vis[node]=true;
	    for(auto child:g[node]){
	        if(vis[child])
	            continue;
	        dfs(child);
	    }
	    order.push_back(node);
	}
	//Function to find number of strongly connected components in the graph.
    int kosaraju(int n, vector<int> adj[])
    {
        for(int i=0;i<n;i++)
            g[i].clear(),rev_g[i].clear(),vis[i]=false;
        for(int i=0;i<n;i++){
            for(auto x:adj[i])
                g[i].push_back(x),rev_g[x].push_back(i);
        }
        
        order.clear();
        for(int i=0;i<n;i++){
            if(vis[i]==false)
                dfs(i);
        }
        reverse(order.begin(),order.end());
        memset(vis,0,sizeof(vis));
        
        int cnt=0;
        for(auto node:order){
            if(!vis[node]){
                cnt++;
                dfs2(node);
            }
        }
        return cnt;
    }
};

//{ Driver Code Starts.


int main()
{
    
    int t;
    cin >> t;
    while(t--)
    {
    	int V, E;
    	cin >> V >> E;

    	vector<int> adj[V];

    	for(int i = 0; i < E; i++)
    	{
    		int u, v;
    		cin >> u >> v;
    		adj[u].push_back(v);
    	}

    	Solution obj;
    	cout << obj.kosaraju(V, adj) << "\n";
    }

    return 0;
}


// } Driver Code Ends