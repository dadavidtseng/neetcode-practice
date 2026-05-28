class PrefixTree {
   public:
    PrefixTree() = default;

    void insert(string word) {
        // current node in trie
        PrefixTree* node = this;

        // iterate through the word string
        for (int i = 0; i < static_cast<int>(word.length()); i++) {
            int const idx = word[i] - 'a';

            // if next node is empty
            if (node->children[idx] == nullptr) {
                // create a new node
                node->children[idx] = new PrefixTree();
            }

            // advance to next node
            node = node->children[idx];
        }

        // we've finished inserting the nodes
        node->isEnd = true;
    }

    bool search(string word) {
        PrefixTree const* node = traverse(word);

        return node == nullptr ? false : node->isEnd;
    }

    bool startsWith(string prefix) { return traverse(prefix) != nullptr; }

    PrefixTree* traverse(string const& word) {
        // current node in trie
        PrefixTree* node = this;

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

    PrefixTree* children[26] = {nullptr};
    bool isEnd = false;
};
