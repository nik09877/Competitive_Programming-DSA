class Solution
{
    bool good(int x, vector<int> &a, int buckets_need, int k)
    {
        int cnt = 0;
        int buckets_have = 0;
        for (auto v: a)
        {
            if (v <= x)
                cnt++;
            else
            {
                buckets_have += cnt / k;
                cnt = 0;
            }
        }
        buckets_have += cnt / k;
        return buckets_have >= buckets_need;
    }
    public:
        int minDays(vector<int> &bloomDay, int m, int k)
        {
            int ans = -1, l = 1, r = *max_element(bloomDay.begin(), bloomDay.end());

            while (l <= r)
            {
                int mid = (l + r) >> 1;
                if (good(mid, bloomDay, m, k))
                    ans = mid, r = mid - 1;
                else
                    l = mid + 1;
            }
            return ans;
        }
};