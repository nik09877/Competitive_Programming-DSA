class Solution {
public:
    int dp[1001][1001][2];
    int mod = 1000000007;
    unordered_set<char>primes;
    int go(int i,int rem_partition,int picking_state,int& mn_len,int& n,string& s){
        if(i > n){
            return 0;
        }
        if(i==n){
            return (rem_partition == 0) and (picking_state == 0);
        }
        if(!rem_partition)
            return 0;
        if(picking_state == 0 and !primes.count(s[i])){
            return 0;
        }
        int& ans = dp[i][rem_partition][picking_state];
        if(ans!=-1)
            return ans;
        
        if(picking_state == 0){
            ans = go(i+mn_len-1,rem_partition,picking_state^1,mn_len,n,s);
            ans%=mod;
        }
        else{
            //extend
            ans = go(i+1,rem_partition,picking_state,mn_len,n,s);
            ans%=mod;
            //choose to end the substring here
            if(rem_partition and !primes.count(s[i])){
                ans+=go(i+1,rem_partition-1,picking_state^1,mn_len,n,s);
                ans%=mod;
            }
        }
        return ans;
    }
    int beautifulPartitions(string s, int k, int minLength) {
        primes.insert('2');
        primes.insert('3');
        primes.insert('5');
        primes.insert('7');
        memset(dp,-1,sizeof(dp));
        int n = s.size();
        return go(0,k,0,minLength,n,s);
    }
};