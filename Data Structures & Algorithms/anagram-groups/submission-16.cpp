class Solution {
   public:
    //-----------------------------------------------------------------------------------------------
    // Custom hash functor for array<int, 26>, enabling its use as an unordered_map key.
    // Combines element hashes using the Boost hash_combine technique.
    struct ArrayHash {
        size_t operator()(array<int, 26> const& arr) const {
            size_t seed = 0;

            for (int val : arr) {
                seed ^= hash<int>{}(val) + 0x9e3779b9 + (seed << 6) + (seed >> 2);
            }

            return seed;
        }
    };

    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        unordered_map<array<int, 26>, vector<string>, ArrayHash> m;

        // Iterate through strs
        for (int i = 0; i < static_cast<int>(strs.size()); ++i) {
            array<int, 26> a{};

            // For every c in strs[i], use a to count the frequency of the c
            for (const char& c : strs[i]) {
                a[c - 'a']++;
            }

            // At a(array<int, 26>), push strs[i] into the map
            m[a].push_back(strs[i]);
        }

        vector<vector<string>> result;

        for (unordered_map<array<int, 26>, vector<string>>::iterator it = m.begin(); it != m.end();
             ++it) {
            result.push_back(it->second);
        }

        return result;
    }
};
