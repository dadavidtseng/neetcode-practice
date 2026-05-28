class Solution {
   public:
    vector<vector<int>> combinationSum(vector<int>& nums, int target) {
        vector<vector<int>> result;
        vector<int> currentCombination;

        // sort the candidates before entering the recursive call for early termination
        sort(nums.begin(), nums.end());
        backtrack(nums, target, 0, currentCombination, result);

        return result;
    }

    void backtrack(vector<int>& candidates, int const remainTarget, size_t const startIndex,
                   vector<int>& currentCombination, vector<vector<int>>& result) {
        // if the remainTarget is 0,
        // store the current combination into result and return
        if (remainTarget == 0) {
            result.push_back(currentCombination);
            return;
        }

        // iterate candidates from startIndex
        for (size_t i = startIndex; i < candidates.size(); i++) {
            int const newRemainTarget = remainTarget - candidates[i];

            // if remainTarget is less than current candidate
            // return immediately because it's invalid
            if (newRemainTarget < 0) {
                return;
            }

            // store the current candidate into currentCombination
            currentCombination.push_back(candidates[i]);

            // recursive call with newRemainTarget and carry the currentCombination
            backtrack(candidates, newRemainTarget, i, currentCombination, result);

            // remove this candidate from currentCombination
            currentCombination.pop_back();
        }
    }
};
