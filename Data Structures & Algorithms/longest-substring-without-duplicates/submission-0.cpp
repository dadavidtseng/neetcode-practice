class Solution {
   public:
    int lengthOfLongestSubstring(string s) {
        unordered_map<char, int> window;  // stores char and index
        int left = 0;                     // left index of the window
        int result = 0;                   // max length of substring

        for (int i = 0; i < static_cast<int>(s.size()); ++i) {
            char const c = s[i];

            // if this char is in the window,
            // means that we have duplicated char
            if (window.contains(c)) {
                // only move left index if the index of duplicated char is greater than left index
                if (window[c] >= left) {
                    // move left index over the duplicated char
                    left = window[c] + 1;
                }
            }

            // stores char and index in the window
            window[c] = i;

            // make sure the result is always the longest
            result = max(result, i - left + 1);
        }

        return result;
    }
};
