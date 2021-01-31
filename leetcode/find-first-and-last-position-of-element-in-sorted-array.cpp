class Solution {
public:
    int first_pos(vector<int>& nums, int target) {
        //return first_position >= target
        int l = 0;
        int r = nums.size() - 1;
        int mid;
        int first = nums.size();

        while (l <= r) {
            mid = l + (r - l) / 2;
            if (target <= nums[mid]) {  //if(target == nums[mid])
                first = mid;
                r = mid - 1;
            }
            //else if (nums[mid] > target)
            //    r = mid - 1;
            else
                l = mid + 1;
        }

        return first;
    }

    vector<int> searchRange(vector<int>& nums, int target) {
        int first = first_pos(nums, target);
        int last = first_pos(nums, target + 1) - 1;

        if (first >= 0 && first < nums.size() && nums[first] == target)
            return { first,last };
        else return { -1,-1 };
    }
};

