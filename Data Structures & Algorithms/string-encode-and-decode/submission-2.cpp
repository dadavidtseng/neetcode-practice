class Solution {
public:

    string encode(vector<string>& strs) {
// Return empty string if strs is empty
        if (strs.empty())
        {
            return "";
        }

        string    result;
        const int strsSize = static_cast<int>(strs.size());

        // Iterate through strs and store each strs[i]'s size in result
        for (int i = 0; i < strsSize; ++i)
        {
            result.append(to_string(strs[i].size()));
            result.append(".");
        }

        result.append("#");

        // Iterate through strs and store each strs[i] in result
        for (int i = 0; i < strsSize; ++i)
        {
            result += strs[i];
        }

        return result;
    }

    vector<string> decode(string s) {
// Return empty if s is empty
        if (s.empty())
        {
            return {};
        }

        vector<int>    sizes;
        vector<string> result;
        int            i = 0;

        while (s[i] != '#')
        {
            int j = i;
            while (s[j] != '.')
            {
                j++;
            }
            sizes.push_back(stoi(s.substr(i, j - i)));
            i = j + 1;
        }
        i++;

        for (int sz : sizes)
        {
            result.push_back(s.substr(i, sz));
            i += sz;
        }
        return result;
    }
};
