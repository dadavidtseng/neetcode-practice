class Solution {
   public:
    int trap(vector<int>& height) {
        int result = 0;
        vector<int> prefix;
        vector<int> suffix;
        int prefixMax = 0;
        int suffixMax = 0;

        for (int i = 0; i < height.size(); ++i) {
            prefixMax = max(prefixMax, height[i]);
            suffixMax = max(suffixMax, height[height.size() - 1 - i]);
            prefix.push_back(prefixMax);
            suffix.push_back(suffixMax);
        }

        for (int i = 0; i < height.size(); ++i) {
            result += min(prefix[i], suffix[height.size() - 1 - i]) - height[i];
        }

        return result;
    }
};
