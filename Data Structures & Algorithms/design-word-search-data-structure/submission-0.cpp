class WordDictionary {
   public:
    WordDictionary() = default;

    void addWord(string word) {
        // current node in trie
        WordDictionary* node = this;

        // iterate through the word string
        for (int i = 0; i < static_cast<int>(word.length()); i++) {
            int const idx = word[i] - 'a';

            // if next node is empty
            if (node->children[idx] == nullptr) {
                // create a new node
                node->children[idx] = new WordDictionary();
            }

            // advance to next node
            node = node->children[idx];
        }

        // we've finished inserting the nodes
        node->isEnd = true;
    }

    bool search(string word) { return searchFrom(word, 0, this); }

    //------------------------------------------------------------------------------------------------
    /// @param word the word that we're trying to search
    /// @param i the index to track current character in the word
    /// @param node the node in the trie
    /// @return true if the search succeeded
    //------------------------------------------------------------------------------------------------
    bool searchFrom(string const& word, size_t const i, WordDictionary const* node) {
        // we've reached the end of the word
        // return true if current node is the end
        if (i == word.length()) {
            return node->isEnd;
        }

        // if this character(word[i]) is '.'
        if (word[i] == '.') {
            // iterate through all 26 children
            for (int j = 0; j < 26; j++) {
                // continue if this node's children doesn't exist
                if (node->children[j] == nullptr) {
                    continue;
                }

                // recursive call for advancing to the next character in word
                // while passing in the current node
                if (searchFrom(word, i + 1, node->children[j])) {
                    // return true when successfully searched,
                    // otherwise, keep looping
                    return true;
                }
            }
        }
        // if it's a normal character
        else {
            // convert the character to the value in trie node
            int const c = word[i] - 'a';

            // return false if this node doesn't exist
            if (node->children[c] == nullptr) {
                return false;
            }

            // recursive call for advancing to the next character in word
            // while passing in the current node
            return searchFrom(word, i + 1, node->children[c]);
        }

        // return false if we've never reached the end of the word after the dfs
        return false;
    }

    WordDictionary* children[26] = {nullptr};
    bool isEnd = false;
};
