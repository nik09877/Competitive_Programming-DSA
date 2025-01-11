class Solution
{
    bool good(int m, vector<int> &a, int th)
    {
        for (auto x: a)
        {
            th -= (x + m - 1) / m;
        }
        return th >= 0;
    }
    public:
        int smallestDivisor(vector<int> &nums, int threshold)
        {
            int ans = -1, l = 1, r = *max_element(nums.begin(), nums.end());
            while (l <= r)
            {
                int m = (l + r) >> 1;
                if (good(m, nums, threshold))
                    ans = m, r = m - 1;
                else
                    l = m + 1;
            }
            return ans;
        }
};