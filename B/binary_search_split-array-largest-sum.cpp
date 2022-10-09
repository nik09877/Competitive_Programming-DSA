class Solution {
public:
    
    int splitArray(vector<int>& a, int k) {
        int l = 0 , r = 1000000000,ans = -1;
       
        auto good = [&](int m){
           //find cnt of minimum subarrays with fixed sum of m 
           int cnt = 0, sum = 0;
           for(auto x:a){
               if(x>m)
                   return false;
               sum+=x;
               if(sum>m)
                   cnt++,sum = x;
           }
            cnt++;
            return cnt<=k;
        };
        
        while(l<=r){
            int m = (l+r)>>1;
            if(good(m))
                ans = m , r = m-1;
            else
                l = m+1;
        }
        return ans;
    }
};
