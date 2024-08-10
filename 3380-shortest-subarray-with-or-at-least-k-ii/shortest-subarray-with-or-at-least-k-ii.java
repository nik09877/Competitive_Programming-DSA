class Solution {
    private int calcORVal(int[] bitCntArr){
        int val = 0;
        for(int i=0;i<32;i++){
            if(bitCntArr[i]>0){
                val+=(1<<i);
            }
        }
        return val;
    }
    private int add(int orVal,int[] arr,int val){
        for(int i=0;i<32;i++){
            if((val&(1<<i))!=0){
                arr[i]++;
            }
        }
        return (orVal|val);
    }
    private int remove(int[] bitCntArr,int val,int orVal){
        for(int i=0;i<32;i++){
            if((val&(1<<i))!=0){
                bitCntArr[i]--;
                if(bitCntArr[i]==0){
                    orVal^=(1<<i);
                }
            }
        }
        return orVal;
    }
    public int minimumSubarrayLength(int[] nums, int k) {
        int minLen = nums.length + 1;
        int n = nums.length;
        int l = 0;
        int orVal = 0;
        int[] bitCntArr = new int[32];
        Arrays.fill(bitCntArr,0);
        for(int r=0;r<n;r++){
            orVal = add(orVal,bitCntArr,nums[r]);
            while(l<=r && orVal>=k){
                minLen = Math.min(minLen,r-l+1);
                orVal = remove(bitCntArr,nums[l],orVal);
                l++;
            }
        }

        return minLen > n ? -1 : minLen;
        
    }
}