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

        // we've finished inserting the nodes
        node->isEnd = true;
    }

    Trie* children[26] = {nullptr};
    bool isEnd = false;
};

//----------------------------------------------------------------------------------------------------
class Solution {
   public:
    static vector<string> findWords(vector<vector<char>>& board, vector<string>& words) {
        vector<string> result;
        string path;  // a container that stores char for result
        Trie* trie = new Trie();

        // insert all words into trie
        for (int i = 0; i < static_cast<int>(words.size()); ++i) {
            trie->insert(words[i]);
        }

        // iterate through all cells in the board and start backtracking
        for (int i = 0; i < static_cast<int>(board.size()); ++i) {
            for (int j = 0; j < static_cast<int>(board[i].size()); ++j) {
                // return early if we've found everything
                if (result.size() == words.size()) {
                    return result;
                }

                backtrack(board, i, j, trie, path, result);
            }
        }

        return result;
    }

    static void backtrack(vector<vector<char>>& board, int const row, int const col, Trie* trie,
                          string& path, vector<string>& result) {
        // return if current cell is out of bound
        // so that we don't go deeper in the wrong direction
        if (row < 0 || col < 0 || row >= static_cast<int>(board.size()) ||
            col >= static_cast<int>(board[0].size())) {
            return;
        }

        // current char in the recursive call
        char& c = board[row][col];

        // return if current cell is '#'
        if (c == '#') {
            return;
        }

        // current index in the recursive call for checking the trie
        int const idx = c - 'a';

        // if we've got a match, keep going deeper in recursive call
        if (trie->children[idx] != nullptr) {
            Trie* child = trie->children[idx];
            path.push_back(c);

            // if we've found every character in the word
            // push the word(found characters) into result
            // and mark this trie node as false so that it can be deleted in next recursive call
            if (child->isEnd) {
                result.push_back(path);
                child->isEnd = false;
            }

            // temporarily marks the current cell's character before we go deeper,
            // so that we don't check the duplicated cell
            char const temp = c;
            c = '#';

            // up, down, left, right
            backtrack(board, row - 1, col, child, path, result);
            backtrack(board, row + 1, col, child, path, result);
            backtrack(board, row, col - 1, child, path, result);
            backtrack(board, row, col + 1, child, path, result);

            path.pop_back();

            // prevents checking the same word in the trie
            bool hasChildren = false;

            for (int k = 0; k < 26; ++k) {
                if (child->children[k] != nullptr) {
                    hasChildren = true;
                    break;
                }
            }

            // if this trie node doesn't have children, and it's been found
            // delete that node and set it to nullptr
            // this is pruning the recursive call for finding duplicated words by deleting the trie
            // node
            if (!hasChildren && !child->isEnd) {
                delete child;
                trie->children[temp - 'a'] = nullptr;
            }

            // restore the cell that we've marked
            c = temp;
        }
    }
};
