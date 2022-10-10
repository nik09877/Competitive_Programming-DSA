class Solution {
public:
    vector<int> spiralOrder(vector<vector<int>>& a) {
        int n = a.size() , m = a[0].size();
        int pointer_to_fst_row = 0,pointer_to_lst_row=n-1;
        int pointer_to_fst_col = 0,pointer_to_lst_col=m-1;
        vector<int>ans;
        
        while(pointer_to_fst_row<=pointer_to_lst_row
             and
             pointer_to_fst_col<=pointer_to_lst_col){
            
            for(int dir=0;dir<4;dir++){
                
                if(dir==0){
                    // GO RIGHT
                    for(int i=pointer_to_fst_col;i<=pointer_to_lst_col;i++)
                        ans.push_back(a[pointer_to_fst_row][i]);
                    pointer_to_fst_row++;
                }
                

                if(dir==1){
                    // GO DOWN
                    for(int i=pointer_to_fst_row;i<=pointer_to_lst_row;i++)
                        ans.push_back(a[i][pointer_to_lst_col]);
                    pointer_to_lst_col--;
                }
                

                if(dir==2){
                    // GO lEFT
                    for(int i=pointer_to_lst_col;i>=pointer_to_fst_col;i--)
                        ans.push_back(a[pointer_to_lst_row][i]);
                    pointer_to_lst_row--;
                }
                

                if(dir==3){
                    // GO UP
                    for(int i=pointer_to_lst_row;i>=pointer_to_fst_row;i--)
                        ans.push_back(a[i][pointer_to_fst_col]);
                    pointer_to_fst_col++;
                }
                
            }

        }
        while(ans.size()>n*m)
            ans.pop_back();
        return ans;
    }
};