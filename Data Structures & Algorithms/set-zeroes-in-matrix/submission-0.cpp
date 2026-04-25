class Solution {
   public:
    void setZeroes(vector<vector<int>>& matrix) {
        int m = matrix.size();
        int n = matrix[0].size();

        vector<bool> rol(m, false);
        vector<bool> col(n, false);

        for (int r = 0; r < m; r++) {
            for (int c = 0; c < n; c++) {
                if (matrix[r][c] == 0) {
                    rol[r] = true;
                    col[c] = true;
                }
            }
        }

        for (int r = 0; r < m; r++) {
            for (int c = 0; c < n; c++) {
                if (rol[r] == true || col[c] == true) {
                    matrix[r][c] = 0;
                }
            }
        }
    }
};
