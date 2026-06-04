class Solution {
   public:
    bool isValidSudoku(vector<vector<char>>& board) {
        unordered_set<char> rowSet[9];
        unordered_set<char> colSet[9];
        unordered_set<char> boxSet[9];

        for (int row = 0; row < 9; ++row) {
            for (int col = 0; col < 9; ++col) {
                char c = board[row][col];

                if (c == '.') {
                    continue;
                }

                int const boxIdx = (row / 3) * 3 + col / 3;

                if (rowSet[row].contains(c) || colSet[col].contains(c) ||
                    boxSet[boxIdx].contains(c)) {
                    return false;
                }

                rowSet[row].insert(c);
                colSet[col].insert(c);
                boxSet[boxIdx].insert(c);
            }
        }

        return true;
    }
};
