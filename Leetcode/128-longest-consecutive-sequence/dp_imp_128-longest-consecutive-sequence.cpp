class Solution
{
    public:
        int longestConsecutive(vector<int> &a)
        {
            unordered_map<int, int> mp;
            for (auto x: a) mp[x]++;
            int ans = 0;

           	//from an element expand in both directions
            for (auto x: a)
            {
                if (mp[x] == 0)
                    continue;
                int len = 1;
                mp[x] = 0;
                int pre = x - 1;
                int nxt = x + 1;
                while (mp[pre])
                    len++, mp[pre] = 0, pre--;
                while (mp[nxt])
                    len++, mp[nxt] = 0, nxt++;
                ans = max(ans, len);
            }
            return ans;
        }
};