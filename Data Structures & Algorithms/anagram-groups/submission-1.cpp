class Solution {
   public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        map<array<int, 26>, vector<string>> container;

        for (string& str : strs) {
            array<int, 26> counter{};

            for (char const& c : str) {
                counter[c - 'a']++;
            }

            container[counter].push_back(str);
        }

        vector<vector<string>> result;

        for (auto& [key, group] : container) {
            result.push_back(group);
        }

        return result;
    }
};
