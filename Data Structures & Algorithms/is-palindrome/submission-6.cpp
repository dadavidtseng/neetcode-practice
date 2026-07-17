class Solution {
   public:
    bool isPalindrome(string s) {
        string newS = "";

        // Iterate through s;
        // Lowercase that character if it's alphanumeric to reconstruct s as newS
        for (int i = 0; i < static_cast<int>(s.length()); ++i) {
            if (isalnum(s[i])) {
                newS += static_cast<char>(tolower(s[i]));
            }
        }
        // Return true if newS equals to its reverse
        return newS == string(newS.rbegin(), newS.rend());
    }
};
