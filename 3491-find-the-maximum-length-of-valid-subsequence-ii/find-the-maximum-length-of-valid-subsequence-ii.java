class Solution {
    public int maximumLength(int[] nums, int k) {
        int dp[][] = new int[k][k];
        int ans = 0;
        for(int i=0;i<nums.length;i++){
            int current = nums[i] % k;

            //possible remainders
            for(int j=0;j<k;j++){
                //j as previous remainder
                dp[current][j] = Math.max(dp[current][j] , dp[j][current] + 1);
                ans = Math.max(ans , dp[current][j]);
            }
        }
       return ans;
    }
}