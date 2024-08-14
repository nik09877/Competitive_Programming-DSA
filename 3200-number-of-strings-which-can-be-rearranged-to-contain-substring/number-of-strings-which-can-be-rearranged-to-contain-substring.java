class Solution {
    private static final int EMPTY = 0b0000,
        LEET = 0b1111,
        L = 0b1000,
        FIRST_E =  0b0100,
        SECOND_E = 0b0010,
        T = 0b0001;
    
    private static final long MOD = 1_000_000_007;

    private long dp[][], n;

    public int stringCount(int n) {
        this.n = n;
        this.dp = new long[n][16];
        for(int i = 0; i < n; i++){
            Arrays.fill(dp[i], -1);
        }
        return (int)this.findWays(0, EMPTY);
    }

    long findWays(int i, int mask){
        if(i == n)
            return mask == LEET ? 1 : 0;

        if(dp[i][mask] != -1)
            return dp[i][mask];
        
        // Choose L or T
        long ways = findWays(i + 1, mask | L) + findWays(i + 1, mask | T);

        if((mask & FIRST_E) > 0)
            // FIRST_E was already chosen earlier
            ways += findWays(i + 1, mask | SECOND_E);
        else
            // Choose FIRST_E
            ways += findWays(i + 1, mask | FIRST_E);

        // Choose any of other 23 chars
        ways = (ways + 23 * findWays(i + 1, mask)) % MOD;
        
        dp[i][mask] = ways;
        return ways;
    }
}