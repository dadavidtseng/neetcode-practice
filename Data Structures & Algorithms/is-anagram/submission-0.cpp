#include <array>

class Solution {
public:
    bool isAnagram(string s, string t) {
        if (s.size() != t.size())
        {
            return false;
        }
   
        array<int, 26> counter{};

        for (int i = 0; i < static_cast<int>(s.size()); ++i)
        {
            counter[s[i] - 'a']++;
            counter[t[i] - 'a']--;
        }

        return counter == array<int, 26>{};
    }
};
