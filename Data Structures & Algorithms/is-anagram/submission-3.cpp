class Solution {
   public:
    bool isAnagram(string s, string t) {
        // return false if the size of two strings are different
        if (s.size() != t.size()) {
            return false;
        }

        // Initialize the array with 26 empty slots
        array<int, 26> a{};

        // Iterate through the string and count the character
        for (int i = 0; i < static_cast<int>(s.size()); ++i) {
            a[s[i] - 'a']++;
            a[t[i] - 'a']--;
        }

        // return true if the array is empty
        return a == array<int, 26>{};
    }
};
