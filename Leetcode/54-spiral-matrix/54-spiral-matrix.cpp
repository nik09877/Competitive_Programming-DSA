class Solution {
public:
    vector<int> spiralOrder(vector<vector<int>>& a) {
        int n = a.size() , m = a[0].size();
        int pointer_to_fst_row = 0,pointer_to_lst_row=n-1;
        int pointer_to_fst_col = 0,pointer_to_lst_col=m-1;
        vector<int>ans;
        
        /*
        In each outer loop traversal print the elements of a square in a clockwise manner.

        Print the top row, i.e. Print the elements of the top row from column index left to right and increase the count of the top so that it will move to the next row.

        Print the right column, i.e. Print the rightmost column from row index top to bottom and decrease the count of right.

        Print the bottom row, i.e. if top <= bottom, then print the elements of a bottom row from column right to left and decrease the count of bottom

        Print the left column, i.e. if left <= right, then print the elements of the left column from the bottom row to the top row and increase the count of left.

        Run a loop until all the squares of loops are printed.
        */
        while(pointer_to_fst_row<=pointer_to_lst_row
             and
             pointer_to_fst_col<=pointer_to_lst_col){
            
            // GO RIGHT
            for(int i=pointer_to_fst_col;i<=pointer_to_lst_col;i++)
                ans.push_back(a[pointer_to_fst_row][i]);
            pointer_to_fst_row++;


            // GO DOWN
            for(int i=pointer_to_fst_row;i<=pointer_to_lst_row;i++)
                ans.push_back(a[i][pointer_to_lst_col]);
            pointer_to_lst_col--;

            if(pointer_to_fst_row<=pointer_to_lst_row)
            {
                // GO lEFT
                for(int i=pointer_to_lst_col;i>=pointer_to_fst_col;i--)
                    ans.push_back(a[pointer_to_lst_row][i]);
                pointer_to_lst_row--;
            }

            if(pointer_to_fst_col<=pointer_to_lst_col)
            {
                // GO UP
                for(int i=pointer_to_lst_row;i>=pointer_to_fst_row;i--)
                    ans.push_back(a[i][pointer_to_fst_col]);
                pointer_to_fst_col++;
            }
        }
        
        return ans;
    }
};