class Solution {
   public:
    vector<vector<int>> combinationSum(vector<int>& nums, int target) {
        vector<vector<int>> result;
        vector<int> curr;

        function<void(int, size_t)> backtrack = [&](int target, size_t idx) {
            // If target is 0,
            // store curr into result and return because we've got nothing to add to curr
            if (target == 0) {
                result.push_back(curr);
                return;
            }

            // If target or idx is invalid
            // return immediately because won't be able to find anything going further
            if (target < 0 || idx >= nums.size()) {
                return;
            }

            // Push the current candidate into curr
            curr.push_back(nums[idx]);

            // Recursive call with new remaining target
            backtrack(target - nums[idx], idx);

            // Remove candidates[idx] from curr when unwinding from the recursive call
            curr.pop_back();

            // Recursive call with target
            backtrack(target, idx + 1);
        };

        backtrack(target, 0);
        return result;
    }
};
