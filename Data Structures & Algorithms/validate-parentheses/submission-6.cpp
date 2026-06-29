class Solution {
   public:
    bool isValid(string s) {
        // Construct the pair for look up
        unordered_map<char, char> pairs{{'(', ')'}, {'[', ']'}, {'{', '}'}};

        stack<char> stack;

        // Iterate through s
        for (const char& c : s) {
            // Push pairs[c](right bracket) into stack when encountering c(left bracket)
            if (pairs.contains(c)) {
                stack.push(pairs[c]);
            }
            // When encountering right bracket,
            // check if we've stored in stack before
            else {
                // Return false if the stack is empty or not the right bracket
                if (stack.empty() || stack.top() != c) {
                    return false;
                }

                // We found a match, close the brackets by removing them from the stack
                stack.pop();
            }
        }

        // Return true if everything has been removed
        return stack.empty();
    }
};
