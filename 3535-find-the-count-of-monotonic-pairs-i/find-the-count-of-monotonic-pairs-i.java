class Solution {
    private static final int MOD = (int) 1e9+7;
    public int countOfPairs(int[] nums) {
        /**
        dp[i][j] denotes no of ways to construct pairs 
        such that we have reached ith pos and curSum of 'A' array is j

        if curSumA = j
            => preSumA <= curSumA

        we have curSumB = nums[i] - j
            => preSumB >= curSumB
        we have preSumB = nums[i-1] - preSumA
            => nums[i-1] - preSumA >= curSumB
            
            => nums[i-1] - preSumA >= nums[i] - curSumA
            => preSumA <= nums[i-1] - nums[i] + curSumA
            AND preSumA <= curSumA
            => preSumA <= min(curSumA, nums[i-1] - nums[i] + curSumA)
            if(preSumA<0)
                dp[i][j] = 0;
            => preSumA >= 0 AND preSumA <= min(curSumA, nums[i-1] - nums[i] + curSumA)

            so for (k = 0 k <= min(curSumA, nums[i-1] - nums[i] + curSumA))
                dp[i][j]+=dp[i-1][k]
            we can use prefixSum
         */

        int n = nums.length;
        int dp[][] = new int[n][1005];
        int pre[] = new int[1005];
        //if there is one element
        for(int j=0;j<=nums[0];j++){
            dp[0][j] = 1;
            pre[j] = 1;
            if(j>0)
                pre[j]+=pre[j-1];
        }
        for(int i=1;i<n;i++){
            for(int j=0;j<=nums[i];j++){
                int R = Math.min(j, nums[i-1] - nums[i] + j);
                R = Math.min(R,nums[i-1]);
                if(R<0)
                {
                    dp[i][j] = 0;
                    continue;
                }
                R = Math.max(0,R);
                dp[i][j] = (dp[i][j] + pre[R]) % MOD;
            }
            for(int j=0;j<=nums[i];j++)
            {
                pre[j] = dp[i][j];
                if(j>0)
                    pre[j] = (pre[j]+pre[j-1])%MOD;
            }
        }
        int ans = 0;
        for(int j=0;j<=nums[n-1];j++)
        {
            ans = (ans + dp[n-1][j])%MOD;
        }
        return ans;
    }
}