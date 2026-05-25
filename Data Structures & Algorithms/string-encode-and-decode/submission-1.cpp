class Solution {
   public:
    string encode(vector<string>& strs) {
        string result;

        for (int i = 0; i < static_cast<int>(strs.size()); ++i) {
            result += to_string(static_cast<int>(strs[i].size()));
            result += '#';
            result += strs[i];
        }

        return result;
    }

    vector<string> decode(string s) {
        vector<string> result;
        string temp;

        for (int i = 0; i < static_cast<int>(s.size()); ++i) {
            if (s[i] == '#') {
                int const length = stoi(temp);
                temp.clear();  // clean up the number string

                for (int j = i + 1; j <= i + length; ++j) {
                    temp.push_back(s[j]);
                }

                result.push_back(temp);  // stores temp(the string we just read)
                temp.clear();            // clean up temp because we need to read the next number
                i += length;             // advance the iterator

                continue;
            }

            temp.push_back(s[i]);
        }

        return result;
    }
};
