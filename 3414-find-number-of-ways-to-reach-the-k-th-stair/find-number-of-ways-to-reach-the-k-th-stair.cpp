class Solution {
public:
    unordered_map<string, int> mp;
    typedef long long ll;

    vector<ll> power;
    int K;

    int solve(int i, int jump, int canGoBack) {
        if (i > K + 1)
            return 0;

        string key = to_string(i) + "_" + to_string(jump) + "_" + to_string(canGoBack);

        if (mp.find(key) != mp.end())
            return mp[key];

        int count = 0;

        if(i == K) {
            count++; //aage jaao. Kyoki wapas bhi aa sakte ho K me tum. Don'r return from here
        }

        if (canGoBack == 1) {
            count += solve(i - 1, jump, 0);
        }

        count += solve(i + power[jump], jump + 1, 1);

        return mp[key] = count;
    }

    int waysToReachStair(int k) {
        power.resize(33);
        K = k;
        
        for(int i = 0; i < 33; ++i) {
            power[i] = pow(2, i);
        }

        mp.clear();
        return solve(1, 0, 1);
    }
};