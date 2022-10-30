/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    //QUERIES ON TREE
    vector<int>euler_tour; // node_id
    int depth[100005]; // depth_of_node_from_root or node_val or path_sum
    int subtree_size[100005];
    
    vector<int>st;
    
    void dfs(TreeNode* node,int d=0)
    {
        euler_tour.push_back(node->val);
        depth[node->val] = d;
        subtree_size[node->val] = 1;
        if(node->left)
        {
            dfs(node->left,d+1);
            subtree_size[node->val]+=subtree_size[node->left->val];
        }
        if(node->right)
        {
            dfs(node->right,d+1);
            subtree_size[node->val]+=subtree_size[node->right->val];
        }
    }
    
    void update(int i,int l,int r,int idx,int val){
        if(l==r){
            st[i] = val;
            return;
        }
        int m = (l+r)/2;
        if(idx<=m)
            update(2*i,l,m,idx,val);
        else
            update(2*i+1,m+1,r,idx,val);
        st[i] = max(st[2*i],st[2*i+1]);
        return;
    }
    int query(int i,int l,int r,int qs,int qe){
        if(qs>r or qe<l)
            return -1;
        if(qs<=l and r<=qe)
            return st[i];
        int m = (l+r)/2;
        int left = query(2*i,l,m,qs,qe);
        int right = query(2*i+1,m+1,r,qs,qe);
        return max(left,right);
    }
    vector<int> treeQueries(TreeNode* root, vector<int>& queries) {
        dfs(root);
        int n = euler_tour.size();
        
        map<int,int>node_id;//pos in segtree
        
        for(int i=1;i<=n;i++)
            node_id[euler_tour[i-1]] = i;
        
        st.assign(4*n,0);
        for(auto node:euler_tour){
            update(1,1,n,node_id[node],depth[node]);
        }
        
        vector<int>ans;
        for(auto node:queries){
            int mx1 = query(1,1,n,1,node_id[node]-1);
            int mx2 = query(1,1,n,node_id[node]+subtree_size[node],n);
            int mx = max(mx1,mx2);
            ans.push_back(mx);
        }
        return ans;
    }
};