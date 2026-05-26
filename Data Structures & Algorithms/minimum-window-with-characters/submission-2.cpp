class Solution {
   public:
    string minWindow(string s, string t) {
        int window[128] = {};  // stores char and frequency
        int tWindow[128] = {};
        int tDistinct = 0;
        int left = 0;
        int matched = 0;
        int minStart = 0;
        int minLength = INT_MAX;

        // build the tWindow from t
        for (int i = 0; i < static_cast<int>(t.length()); ++i) {
            if (tWindow[static_cast<unsigned char>(t[i])] == 0) {
                tDistinct++;
            }
            tWindow[static_cast<unsigned char>(t[i])]++;
        }

        // use slide window to move from left to right
        for (int i = 0; i < static_cast<int>(s.length()); ++i) {
            unsigned char c = s[i];

            // add s[i] to window
            window[c]++;

            // if current char is in tWindow and is within that char count in tWindow, and match +1
            if (tWindow[c] > 0 && window[c] == tWindow[c]) {
                matched++;
            }

            // while match == tWindow.size(), remove s[left] from window, and move left +1
            while (matched == tDistinct) {
                // update minStart and minLength if windowLength is smaller than minLength
                int const windowLength = i - left + 1;

                if (windowLength < minLength) {
                    minStart = left;
                    minLength = windowLength;
                }

                unsigned char cLeft = s[left];

                // if that s[left] is in tWindow, matched -1
                if (tWindow[cLeft] > 0 && window[cLeft] == tWindow[cLeft]) {
                    matched--;
                }

                // Shrink window and advance left
                window[cLeft]--;
                left++;
            }
        }

        return minLength == INT_MAX ? "" : s.substr(minStart, minLength);
    }
};
