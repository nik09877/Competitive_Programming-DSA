class Solution {
    private long go(int i,int row, long[][] dp,int[] a,int[] b){
        if(i>=a.length)
            return 0;
        
        long ans = dp[i][row];
        if(ans!=-1)
            return ans;
        
        ans = (row==0?a[i]:b[i]) + Math.max(go(i+1,row,dp,a,b),go(i+2,row^1,dp,a,b));
        return dp[i][row] = ans;
    }
    public long maxEnergyBoost(int[] a, int[] b) {
        int n = a.length;
        long[][] dp = new long[n][2];
        for(int i=0;i<n;i++)
            Arrays.fill(dp[i],-1);
        return Math.max(go(0,0,dp,a,b),go(0,1,dp,a,b));
    }
}