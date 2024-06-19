class Solution {
#define ll long long 
private:
    ll getMaxDamage(vector<ll>& dp, map<int, int>& frequencyMap, vector<int>& uniquePowers, int index) {
        if (index == uniquePowers.size()) return 0;
        if (dp[index] != -1) return dp[index];
        // Option 1: Skip the current element
        ll skip = getMaxDamage(dp, frequencyMap, uniquePowers, index + 1);
        // Option 2: Take the current element
        ll take = 0;
        int nextIndex = index + 1;
        while (nextIndex < uniquePowers.size() && uniquePowers[nextIndex] - uniquePowers[index] <= 2) {
            nextIndex++;
        }
        take = ((1ll)*frequencyMap[uniquePowers[index]] * uniquePowers[index]) + getMaxDamage(dp, frequencyMap, uniquePowers, nextIndex);
        return dp[index] = max(take, skip);
    }
public:
    long long maximumTotalDamage(vector<int>& power) {
        map<int, int> frequencyMap;
        vector<int> uniquePowers;
        // Create frequency map and unique powers list
        for (auto p : power) {
            frequencyMap[p]++;
        }
        for (auto it : frequencyMap) {
            uniquePowers.push_back(it.first);
        }
        // Initialize DP array with -1
        vector<ll> dp(frequencyMap.size(), -1);
        // Start the recursive function
        return getMaxDamage(dp, frequencyMap, uniquePowers, 0);
    }
};