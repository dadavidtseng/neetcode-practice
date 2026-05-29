class Solution {
   public:
    bool exist(vector<vector<char>>& board, string word) {
        // iterate through each cell on the board to start backtracking
        // each cell has four directions when doing backtracking
        for (int i = 0; i < static_cast<int>(board.size()); ++i) {
            for (int j = 0; j < static_cast<int>(board[0].size()); ++j) {
                // if any of the backtracking is true, return true early
                if (backtrack(board, word, i, j, 0)) {
                    return true;
                }
            }
        }

        // return false if we've never found a match
        return false;
    }

    bool backtrack(vector<vector<char>>& board, string const& word, int const row, int const col,
                   int const currentIndex) {
        // return true if we've found every character in the word
        if (currentIndex == static_cast<int>(word.size())) {
            return true;
        }

        // return false if current cell is out of bound
        // so that we don't go deeper in the wrong direction
        if (row < 0 || col < 0 || row >= static_cast<int>(board.size()) ||
            col >= static_cast<int>(board[0].size())) {
            return false;
        }

        // if we've got a match, keep going deeper in recursive call
        if (board[row][col] == word[currentIndex]) {
            // temporarily marks the current cell's character before we go deeper,
            // so that we don't check the duplicated cell
            char const temp = board[row][col];
            board[row][col] = '#';

            // up, down, left, right
            if (backtrack(board, word, row - 1, col, currentIndex + 1) ||
                backtrack(board, word, row + 1, col, currentIndex + 1) ||
                backtrack(board, word, row, col - 1, currentIndex + 1) ||
                backtrack(board, word, row, col + 1, currentIndex + 1)) {
                return true;
            }

            // restore the cell that we've marked
            board[row][col] = temp;
        }

        // return false if this is not a match
        return false;
    }
};
