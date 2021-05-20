class Solution {
public:
    int coinChange(vector<int>& coins, int amount) {
        vector<int> dp(amount + 1, 10001);
        dp[0] = 0;

        for (int c : coins) {
            if(c >= amount) continue;
            dp[c] = 1;
        }

        for (int i = 0; i <= amount; i++) {
            int mn = dp[i];
            for (int c : coins) {
                if (i < c) continue;
                mn = min(dp[i - c] + 1, mn);
            }
            dp[i] = mn;
        }

        return dp[amount] == 10001 ? -1 : dp[amount];
    }
};
