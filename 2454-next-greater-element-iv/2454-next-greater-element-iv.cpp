class Solution {
public:
    vector<int> seg;
    void build(int l, int r, int x, vector<int> &nums) {
        if(l == r) {
            if(l < nums.size()) {
                seg[x] = nums[l];
            }
            return;
        }

        int mid = (l + r) / 2;
        build(l, mid, 2 * x + 1, nums);
        build(mid + 1, r, 2 * x + 2, nums);

        seg[x] = max(seg[2 * x + 1], seg[2 * x + 2]); //Segment tree for max operation
    }
    int query(int k, int l, int x, int lx, int rx) {
        if(seg[x] <= k or rx < l) return -1; 
		// if the maximum in the range is less than or equal to nums[i] or the range less than i return -1
		
        if(lx == rx) return lx;

        int mid = (lx + rx) / 2;

        int res = query(k, l, 2 * x + 1, lx, mid);
		//first search in the left subtree
		
        if(res == -1) // if not present search in the right subtree
            res = query(k, l, 2 * x + 2, mid + 1, rx);
			
        return res;
    }
    vector<int> secondGreaterElement(vector<int>& nums) {
        int n = nums.size();
        int x = 1;
        
        while(x <= n) x *= 2;
        seg.resize(2 * x, 0);
        build(0, x - 1, 0, nums);
        
        vector<int> res(n, -1);
        
        for(int i = 0; i < n; ++i) {
            int first = query(nums[i], i + 1, 0, 0, x - 1); //first index k such that nums[i] < nums[k]
            if(first != -1) {
                int second = query(nums[i], first + 1, 0, 0, x - 1); //second index j such that nums[i] < nums[j]
                if(second != -1) res[i] = nums[second];
            }
        }
        return res;
    }
};