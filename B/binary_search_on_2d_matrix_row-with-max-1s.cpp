//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
//User function template for C++
class Solution{
public:
	int rowWithMax1s(vector<vector<int> > a, int n, int m) {
	    int mx_cnt=0,mx_row=-1,cnt=0;
	    int i=0,j=m-1;
	    
	    while(i<n and j>=0){
	        if(a[i][j]==1){
	            cnt++;	            
	            if(cnt>mx_cnt)
	            mx_cnt=cnt,mx_row=i;
	            j--;
	        }
	        else{
	            if(cnt>mx_cnt)
	            mx_cnt=cnt,mx_row=i;
	            i++;
	        }
	    }
	    return mx_row;
	}

};

//{ Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t--) {
        int n, m;
        cin >> n >> m;
        vector< vector<int> > arr(n,vector<int>(m));
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                cin>>arr[i][j];
            }
        }
        Solution ob;
        auto ans = ob.rowWithMax1s(arr, n, m);
        cout << ans << "\n";
    }
    return 0;
}

// } Driver Code Ends