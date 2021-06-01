class Solution:
    def lengthOfLIS(self, nums: List[int]) -> int:
        dp = [1 for i in range(len(nums))]
        ret = 1
        
        for i in range(1, len(nums)):
            for j in range(0,i):
                if(nums[j] < nums[i]):
                    dp[i] = max(dp[j] + 1, dp[i])
                else:
                    dp[i] = max(0, dp[i])
            ret = max(ret, dp[i])
            
        return ret
        
        
'''
class Solution {
public:
    int lengthOfLIS(vector<int>& nums) {
        vector<int> dp(nums.size(),1);
        int ret = 1;

        for (int i = 1; i < nums.size(); i++) {
            for (int j = 0; j < i; j++) {
                dp[i] = max(nums[j] < nums[i] ? dp[j] + 1 : 0, dp[i]);
            }
            ret = max(ret, dp[i]);
        }
        
        return ret;
    }
};        
'''
