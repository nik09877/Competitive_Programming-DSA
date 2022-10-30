class Solution {
public:
    long long f(int x,vector<int>& a,vector<int>& cost){
        long long sum=0;
        for(int i=0;i<a.size();i++){
            sum+=abs(x-a[i])*1ll*cost[i];
        }
        return sum;
    }
    long long minCost(vector<int>& a, vector<int>& cost) {
        //binary search on convex functions
        int l = 1, r = 1e6;
        while(l<=r){
            int m = (l+r)>>1;
            
            long long mid_sum = f(m,a,cost);
            long long left_sum = f(m-1,a,cost);
            long long right_sum = f(m+1,a,cost);
            
            if(mid_sum<=left_sum and mid_sum<=right_sum)
                return mid_sum;
            if(left_sum<=mid_sum)
                r = m-1;
            else
                l=m+1;
        }
        return 0;
    }
};