class Solution {
   public:
    vector<vector<int>> pacificAtlantic(vector<vector<int>>& heights) {
        vector<vector<int>> result;
        vector topLeft(heights.size(), vector(heights[0].size(), false));
        vector bottomRight(heights.size(), vector(heights[0].size(), false));

        for (int i = 0; i < heights.size(); ++i) {
            dfs(heights, i, 0, heights[i][0], topLeft);  // left
            dfs(heights, i, heights[0].size() - 1, heights[i][heights[0].size() - 1],
                bottomRight);  // right
        }

        for (int j = 0; j < heights[0].size(); ++j) {
            dfs(heights, 0, j, heights[0][j], topLeft);  // top
            dfs(heights, heights.size() - 1, j, heights[heights.size() - 1][j],
                bottomRight);  // bottom
        }

        for (int i = 0; i < heights.size(); ++i) {
            for (int j = 0; j < heights[0].size(); ++j) {
                if (topLeft[i][j] && bottomRight[i][j]) {
                    result.push_back({i, j});
                }
            }
        }

        return result;
    }

    void dfs(vector<vector<int>>& heights, int row, int col, int previous,
             vector<vector<bool>>& hasVisited) {
        if (row < 0 || col < 0 || row >= heights.size() || col >= heights[0].size()) {
            return;
        }

        if (heights[row][col] < previous) {
            return;
        }

        if (hasVisited[row][col]) {
            return;
        }

        hasVisited[row][col] = true;

        dfs(heights, row + 1, col, heights[row][col], hasVisited);
        dfs(heights, row - 1, col, heights[row][col], hasVisited);
        dfs(heights, row, col + 1, heights[row][col], hasVisited);
        dfs(heights, row, col - 1, heights[row][col], hasVisited);
    }
};
