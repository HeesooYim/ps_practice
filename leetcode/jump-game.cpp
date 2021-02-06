// greedy
class Solution {
public:
    bool canJump(vector<int>& nums) {
        int last = nums.size() - 1;

        for (int i = nums.size() - 1; i >= 0; i--) {
            if (i + nums[i] >= last)
                last = i;
        }

        return last == 0;
    }
};

//dp
class Solution {
public:
    bool canJump(vector<int>& nums) {
        vector<bool> dp(nums.size(), false);
        dp[0] = true;

        for (int i = 0; i < nums.size(); i++) {
            if (!dp[i]) continue;
            int mx = min(i + nums[i], int(nums.size() - 1));
            for (int j = i + 1; j <= mx; j++) {
                dp[j] = true;
            }
        }

        return dp[nums.size() - 1];
    }
};
