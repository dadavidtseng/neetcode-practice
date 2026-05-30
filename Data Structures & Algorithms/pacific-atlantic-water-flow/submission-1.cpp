class Solution {
   public:
    vector<vector<int>> pacificAtlantic(vector<vector<int>>& heights) {
        vector<vector<int>> result;
        int const row = static_cast<int>(heights.size());
        int const col = static_cast<int>(heights[0].size());

        vector topLeft(row, vector(col, false));
        vector bottomRight(row, vector(col, false));

        for (int i = 0; i < row; ++i) {
            dfs(heights, i, 0, heights[i][0], topLeft);                  // left
            dfs(heights, i, col - 1, heights[i][col - 1], bottomRight);  // right
        }

        for (int j = 0; j < col; ++j) {
            dfs(heights, 0, j, heights[0][j], topLeft);                  // top
            dfs(heights, row - 1, j, heights[row - 1][j], bottomRight);  // bottom
        }

        for (int i = 0; i < row; ++i) {
            for (int j = 0; j < col; ++j) {
                if (topLeft[i][j] && bottomRight[i][j]) {
                    result.push_back({i, j});
                }
            }
        }

        return result;
    }

    void dfs(vector<vector<int>>& heights, int const row, int const col, int const previousHeight,
             vector<vector<bool>>& hasVisited) {
        if (row < 0 || col < 0 || row >= static_cast<int>(heights.size()) ||
            col >= static_cast<int>(heights[0].size())) {
            return;
        }

        if (heights[row][col] < previousHeight) {
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
