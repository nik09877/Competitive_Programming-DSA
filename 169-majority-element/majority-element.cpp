class Solution {
public:
    int majorityElement(vector<int>& nums) {
        int major = -1, majorCnt = 0;
        for(auto x:nums){
            if(majorCnt == 0)
                major = x,majorCnt = 1;
            else if(major == x)
                majorCnt++;
            else majorCnt--;
        }
        return count(nums.begin(),nums.end(),major) > nums.size()/2 ? major : -1;
    }
};