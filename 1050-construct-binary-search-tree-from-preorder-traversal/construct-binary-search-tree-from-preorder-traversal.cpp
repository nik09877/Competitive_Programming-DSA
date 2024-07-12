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
    TreeNode* go(int l,int r,vector<int>& preorder){
        if(l>r)
            return NULL;
        if(l==r)
            return new TreeNode(preorder[l]);
        
        TreeNode* root = new TreeNode(preorder[l]);
        int mid = -1;
        for(int i = l+1;i<=r;i++)
        {
            if(preorder[i]<=preorder[l]){
                mid = i;
                continue;
            }
            break;
        }
        if(mid == -1){
            root->left = NULL;
            root->right = go(l+1,r,preorder);
        }
        else{
            root->left = go(l+1,mid,preorder);
            root->right = go(mid+1,r,preorder);
        }
        return root;
    }
    TreeNode* bstFromPreorder(vector<int>& preorder) {
        int n= preorder.size();
        return go(0,n-1,preorder);
    }
};