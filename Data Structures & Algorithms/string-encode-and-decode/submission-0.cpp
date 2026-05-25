class Solution {
public:

    string encode(vector<string>& strs) {
string result;

        for (int i = 0; i < strs.size(); ++i)
        {
            result += to_string((int)strs[i].size());
            result += '#';
            result += strs[i];
        }

        return result;
    }

    vector<string> decode(string s) {
vector<string> result;
        string         temp;

        for (int i = 0; i < s.size(); ++i)
        {
            if (s[i] == '#')
            {
                int const number = stoi(temp);
                temp.clear();
                for (int j = i + 1; j < i + number + 1; ++j)
                {
                    temp.push_back(s[j]);
                }
                result.push_back(temp);
                temp.clear();
                i += number;
                continue;
            }

            temp.push_back(s[i]);
        }

        return result;
    }
};
