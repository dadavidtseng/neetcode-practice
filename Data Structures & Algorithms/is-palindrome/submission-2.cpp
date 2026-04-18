class Solution {
public:
    bool isPalindrome(string s) {
        // remove space
        // lower case every char
        // one pointer from start
        // one pointer from end
        // the absolute value of indexes of these two pointer is 0 or 1 -> true

        string newS;
        newS.reserve(s.size());  // one allocation instead of log(n) re-allocs

        for(int i = 0; i < s.size(); i++)
        {
            if((s[i] >= '0' && s[i] <= '9') ||
            (s[i] >= 'A' && s[i] <= 'Z') ||
            (s[i] >= 'a' && s[i] <= 'z') )
            {
                newS += std::tolower((unsigned char)s[i]);
            }
        }

        for(int j = 0; j < (int)newS.size() / 2; j++)
        {
            int k = newS.size() - 1 - j;
            if(newS[j] != newS[k])
            {
                return false;
            }
        }

        return true;
    }
};