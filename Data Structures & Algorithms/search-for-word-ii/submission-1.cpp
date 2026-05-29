//----------------------------------------------------------------------------------------------------
class Trie
{
public:
    Trie() = default;

    void insert(string word)
    {
        // current node in trie
        Trie* node = this;

        // iterate through the word string
        for (int i = 0; i < static_cast<int>(word.length()); i++)
        {
            int const idx = word[i] - 'a';

            // if next node is empty
            if (node->children[idx] == nullptr)
            {
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
    bool  isEnd        = false;
};

//----------------------------------------------------------------------------------------------------
class Solution
{
public:
    static vector<string> findWords(vector<vector<char>>& board, vector<string>& words)
    {
        vector<string> result;
        string         path;
        Trie*          trie = new Trie();

        for (int i = 0; i < static_cast<int>(words.size()); ++i)
        {
            trie->insert(words[i]);
        }

        for (int i = 0; i < static_cast<int>(board.size()); ++i)
        {
            for (int j = 0; j < static_cast<int>(board[i].size()); ++j)
            {
                if (result.size() == words.size()) return result;

                backtrack(board, i, j, trie, path, result);
            }
        }

        return result;
    }

    static void backtrack(vector<vector<char>>& board, int const row, int const col, Trie* trie, string& path, vector<string>& result)
    {
        // return false if current cell is out of bound
        // so that we don't go deeper in the wrong direction
        if (row < 0 || col < 0 || row >= static_cast<int>(board.size()) || col >= static_cast<int>(board[0].size()))
        {
            return;
        }

        if (board[row][col] == '#')
        {
            return;
        }

        // if we've got a match, keep going deeper in recursive call
        if (trie->children[board[row][col] - 'a'])
        {
            // temporarily marks the current cell's character before we go deeper,
            // so that we don't check the duplicated cell
            Trie* child = trie->children[board[row][col] - 'a'];
            path.push_back(board[row][col]);

            // return true if we've found every character in the word
            if (child->isEnd)
            {
                result.push_back(path);
                child->isEnd = false;
            }

            char const temp = board[row][col];
            board[row][col] = '#';

            // up, down, left, right
            backtrack(board, row - 1, col, child, path, result);
            backtrack(board, row + 1, col, child, path, result);
            backtrack(board, row, col - 1, child, path, result);
            backtrack(board, row, col + 1, child, path, result);

            path.pop_back();

            bool hasChildren = false;
            for (int k = 0; k < 26; ++k)
            {
                if (child->children[k] != nullptr)
                {
                    hasChildren = true;
                    break;
                }
            }
            if (!hasChildren && !child->isEnd)
            {
                delete child;
                trie->children[temp - 'a'] = nullptr;
            }

            // restore the cell that we've marked
            board[row][col] = temp;
        }
    }
};