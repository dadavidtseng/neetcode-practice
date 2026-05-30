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
            cloned;      // a lookup map for node's value and a pointer to that node
        queue<Node*> q;  // a queue for traversing the graph

        // return empty graph if this node is nullptr
        if (node == nullptr) {
            return nullptr;
        }

        // 1. Push the original root node into queue to for while loop later
        // 2. Create the clone node
        // 3. Store the clone node into cloned map
        q.push(node);
        Node* clone = new Node(node->val);
        cloned[clone->val] = clone;

        // exit when we've exhausted the graph
        while (!q.empty()) {
            // cache the current node from the queue
            // and remove it from the queue
            Node const* cur = q.front();
            q.pop();

            // iterate through original current node's neighbors
            for (int i = 0; i < static_cast<int>(cur->neighbors.size()); ++i) {
                Node* neighbor = cur->neighbors[i];

                // if we haven't cloned this neighbor node in the cloned map
                // 1. Create a cloneNeighbor node using original neighbor's value
                // 2. Store cloneNeighbor into cloned map
                // 3. Push neighbor into the queue for next call
                // Note that cloned map is for cloning node
                if (!cloned.contains(neighbor->val)) {
                    Node* cloneNeighbor = new Node(neighbor->val);

                    cloned[cloneNeighbor->val] = cloneNeighbor;
                    q.push(neighbor);
                }

                // 4. Store the cloned neighbor node into cloned node's neighbors
                cloned[cur->val]->neighbors.push_back(cloned[neighbor->val]);
            }
        }

        return clone;
    }
};
