class Solution {
public:
    int numSquares(int n) {
        vector<int> dp(n + 1, INT_MAX);
        dp[0] = 0;

        for (int i = 1; i <= n; i++) {
            for (int j = 1; j * j <= i; j++) {
                dp[i] = min(dp[i - j * j] + 1, dp[i]);
            }
        }

        return dp[n];
    }
};

// time limitation...
class Solution {
public:
    int numSquares(int n) {
        vector<int> dp(n + 1, 0);
        int i = 1;
        while (i*i <= n) {
            dp[i*i] = 1;
            if(i*i + 1 > n) break;
            dp[i*i + 1] = 2;
            i++;
        }

        for (i = 2; i <= n; i++) {
            if (dp[i]) continue;
            dp[i] = dp[1] + dp[i - 1];
            for (int j = 2; j <= i / 2; j++) {
                dp[i] = min(dp[i], dp[j] + dp[i - j]);
            }
        }
        
	return dp[n];
    }
};
