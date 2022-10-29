class Solution {
public:
    int validSubarraySize(vector<int>& a, int v) {
        stack<int>st;
        int n = a.size();
        vector<int>left(n,-1),right(n,n);
        for(int i=0;i<n;i++){
            while(st.size() and a[st.top()]>=a[i])
                st.pop();
            if(st.empty())
                left[i] = -1;
            else
                left[i] = st.top();
            st.push(i);
        }
        st = stack<int>();
        for(int i=n-1;i>=0;i--){
            while(st.size() and a[st.top()]>=a[i])
                st.pop();
            if(st.empty())
                right[i] = n;
            else
                right[i] = st.top();
            st.push(i);
        }
        
        for(int i=0;i<n;i++){
            int len = right[i]-left[i]-1;
            if(a[i]>(v/len))
                return len;
        }
        return -1;
    }
};