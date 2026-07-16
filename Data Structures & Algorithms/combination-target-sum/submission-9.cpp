class Solution {
   public:
    vector<vector<int>> combinationSum(vector<int>& nums, int target) {
        vector<vector<int>> result;
        vector<int> curr;

        // Sort the candidates before entering the recursive call for early termination
        sort(nums.begin(), nums.end());

        function<void(int, size_t)> backtrack = [&](int target, size_t idx) {
            // If target is 0,
            // store curr into result and return because we've got nothing to add to curr
            if (target == 0) {
                result.push_back(curr);
                return;
            }

            // Iterate candidates from idx
            for (size_t i = idx; i < nums.size(); ++i) {
                // If the current candidate is invalid
                // return immediately because won't be able to find anything going further
                if (nums[i] > target) {
                    return;
                }

                // Push the current candidate into curr
                curr.push_back(nums[i]);

                // Recursive call with new remaining target
                backtrack(target - nums[i], i);

                // Remove this candidate from curr when unwinding from the recursive call
                curr.pop_back();
            }
        };

        backtrack(target, 0);
        return result;
    }
};
