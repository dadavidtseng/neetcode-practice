class Solution {
   public:
    bool isValidSudoku(vector<vector<char>>& board) {
        unordered_set<char> s;

        for (char i = 0; i < 9; ++i) {
            for (char j = 0; j < 9; ++j) {
                if (board[i][j] == '.') {
                    continue;
                }

                if (!s.contains(board[i][j])) {
                    s.insert(board[i][j]);

                    continue;
                }

                return false;
            }

            s.clear();
        }

        for (char i = 0; i < 9; ++i) {
            for (char j = 0; j < 9; ++j) {
                if (board[j][i] == '.') {
                    continue;
                }

                if (!s.contains(board[j][i])) {
                    s.insert(board[j][i]);

                    continue;
                }

                return false;
            }

            s.clear();
        }

        for (char i = 0; i < 9; i += 3) {
            for (char j = 0; j < 9; j += 3) {
                for (char x = i; x < i + 3; ++x) {
                    for (char y = j; y < j + 3; ++y) {
                        if (board[x][y] == '.') {
                            continue;
                        }

                        if (!s.contains(board[x][y])) {
                            s.insert(board[x][y]);
                            continue;
                        }

                        return false;
                    }
                }

                s.clear();
            }
        }

        return true;
    }
};
