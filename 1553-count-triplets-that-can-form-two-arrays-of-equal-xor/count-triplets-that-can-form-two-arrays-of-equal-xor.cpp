class Solution {
public:
    int countTriplets(vector<int>& arr) {
        unordered_map<int,int>cnt,sum;
        int x_or = 0,ans(0);
        for(int i=0;i<arr.size();i++){
            int x = arr[i];
            x_or^=x;
            if(x_or == 0){
                ans+=i;
            }
            if(cnt.count(x_or)){
                ans+= cnt[x_or]*i - sum[x_or];
            }
            cnt[x_or]++;
            sum[x_or]+=i+1;
        }
        return ans;        
    }
};