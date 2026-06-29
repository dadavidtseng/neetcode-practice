class Solution {
   public:
    bool isValid(string s) {
        while (true) {
            size_t pos;

            if ((pos = s.find("()")) != string::npos || (pos = s.find("[]")) != string::npos ||
                (pos = s.find("{}")) != string::npos) {
                s.erase(pos, 2);
                continue;
            }
            break;
        }

        return s.empty();
    }
};
