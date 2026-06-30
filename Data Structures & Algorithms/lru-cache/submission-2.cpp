class Node {
   public:
    explicit Node(const int _key, const int _value) : key(_key), value(_value) {}

    int key = 0;
    int value = 0;
    Node* prev = nullptr;
    Node* next = nullptr;
};

class LRUCache {
   public:
    explicit LRUCache(const int _capacity) {
        capacity = _capacity;
        left = new Node(0, 0);
        right = new Node(0, 0);

        left->next = right;
        right->prev = left;
    }

    int get(const int key) {
        if (cache.contains(key)) {
            _remove(cache[key]);
            _add_to_head(cache[key]);
            return cache[key]->value;
        }

        return -1;
    }

    void put(const int key, const int value) {
        if (cache.contains(key)) {
            Node* node = cache[key];
            node->value = value;
            _remove(node);
            _add_to_head(node);
            return;
        }

        Node* newNode = new Node(key, value);
        cache[key] = newNode;
        _add_to_head(newNode);

        if (static_cast<int>(cache.size()) > capacity) {
            Node* lru = left->next;
            _remove(lru);
            cache.erase(lru->key);
            delete lru;
        }
    }

   private:
    void _remove(const Node* node) {
        node->prev->next = node->next;
        node->next->prev = node->prev;
    }

    void _add_to_head(Node* node) {
        Node* _right = right;
        Node* prev_right = right->prev;

        node->prev = prev_right;
        node->next = right;
        _right->prev = node;
        prev_right->next = node;
    }

    int capacity;
    unordered_map<int, Node*> cache;
    Node* left = nullptr;
    Node* right = nullptr;
};