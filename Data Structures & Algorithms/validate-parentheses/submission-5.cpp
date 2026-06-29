class Solution {
   public:
    bool isValid(string s) {
        while (true) {
            size_t pos;

            // Remove the brackets if it's in the string

            if ((pos = s.find("()")) != string::npos || (pos = s.find("[]")) != string::npos ||
                (pos = s.find("{}")) != string::npos) {
                s.erase(pos, 2);
            }
            // Exit the loop when we couldn't find anything anymore
            else {
                break;
            }
        }

        // Return true if everything has been removed
        return s.empty();
    }
};
