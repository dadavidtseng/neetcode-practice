class Node:
    def __init__(self, key = 0, value = 0) -> None:
        self.key = key
        self.value = value
        self.prev: 'Node' = self
        self.next: 'Node' = self

class LRUCache:
    def __init__(self, capacity: int):
        self.capacity = capacity
        self.cache = {}
        self.left = Node()
        self.right = Node()
        self.left.next = self.right
        self.right.prev = self.left

    def _remove(self, node) -> None:
        node.prev.next = node.next
        node.next.prev = node.prev

    def _add_to_head(self, node) -> None:
        right = self.right
        prev_right = self.right.prev

        node.prev = prev_right
        node.next = right
        right.prev = node
        prev_right.next = node

    def get(self, key: int) -> int:
        if key in self.cache:
            self._remove(self.cache[key])
            self._add_to_head(self.cache[key])
            return self.cache[key].value

        return -1

    def put(self, key: int, value: int) -> None:
        if key in self.cache:
            node = self.cache[key]
            node.value = value
            self._remove(node)
            self._add_to_head(node)
            return

        self.cache[key] = Node(key, value)
        self._add_to_head(self.cache[key])

        if len(self.cache) > self.capacity:
            lru = self.left.next
            self._remove(lru)
            del self.cache[lru.key]
