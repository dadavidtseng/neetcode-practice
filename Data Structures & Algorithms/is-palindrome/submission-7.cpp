class Solution {
   public:
    bool isPalindrome(string s) {
        int L = 0;
        int R = static_cast<int>(s.length()) - 1;

        // Return true is the character is a letter or a digit
        auto isAlphaNum = [](const char c) -> bool {
            return ('A' <= c && c <= 'Z') || ('a' <= c && c <= 'z') || ('0' <= c && c <= '9');
        };

        // Exit the while loop when L/R pointers cross
        // 1. Advance L pointer when L/R pointers don't cross and s[L] is not alphanumeric
        // 2. Decrement R pointer when L/R pointers don't cross and s[R] is not alphanumeric
        // 3. Return false if lowercased s[L] and s[R] are not equal
        // 4. Move L/R pointers toward the center
        while (L < R) {
            while (L < R && !isAlphaNum(s[L])) {
                L++;
            }
            while (L < R && !isAlphaNum(s[R])) {
                R--;
            }
            if (tolower(s[L]) != tolower(s[R])) {
                return false;
            }
            L++;
            R--;
        }
        // Return true if no mismatch was found while moving L/R pointers
        return true;
    }
};
