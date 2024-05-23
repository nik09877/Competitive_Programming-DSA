class Solution {
public:
    int findMaxConsecutiveOnes(vector<int>& nums) {
        int mxLen = 0, len = 0;
        for(auto x:nums){
            if(x==0){
                mxLen = max(mxLen,len);
                len = 0;
                continue;
            }
            len++;
        }
        mxLen = max(mxLen,len);
        return mxLen;
    }
};