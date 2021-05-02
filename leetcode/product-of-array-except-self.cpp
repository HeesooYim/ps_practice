class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        vector<int> ans;
        int zero_cnt = 0;
        int product = 1;
        for (int i = 0; i < nums.size(); i++) {
            if (nums[i] == 0) {
                zero_cnt++;
                continue;
            }
            product *= nums[i];
        }

        if (zero_cnt) {
            if (zero_cnt > 1) {
                product = 0;
            }
            for (int i = 0; i < nums.size(); i++) {
                if (nums[i] == 0) ans.push_back(product);
                else ans.push_back(0);
            }
        }
        else {
            for (int i = 0; i < nums.size(); i++) {
                ans.push_back(product / nums[i]);
            }
        }

        return ans;
    }
};


// without division
class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        vector<int> ans(nums.size());
        ans[0] = 1;
        for (int i = 1; i < nums.size(); i++) {
            ans[i] = ans[i - 1] * nums[i - 1];
        }

        vector<int> temp(nums.size());
        temp[nums.size() - 1] = 1;
        for (int i = nums.size() - 2; i >= 0; i--) {
            temp[i] = temp[i + 1] * nums[i + 1];
        }

        for (int i = 0; i < nums.size(); i++) {
            ans[i] *= temp[i];
        }

        return ans;
    }
};

// O(1) space complexity 
class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        vector<int> ans(nums.size());
        ans[0] = 1;
        for (int i = 1; i < nums.size(); i++) {
            ans[i] = ans[i - 1] * nums[i - 1];
        }

        for (int i = nums.size() - 2; i > 0; i--) {
            nums[i] *= nums[i + 1];
        }

        for (int i = 0; i < nums.size() - 1; i++) {
            ans[i] *= nums[i + 1];
        }

        return ans;
    }
};
