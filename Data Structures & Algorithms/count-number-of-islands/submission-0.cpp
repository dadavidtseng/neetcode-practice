class Solution {
   public:
    int numIslands(vector<vector<char>>& grid) {
        int result = 0;

        // iterate through every grids
        for (int i = 0; i < static_cast<int>(grid.size()); ++i) {
            for (int j = 0; j < static_cast<int>(grid[0].size()); ++j) {
                // only enter the recursive call if that grad is '1'
                // if we successfully pass the sinkIsland,
                // means that this is and island, hence result++
                if (grid[i][j] == '1') {
                    sinkIsland(grid, i, j);
                    result++;
                }
            }
        }

        return result;
    }

    void sinkIsland(vector<vector<char>>& grid, int row, int col) {
        // return if this grid is out of bound
        if (row < 0 || col < 0 || row >= static_cast<int>(grid.size()) ||
            col >= static_cast<int>(grid[0].size())) {
            return;
        }

        // return if this grid has already been visited
        // so that we don't count it again
        if (grid[row][col] == '0') {
            return;
        }

        // mark this grid as visited
        grid[row][col] = '0';

        sinkIsland(grid, row - 1, col);  // up
        sinkIsland(grid, row + 1, col);  // down
        sinkIsland(grid, row, col - 1);  // left
        sinkIsland(grid, row, col + 1);  // right
    }
};
