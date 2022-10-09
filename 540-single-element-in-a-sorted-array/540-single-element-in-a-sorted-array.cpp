class Solution
{
    public:
        int singleNonDuplicate(vector<int> &a)
        {
            int l = 0, r = a.size() - 1;
            while (l <= r)
            {
                int m = (l + r) >> 1;
                if (m > 0 and a[m] == a[m - 1])
                {
                    int left_len = m + 1;
                    if (left_len % 2 == 0)
                        l = m + 1;
                    else
                        r = m - 1;
                }
                else if (m < a.size() - 1 and a[m] == a[m + 1])
                {
                    int right_len = a.size() - m;
                    if (right_len % 2 == 0)
                        r = m - 1;
                    else
                        l = m + 1;
                }
                else
                    return a[m];
            }
            return -1;
        }
};