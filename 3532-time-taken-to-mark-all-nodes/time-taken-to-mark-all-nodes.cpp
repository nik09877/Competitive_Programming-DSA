class Solution {
    void buildFar(int curr, vector<vector<int>> &adj, vector<int> &far1, vector<int> &far2) {
        int maxChild1 = 0, maxChild2 = 0;
        // Iterate through each child (branch), and find the two farthest children.
        for(int child: adj[curr]) {
            if(child <= curr) continue;

            buildFar(child, adj, far1, far2);
            int dist = ((child & 1) ? 1 : 2) + far1[child];
            if(dist >= maxChild1) {
                maxChild2 = maxChild1;
                maxChild1 = dist;
            } else if(dist > maxChild2) {
                maxChild2 = dist;
            }
        }

        far1[curr] = maxChild1, far2[curr] = maxChild2;
    }

    void calcOthers(int curr, int parentDist, vector<vector<int>> &adj, const vector<int> &far1, const vector<int> &far2, vector<int> &ans) {
        // parentDist: the farthest distance when node[parent] is the root
        
        ans[curr] = max(parentDist, far1[curr]);

        for(int child: adj[curr]) {
            if(child < curr) continue;

            int toParent = (curr & 1) ? 1 : 2;
            int tochild = (child & 1) ? 1 : 2;
            // For this child, exclude itself or it is not correct
            // (If the branch containing this child is the farthest for node curr, we should use the second farthest) 
            int farthestChildExceptThisChild = (far1[curr] == (tochild + far1[child])) ? far2[curr] : far1[curr]; 

            calcOthers(child, toParent + max(parentDist, farthestChildExceptThisChild), adj, far1, far2, ans);
        }
    }
public:
    vector<int> timeTaken(vector<vector<int>>& edges) {
        int n = edges.size() + 1;
        vector<vector<int>> adj(n);
        for(auto &edge: edges) {
            adj[edge[0]].push_back(edge[1]);
            adj[edge[1]].push_back(edge[0]);
        }

        // first, use 0 as root and calculate below:
        // far1[i]: the farthest children for the subtree with root i
        // far2[i]: the second farthest children for the subtree with root i
        vector<int> far1(n, 0), far2(n, 0);
        buildFar(0, adj, far1, far2);

        // by far1 and far2, we can use re-rooting to help us find the answer
        vector<int> ans(n, 0);
        calcOthers(0, 0, adj, far1, far2, ans);

        return ans;
    }
};