class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        int sortedTillIdx = 0;
        for(int i=1;i<nums.size();i++){
            if(nums[i] == nums[sortedTillIdx])
                continue;
            sortedTillIdx++;
            swap(nums[sortedTillIdx],nums[i]);
        }
        return sortedTillIdx+1;
    }
};