class Solution {
public:
    int maximalSquare(vector<vector<char>>& matrix) {
        int ret = 0;
        int r = matrix.size();
        int w = matrix[0].size();
        vector<vector<int>> dp(r, vector<int>(w, 0));

        for (int i = 0; i < r; i++) {
            for (int j = 0; j < w; j++) {
                if (matrix[i][j] == '0') continue;
                if (i == 0 || j == 0) {
                    dp[i][j] = matrix[i][j] - '0';
                }
                else {
                    dp[i][j] = min(dp[i - 1][j - 1], min(dp[i - 1][j], dp[i][j - 1])) + 1;
                }
                ret = max(ret, dp[i][j]);
            }
        }

        return ret * ret;
    }
};
