class Solution
{
    public:
       	//https://leetcode.com/problems/find-a-peak-element-ii/discuss/1276556/JavaPythonC%2B%2B-Clear-Explanation-with-Images-or-M*Log(N)-or-Very-Short-code

        vector<int> findPeakGrid(vector<vector < int>> &a)
        {
            int startCol = 0, endCol = a[0].size() - 1;

           	//Binary search on the column
            while (startCol <= endCol)
            {
                int midCol = (startCol + endCol) >> 1;

               	//find row position of max element of midColumn
                int mxRow = 0;
                for (int row = 0; row < a.size(); row++)
                {
                    mxRow = a[row][midCol] > a[mxRow][midCol] ? row : mxRow;
                }

                int leftIsBig = midCol > startCol and a[mxRow][midCol - 1] > a[mxRow][midCol];
                int rightIsBig = midCol < endCol and a[mxRow][midCol + 1] > a[mxRow][midCol];

                if (!leftIsBig and!rightIsBig)
                    return { mxRow, midCol };
                
                else if (leftIsBig)
                    endCol = midCol - 1;
                
                else
                    startCol = midCol + 1;
            }
            return { -1,-1 };
        }
};