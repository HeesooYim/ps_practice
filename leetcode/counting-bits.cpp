// dp로 풀어보려 했으나,,뭔가 구려짐,,
class Solution {
public:
    vector<int> countBits(int num) {
        vector<int> ans(num + 1, 0);
        ans[0] = 0;
        if(num > 0)
            ans[1] = 1;

        for (int i = 1; ; i++) {
            for (int j = int(pow(2, i)); j < int(pow(2, i + 1)); j++) {
                if (j > num) return ans;

                int n = j - pow(2, i - 1);
                if (n < pow(2, i)) {
                    ans[j] = ans[n];
                }
                else {
                    ans[j] = ans[n] + 1;
                }
            }
        }
    }
};


class Solution {
public:
    vector<int> countBits(int num) {
        vector<int> dp(num + 1, 0);
        dp[0] = 0;

        for (int i = 1; i <= num; i++) {
            if (i % 2 == 0)
                dp[i] = dp[i / 2];
            else
                dp[i] = dp[i / 2] + 1;
        }

        return dp;
    }
};
