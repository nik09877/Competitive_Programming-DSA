class Solution
{
    bool good(int W,vector<int>& a,int days){
        int sum = 0;
        for(auto x:a){
            if(x>W)
                return false;
            sum+=x;
            if(sum>W)
                sum = x, days--;
        }
        days--;
        return days>=0;
    }
    public:
        int shipWithinDays(vector<int> &weights, int days)
        {

            int l = 0, r = 10000000, ans = -1;
            while (l <= r)
            {
                int m = (l + r) >> 1;
                if (good(m, weights, days))
                    ans = m, r = m - 1;
                else
                    l = m + 1;
            }
            return ans;
        }
};