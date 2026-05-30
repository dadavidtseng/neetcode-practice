class Solution {
   public:
    bool validTree(int n, vector<vector<int>>& edges) {
        vector<vector<int>> graph(n);
        vector visited(n, false);

        int const edgeSize = static_cast<int>(edges.size());

        if (edgeSize != n - 1) {
            return false;
        }

        for (int i = 0; i < edgeSize; ++i) {
            int node = edges[i][0];
            int neighbor = edges[i][1];

            graph[node].push_back(neighbor);
            graph[neighbor].push_back(node);
        }

        dfs(graph, visited, 0);

        for (int i = 0; i < n; ++i) {
            if (!visited[i]) {
                return false;
            }
        }

        return true;
    }

    void dfs(vector<vector<int>>& graph, vector<bool>& visited, int const i) {
        if (visited[i]) {
            return;
        }

        visited[i] = true;

        vector<int> const node = graph[i];

        for (int j = 0; j < static_cast<int>(node.size()); ++j) {
            int const neighbor = node[j];

            dfs(graph, visited, neighbor);
        }
    }
};
