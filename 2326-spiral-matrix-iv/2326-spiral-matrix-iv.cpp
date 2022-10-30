class Solution{
    public:
    vector<vector<int>> spiralMatrix(int m, int n, ListNode* head) {
    int left=0, right= n-1, top=0, bottom= m-1;
    vector<vector<int>> ans(m,vector<int>(n,-1));
    ListNode* ptr= head;
    for(;true;){
        for(int i=left;i<=right and ptr;i++,ptr=ptr->next) ans[top][i]=ptr->val;
        top++;
        if(top>bottom or !ptr) break;
        for(int i=top;i<=bottom and ptr;i++,ptr=ptr->next) ans[i][right]=ptr->val;
        right--;
        if(left>right or !ptr) break;
        for(int i=right;i>=left and ptr;i--,ptr=ptr->next) ans[bottom][i]=ptr->val;
        bottom--;
        if(top>bottom or !ptr) break;
        for(int i=bottom;i>=top and ptr;i--,ptr=ptr->next) ans[i][left]=ptr->val;
        left++;
        if(left>right or !ptr) break;
    }
    return ans;
}
};