class Solution
{
    public:
        void moveZeroes(vector<int> &a)
        {
            int n = a.size();
            int i = 0, j = 0;
            while (i < n and j < n)
            {
                while (i < n and a[i])
                    i++;
                if (i == n)
                    break;
                while (j < n and!a[j])
                    j++;
                if (j == n)
                    break;
                if (i < j)
                    swap(a[i], a[j]), i++, j++;
                else
                    j++;
            }
        }
};