class Solution {
public:
    long long minOperationsToMakeMedianK(vector<int>& a, int k) {
                    
        // if n is odd
        //      x y  k a b
        // if n is even

        //    n/2  k  n/2-1

        // max pq  k  

        // max pq -> number of elements smaller than k      
        // min pq -> number of elements greater than k

        // 5

        // 1 2 4 5 6 7 8

        int n = a.size();

        priority_queue<pair<int,int>,vector<pair<int,int>>,greater<pair<int,int>>>right_mn_pq;
        priority_queue<pair<int,int>>left_mx_pq;

        for(int i=0;i<n;i++){
            int x = a[i];
            if(x<k)
                left_mx_pq.push({x,i});
            else if(x>k)
                right_mn_pq.push({x,i});
        }
        
        long long ans = 0;
        //n is odd
        if(n&1){
            int mx_req = n/2;

            while(left_mx_pq.size() > mx_req){
                auto [x,i] = left_mx_pq.top();
                left_mx_pq.pop();
                ans+=k-x;
            }

            while(right_mn_pq.size() > mx_req){
                auto [x,i] = right_mn_pq.top();
                right_mn_pq.pop();
                ans+=x-k;
            }
        }
        else{
            int mx_req_left = n/2;
            while(left_mx_pq.size() > mx_req_left){
                auto [x,i] = left_mx_pq.top();
                left_mx_pq.pop();
                ans+=k-x;
            }

            while(right_mn_pq.size() > mx_req_left - 1){
                auto [x,i] = right_mn_pq.top();
                right_mn_pq.pop();
                ans+=x-k;
            }
        }
        return ans;
    }
};