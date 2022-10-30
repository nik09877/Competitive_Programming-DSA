#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace __gnu_pbds;
template <class T>
using ordered_set = tree<T, null_type, less<T>, rb_tree_tag, tree_order_statistics_node_update>;

class Solution {
public:
    long long numberOfPairs(vector<int>& a, vector<int>& b, int d) {
        ordered_set<pair<int,int>>st;
        int n = a.size();
        long long ans=0;
        for(int i=0;i<n;i++){
            int key = a[i]-b[i];
            ans+=st.order_of_key({key+d,n});
            st.insert({key,i});
        }
        return ans;
    }
};