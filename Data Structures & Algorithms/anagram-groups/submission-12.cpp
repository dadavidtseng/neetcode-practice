class Solution {
   public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        unordered_map<string, vector<string>> m;

        // Iterate through strs
        for (int i = 0; i < static_cast<int>(strs.size()); ++i) {
            vector v(26, 0);

            // For every c in strs[i], use v to count the frequency of the c
            for (const char& c : strs[i]) {
                v[c - 'a']++;
            }

            string s = to_string(v[0]);

            for (int j = 1; j < 26; ++j) {
                s += ',' + to_string(v[j]);
            }

            m[s].push_back(strs[i]);
        }

        vector<vector<string>> result;
        result.reserve(m.size());

        for (auto& [key, group] : m) {
            result.push_back(group);
        }

        return result;
    }
};
