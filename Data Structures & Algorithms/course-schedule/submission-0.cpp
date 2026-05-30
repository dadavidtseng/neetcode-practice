class Solution {
   public:
    bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {
        // Create adjacency list
        vector<vector<int>> node(numCourses);

        // Iterate through the prerequisites([[1,0],[0,1]])
        // Connect the prerequisite(neighbor node) with course(node)
        for (int i = 0; i < static_cast<int>(prerequisites.size()); ++i) {
            int const course = prerequisites[i][0];
            int const prerequisite = prerequisites[i][1];

            node[course].push_back(prerequisite);
        }

        // Create the state for every nodes
        // 0=unvisited, 1=in-progress, 2=done
        vector state(numCourses, 0);

        // Iterate through every courses
        // return false if any cycle is found
        // Notice that we're using numCourses here instead of prerequisites
        // because the prerequisites.size() might be greater or equal than numCourses
        for (int i = 0; i < numCourses; ++i) {
            if (dfs(node, state, i)) {
                return false;
            }
        }

        // return true if no cycle was found
        return true;
    }

    //------------------------------------------------------------------------------------------------
    /// @brief DFS for finding cycle in the graph
    /// @param node Current node(course) in the recursive call
    /// @param state 0=unvisited, 1=in-progress, 2=done
    /// @param i Course index for state and node look up
    /// @return true if there's a cycle
    //------------------------------------------------------------------------------------------------
    bool dfs(vector<vector<int>> const& node, vector<int>& state, int i) {
        // return true if this visiting node is still in-progress,
        // means that we've found a cycle
        if (state[i] == 1) {
            return true;
        }

        // return false if this visiting node is done,
        // means that we're safe to take it
        if (state[i] == 2) {
            return false;
        }

        // Mark this node's state as in-progress since state[i] is 0
        state[i] = 1;

        // Iterate through this course(node)'s every prerequisites(neighbor nodes)
        // return true if any cycle was found
        for (int j = 0; j < static_cast<int>(node[i].size()); ++j) {
            if (dfs(node, state, node[i][j])) {
                return true;
            }
        }

        // Mark this course(node)'s state as completed since we didn't find any cycle
        state[i] = 2;

        return false;
    }
};
