#define ll long long
class Solution {
public:
    set<int>cut_w,cut_h;
    map<pair<int,int>,int>cost;
    ll dp[202][202], mn = -1000000000000;
    
    ll go(int h,int w){
        ll& ans = dp[h][w];
        if(ans!=-1)
            return ans;
        
        // ans=mn;
        // if(cost[{h,w}]!=0)
        ans=cost[{h,w}];
        
        for(auto i:cut_h){
            if(i>=h)
                continue;
            ans = max( ans , go(i,w)+go(h-i,w));
        }
        for(auto i:cut_w){
            if(i>=w)
                continue;
            ans = max( ans , go(h,i)+go(h,w-i));
        }
        return ans;
    }
    long long sellingWood(int m, int n, vector<vector<int>>& prices) {
        for(auto x:prices){
            int h,w,c;
            h = x[0],w=x[1],c=x[2];
            cut_w.insert(w),cut_h.insert(h);
            cost[{h,w}] = c;
        }
        memset(dp,-1,sizeof(dp));
        return go(m,n);
    }
};