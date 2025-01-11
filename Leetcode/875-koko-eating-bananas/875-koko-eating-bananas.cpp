class Solution {
public:
    
    bool isValid(int k,vector<int>piles,int H){
        long time=0;
        for(int i=0;i<piles.size();i++){
            time+=(piles[i]+k-1)/k;
        }
        return time<=H;
    }
    int minEatingSpeed(vector<int>& piles, int H) {
        int ans=-1,mid;
        int lb=1;
        int ub=*max_element(piles.begin(),piles.end());
        
        while(lb<=ub){
            mid=(lb+ub)/2;
            
            if(isValid(mid,piles,H)){
                
                ans=mid;
                ub=mid-1;
            }
            else{
                
                lb=mid+1;
            }
        }
        return ans;
    }
};