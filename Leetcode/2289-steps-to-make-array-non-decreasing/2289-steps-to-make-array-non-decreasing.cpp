class Solution {
public:
    int totalSteps(vector<int>& A) {
        int n = A.size(), res = 0;
        vector<int> stack, dp(n);
        for (int i = n - 1; i >= 0; --i) {
            while (!stack.empty() && A[i] > A[stack.back()]) {
                dp[i] = max(1+dp[i], dp[stack.back()]);
                stack.pop_back();
                res = max(res, dp[i]);
            }
            stack.push_back(i);
        }
        return res;
    }
};

        // vector<int>right(n);
        // stack<int>st;
        // for(int i=n-1;i>=0;i--){
        //     int cnt=0;
        //     while(st.size() and a[i]>a[st.top()])
        //         cnt++,st.pop();
        //     right[i] = cnt;
        //     // if(st.empty())
        //         // left[i]=-1;
        //     // else
        //         // left[i] = st.top();
        //     st.push(i);
        // }
        // int ans=0;
        // for(int i=0;i<n;i++)
        // {
        //     cout<<right[i]<<" ";
        //     if(right[i]==0)
        //         continue;
        //     ans= max(ans,right[i]+1);
        // }
        // cout<<endl;
        // return ans;