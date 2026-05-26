class Solution {
   public:
    string minWindow(string s, string t) {
        unordered_map<char, int> window;  // stores char and frequency
        unordered_map<char, int> tWindow;
        int left = 0;
        int matched = 0;
        string result;

        // build the tWindow from t
        for (int i = 0; i < static_cast<int>(t.length()); ++i) {
            tWindow[t[i]]++;
        }

        // use slide window to move from left to right
        for (int i = 0; i < static_cast<int>(s.length()); ++i) {
            char c = s[i];

            // add s[i] to window
            window[c]++;

            // if current char is in tWindow and is within that char count in tWindow, and match +1
            if (tWindow.contains(c) && window[c] == tWindow[c]) {
                matched++;
            }

            // while match == tWindow.size(), move left +1, and remove s[left] from window
            while (matched == (int)tWindow.size()) {
                // update result if window.size() is smaller than result
                int windowLen = i - left + 1;
                if (result.empty() || windowLen < result.length()) {
                    result = s.substr(left, windowLen);
                }

                // if that s[left] is in tWindow, matched -1
                if (tWindow.contains(s[left]) && window[s[left]] == tWindow[s[left]]) {
                    matched--;
                }

                window[s[left]]--;
                left++;
            }
        }

        return result;
    }
};
