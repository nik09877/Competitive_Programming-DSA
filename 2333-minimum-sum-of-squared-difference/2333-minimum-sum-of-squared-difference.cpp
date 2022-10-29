class Solution {
public:
bool ispossible(vector<int>&v, int cut, long long &k){
        long long total = 0;
        for(int i = 0; i < v.size(); i++){
            if(v[i] > cut)
                total += v[i] - cut;
        }
        return total <= k;
    }
    long long minSumSquareDiff(vector<int>& nums1, vector<int>& nums2, int k1, int k2) {
        int n = nums1.size();
        vector<int>v(n);
        for(int i = 0; i < n; i++){
            v[i] = abs(nums1[i] - nums2[i]);
        }
		/*
		using binary search we get the maximum value of abs(nums1[i] - nums2[i]) , which is possible 
		to reduce from all the abs differences above that and still k will be >= 0
		*/
        int low = 0;
        int high = *max_element(v.begin(), v.end());
        int ans = 0; 
        long long k = k1+k2;
        while(low <= high){
            int mid = low + (high - low) / 2;
            if(ispossible(v, mid, k)){
                ans = mid;
                high = mid - 1;
            }else{
                low = mid + 1;
            }
        }
		//reducing all the abs(nums1[i] - nums2[i]) and also reducing k by that much amount
        long long res = 0;
        for(int i = 0; i < n; i++){
            if(v[i] > ans && k > 0){
                int dif = v[i] - ans;
                k -= dif;
                v[i] -= dif;
            }
        }
        priority_queue<int>pq;
        for(int i = 0; i < n; i++){
            pq.push(v[i]);
        }
		//now removing rest of the extra k's from the array to get optimal res
        while(k > 0 && pq.top() > 0){
            int l = pq.top();
            pq.pop();
            l -= 1;
            pq.push(l);
            k--;
        }
		//if the maximum difference is 0, then rest of the differences will also be 0, so return 0
        if(pq.top() == 0)
            return 0;
		//else, while top element is > 0, poping one by one and adding it to the res
        while(!pq.empty() && pq.top() > 0){
            res += pq.top()* 1ll * pq.top();
            pq.pop();
        }
        return res;
    }
};