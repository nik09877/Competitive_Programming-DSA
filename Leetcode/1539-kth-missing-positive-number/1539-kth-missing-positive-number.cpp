class Solution
{
    public:
        int findKthPositive(vector<int> &a, int k)
        {
            int n = a.size();
            int ans = -1, l = 0, r = n - 1;
            while (l <= r)
            {
                int m = (l + r) >> 1;

                int missing_ele_in_left_side = a[m] - (m + 1);
                if (missing_ele_in_left_side < k)
                    ans = m, l = m + 1;

                else
                    r = m - 1;
            }
            if(ans==-1){
                return k;
            }
            
            int missing_ele_in_left_side = a[ans] - (ans + 1);
            int missing_ele_in_right = k - (missing_ele_in_left_side);
            return a[ans] + missing_ele_in_right;
        }
};