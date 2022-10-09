class Solution {
public:
    bool search(vector<int>& a, int target) {
        int n = (int)a.size();
        int l = 0,  r = n-1;
        
        /*
        [1,1,1,1,1,1,1,1,1,1,1,1,1,2,1,1,1,1,1]
        2
        */
        //IMP for above case
        while(l<n-1 and a[l]==a[l+1])
            l++;
        while(r>0 and a[r]==a[r-1])
            r--;
        
        
        //find pos of smallest element
        int pivot = -1;
        while(l<r){
            int mid = (l+r)>>1;
            if(a[mid]==a[r])
                r--;
            else if(a[mid]>a[r])
                l=mid+1;
            else
                r=mid;
        }
        pivot = l;
        cout<<pivot<<endl;
        
        //decide in which section you want to binary search
        if(pivot == 0)
            l = 0 , r=n-1;
        else{
            if(target > a[n-1])
                l=0,r=pivot-1;
            else 
                l=pivot,r=n-1;
        }
        while(l<=r){
            int mid = (l+r)>>1;
            if(a[mid]==target)
                return true;
            else if(a[mid]<target)
                l=mid+1;
            else
                r=mid-1;
        }
        return false;
    }
};