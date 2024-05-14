class Solution {
public:
    int maxScore(vector<vector<int>>& grid) {
        int n = grid.size();
        int m = grid[0].size();
        vector<vector<int>> dp(n, vector<int>(m, INT_MAX));
        int mx_score = INT_MIN;
        dp[0][0] = grid[0][0];
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                dp[i][j] = grid[i][j];
                if (i) {
                    dp[i][j] = min(dp[i][j], dp[i - 1][j]);
                    mx_score = max(mx_score, grid[i][j] - dp[i - 1][j]);
                }
                if (j) {
                    dp[i][j] = min(dp[i][j], dp[i][j - 1]);
                    mx_score = max(mx_score, grid[i][j] - dp[i][j - 1]);
                }
            }
        }

        return mx_score;
    }
};