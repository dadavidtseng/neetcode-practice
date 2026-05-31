class Solution {
   public:
    string foreignDictionary(vector<string>& words) {
        string result;
        vector<vector<char>> graph(26);

        for (int i = 0; i < words.size() - 1; ++i) {
            bool found = false;

            for (int j = 0; j < min(words[i].size(), words[i + 1].size()); ++j) {
                char a = words[i][j];
                char b = words[i + 1][j];

                if (a != b) {
                    found = true;
                    graph[a - 'a'].push_back(b);
                    break;
                }
            }

            if (!found && words[i].size() > words[i + 1].size()) {
                result.clear();

                return result;
            }
        }

        unordered_map<char, int> charInDegree;

        for (int i = 0; i < words.size(); ++i) {
            for (int j = 0; j < words[i].size(); ++j) {
                charInDegree[words[i][j]] = 0;
            }
        }

        for (int i = 0; i < graph.size(); ++i) {
            for (int j = 0; j < graph[i].size(); ++j) {
                charInDegree[graph[i][j]]++;
            }
        }

        queue<char> q;

        for (auto& [c, inDegree] : charInDegree) {
            if (inDegree == 0) {
                q.push(c);
            }
        }

        while (!q.empty()) {
            char front = q.front();
            int idx = front - 'a';
            q.pop();
            result += front;

            for (int i = 0; i < graph[idx].size(); ++i) {
                charInDegree[graph[idx][i]]--;

                if (charInDegree[graph[idx][i]] == 0) {
                    q.push(graph[idx][i]);
                }
            }
        }

        if (result.size() < charInDegree.size()) {
            result.clear();

            return result;
        }

        return result;
    }
};
