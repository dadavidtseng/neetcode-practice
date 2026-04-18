class Solution {
public:
    bool hasDuplicate(vector<int>& nums) {
        unordered_set<int> container;

        for (int i = 0; i < static_cast<int>(nums.size()); ++i)
        {   
            // bool value set to true if and only if the insertion took place
            if (!container.insert(nums[i]).second)
            {   
                return true;
            }
        }

        return false;
    }
};