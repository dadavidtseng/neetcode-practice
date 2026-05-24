class Solution {
   public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        unordered_map<string, vector<string>> container;

        for (int i = 0; i < (int)strs.size(); ++i) {
            string key = strs[i];
            sort(key.begin(), key.end());

            container[key].push_back(strs[i]);
        }

        vector<vector<string>> result;

        for (auto& [key, group] : container) {
            result.push_back(group);
        }

        return result;
    }
};
