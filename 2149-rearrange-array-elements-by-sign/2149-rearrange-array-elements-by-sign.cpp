class Solution {
public:
    vector<int> rearrangeArray(vector<int>& a) {
        int n = a.size();
        int i=0,j=0;
        vector<int>ans;
        while(i<n or j<n){
            //find pos ele
            while(i<n and a[i]<0)
                i++;
            if(i<n)
                ans.push_back(a[i++]);
            
            //find neg ele
            while(j<n and a[j]>0)
                j++;
            if(j<n)
                ans.push_back(a[j++]);
        }
        return ans;
    }
};