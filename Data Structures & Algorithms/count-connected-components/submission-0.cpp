class Solution {
   public:
    int countComponents(int n, vector<vector<int>>& edges) {
        vector<int> parent(n);
        vector rank(n, 0);
        int result = n;

        for (int i = 0; i < n; ++i) {
            parent[i] = i;
        }

        function<int(int)> find = [&](int const x) {
            if (parent[x] != x) {
                parent[x] = find(parent[x]);
            }

            return parent[x];
        };

        for (int i = 0; i < static_cast<int>(edges.size()); ++i) {
            int const rootA = find(edges[i][0]);
            int const rootB = find(edges[i][1]);

            if (rootA == rootB) {
                continue;
            }

            if (rank[rootA] < rank[rootB]) {
                parent[rootA] = rootB;
            } else if (rank[rootA] > rank[rootB]) {
                parent[rootB] = rootA;
            } else {
                parent[rootB] = rootA;
                ++rank[rootA];
            }

            --result;
        }

        return result;
    }
};
