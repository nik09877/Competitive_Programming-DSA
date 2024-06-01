class Solution {
public:
    int maxPalindromesAfterOperations(vector<string>& words) {
        vector<int> A;
        for (const string& w : words)
            A.push_back(w.length());
        sort(A.begin(), A.end());

        unordered_map<char, int> count;
        for (auto& w : words)
            for (char c : w)
                count[c]++;
        int pairs = 0, n = A.size();
        for (auto& p : count)
            pairs += p.second / 2;

        for (int i = 0; i < n; ++i)
            if ((pairs -= A[i] / 2) < 0)
                return i;
        return n;
    }
};