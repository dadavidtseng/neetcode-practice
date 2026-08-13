class Solution {
public:
    string minWindow(string s, string t) {
        // Return empty string if provided t is empty
        if (t.empty()) {
            return "";
        }

        // Create a frequency map for t
        unordered_map<char, int> freqT;

        for (const char c : t) {
            freqT[c]++;
        }

        unordered_map<char, int> window;
        int matched = 0;
        int target = static_cast<int>(freqT.size());
        int resultStartIdx = -1;
        int resultLength = INT_MAX;
        int L = 0;

        // Extend the window by moving its right pointer
        for (int R = 0; R < static_cast<int>(s.length()); ++R) {
            char cR = s[R];

            window[cR]++;

            // Increment matched if cR is in t and currnet window contains enough cR
            if (freqT[cR] > 0 && window[cR] == freqT[cR]) {
                matched++;
            }

            // Exit the while loop when this is not a valid window
            while (matched == target) {
                // update minStart and minLength if windowLength is smaller than minLength
                // this is for avoiding using substr in a while loop
                int const windowLength = R - L + 1;

                if (windowLength < resultLength) {
                    resultStartIdx = L;
                    
                    resultLength = min(resultLength, R - L + 1);
                }

                char const cL = s[L];

                // if that s[left] is in tWindow, matched -1
                if (freqT[cL] > 0 && window[cL] == freqT[cL]) {
                    matched--;
                }

                // Shrink window and advance left
                window[cL]--;
                L++;
            }
        }

        return resultLength == INT_MAX ? "" : s.substr(resultStartIdx, resultLength);
    }
};
