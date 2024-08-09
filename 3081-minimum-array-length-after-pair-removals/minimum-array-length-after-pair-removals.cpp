class Solution {
public:
    // time/space: O(nlogn)/O(n)
    int minLengthAfterRemovals(vector<int>& nums) {
        // calculate the frequency for each number
        int n = nums.size();
        unordered_map<int, int> freq;
        for (const int& num : nums) freq[num]++;
        
        // push the frequencies to a max. heap
        priority_queue<int> pq;
        for (auto it = freq.begin(); it != freq.end(); it++) pq.push(it->second);
        
        // keep removing the top 2 elements
        while (pq.size() >= 2) {
            int count1 = pq.top();
            pq.pop();
            int count2 = pq.top();
            pq.pop();
            if (count1 > 1) pq.push(count1 - 1);
            if (count2 > 1) pq.push(count2 - 1);            
        }
        
        // return `0` if all elements are removed
        if (pq.empty()) return 0;

        // return the rest frequency
        return pq.top();
    }
};