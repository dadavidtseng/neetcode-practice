//----------------------------------------------------------------------------------------------------
class Trie {
   public:
    Trie() = default;

    void insert(string word) {
        // current node in trie
        Trie* node = this;

        // iterate through the word string
        for (int i = 0; i < static_cast<int>(word.length()); i++) {
            int const idx = word[i] - 'a';

            // if next node is empty
            if (node->children[idx] == nullptr) {
                // create a new node
                node->children[idx] = new Trie();
            }

            // advance to next node
            node = node->children[idx];
        }

        node->word = word;

        // we've finished inserting the nodes
        node->isEnd = true;
    }

    bool search(string word) {
        Trie const* node = traverse(word);

        return node == nullptr ? false : node->isEnd;
    }

    Trie* traverse(string const& word) {
        // current node in trie
        Trie* node = this;

        // iterate through the word string
        for (int i = 0; i < static_cast<int>(word.length()); i++) {
            int const idx = word[i] - 'a';

            // if next node is empty
            if (node->children[idx] == nullptr) {
                return nullptr;
            }

            // advance to next node
            node = node->children[idx];
        }
        return node;
    }

    Trie* children[26] = {nullptr};
    string word;
    bool isEnd = false;
};

//----------------------------------------------------------------------------------------------------
class Solution {
   public:
    static vector<string> findWords(vector<vector<char>>& board, vector<string>& words) {
        vector<string> result;
        Trie* trie = new Trie();

        for (int i = 0; i < static_cast<int>(words.size()); ++i) {
            trie->insert(words[i]);
        }

        for (int i = 0; i < static_cast<int>(board.size()); ++i) {
            for (int j = 0; j < static_cast<int>(board[i].size()); ++j) {
                backtrack(board, i, j, trie, result);
            }
        }

        return result;
    }

    static void backtrack(vector<vector<char>>& board, int const row, int const col, Trie* trie,
                          vector<string>& result) {
        // return true if we've found every character in the word
        if (trie->isEnd) {
            result.push_back(trie->word);
            trie->isEnd = false;
        }

        // return false if current cell is out of bound
        // so that we don't go deeper in the wrong direction
        if (row < 0 || col < 0 || row >= static_cast<int>(board.size()) ||
            col >= static_cast<int>(board[0].size())) {
            return;
        }

        if (board[row][col] == '#') {
            return;
        }

        // if we've got a match, keep going deeper in recursive call
        if (trie->children[board[row][col] - 'a']) {
            // temporarily marks the current cell's character before we go deeper,
            // so that we don't check the duplicated cell
            Trie* child = trie->children[board[row][col] - 'a'];
            char const temp = board[row][col];
            board[row][col] = '#';

            // up, down, left, right
            backtrack(board, row - 1, col, child, result);
            backtrack(board, row + 1, col, child, result);
            backtrack(board, row, col - 1, child, result);
            backtrack(board, row, col + 1, child, result);

            // restore the cell that we've marked
            board[row][col] = temp;
        }
    }
};