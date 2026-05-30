/*
// Definition for a Node.
class Node {
public:
    int val;
    vector<Node*> neighbors;
    Node() {
        val = 0;
        neighbors = vector<Node*>();
    }
    Node(int _val) {
        val = _val;
        neighbors = vector<Node*>();
    }
    Node(int _val, vector<Node*> _neighbors) {
        val = _val;
        neighbors = _neighbors;
    }
};
*/

class Solution {
   public:
    Node* cloneGraph(Node* node) {
        unordered_map<int, Node*>
            visited;     // a lookup map for node's value and a pointer to that node
        queue<Node*> q;  // a queue for traversing the graph

        // return empty visited map if this node is nullptr
        if (node == nullptr) {
            return nullptr;
        }

        // start from the root node
        q.push(node);
        Node* clone = new Node(node->val);
        visited[clone->val] = clone;

        // exit when we've exhausted the graph
        while (!q.empty()) {
            // cache the current node from the queue
            // and remove it from the queue
            Node const* cur = q.front();
            q.pop();

            // iterate through current node's neighbors
            for (int i = 0; i < static_cast<int>(cur->neighbors.size()); ++i) {
                Node* neighbor = cur->neighbors[i];

                // if we haven't visited this neighbor node
                // 1. store it into visited map
                // 2. push it into the queue for next call
                if (!visited.contains(neighbor->val)) {
                    Node* cloneNeighbor = new Node(neighbor->val);

                    visited[cloneNeighbor->val] = cloneNeighbor;
                    q.push(neighbor);
                }

                visited[cur->val]->neighbors.push_back(visited[neighbor->val]);
            }
        }

        return clone;
    }
};
