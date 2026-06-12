class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        struct ArrayHash {
            size_t operator()(array<int, 26> const& arr) const {
                size_t seed = 0;
                for (int val : arr) {
                    seed ^= hash<int>{}(val) + 0x9e3779b9 + (seed << 6) +
                            (seed >> 2);
                }
                return seed;
            }
        };

        unordered_map<array<int, 26>, vector<string>, ArrayHash> container;

        for (int i = 0; i < (int)strs.size(); ++i) {
            array<int, 26> counter{};

            for (auto& ch : strs[i]) {
                counter[ch - 'a']++;
            }

            container[counter].push_back(strs[i]);
        }

        vector<vector<string>> result;

        for (auto& [key, group] : container) {
            result.push_back(std::move(group));
        }

        return result;
    }
};
