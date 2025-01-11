class Solution {
public:
    int findMin(vector<int>& a) {
        int l=0,r=a.size()-1;
        while(l<r){
            int m=(l+r)>>1;
            if(a[m]==a[r])
                r--;
            else if(a[m]>a[r])
                l=m+1;
            else
                r=m;
        }
        return a[l];
    }
};