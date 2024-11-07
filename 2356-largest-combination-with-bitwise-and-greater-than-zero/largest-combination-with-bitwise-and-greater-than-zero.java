class Solution {
    public int largestCombination(int[] candidates) {
        int[] bitCnt = new int[32];
        for(int x:candidates){
            for(int i=0;i<32;i++){
                if((x&(1<<i))!=0)
                    bitCnt[i]++;
            }
        }
        int ans = 0;
        for(int i=0;i<32;i++)
        {
            ans = Math.max(ans,bitCnt[i]);
        }
        return ans;
    }
}