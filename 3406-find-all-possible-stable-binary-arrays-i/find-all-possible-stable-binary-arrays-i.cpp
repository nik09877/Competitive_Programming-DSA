class Solution {
public:
 int mod = 1e9 + 7; 
    int dp[202][202][2];    
    int solve(int one, int zero, bool ms, int limit){
        if(one==0 && zero==0) return 1;
        
        int ans = 0;
      
        if(dp[one][zero][ms]!=-1)
            return dp[one][zero][ms]; 
        
        if(ms==1) 
        {
            for(int i=1; i<=min(one,limit); i++){
                ans = (ans+solve(one-i,zero,false,limit)%mod)%mod ;
            }
        }
        else if(ms==0){ 
            for(int i=1; i<=min(zero,limit); i++){
                ans = (ans+solve(one,zero-i,true,limit)%mod)%mod ;
            }
        }
        return dp[one][zero][ms] = ans%mod; 
    }
    int numberOfStableArrays(int zero, int one, int limit) {
         memset(dp,-1,sizeof(dp)) ;
         int a=solve(one,zero,1,limit)%mod;
         int b= solve(one,zero,0,limit)%mod;
         return (a+b)%mod;    
    }
};