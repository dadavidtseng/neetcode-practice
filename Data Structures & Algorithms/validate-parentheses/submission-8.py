class Solution:
    def isValid(self, s: str) -> bool:
        # Construct the pair for look up
        pairs = {"(": ")", "[": "]", "{": "}"}
        stack = []

        # Iterate through s
        for c in s:
            # Push pairs[c](right bracket) into stack when encountering c(left bracket)
            if c in pairs:
                stack.append(pairs[c])
            # When encountering right bracket,
            # check if we've stored in stack before
            else:
                # Return false if the stack is empty or not the right bracket
                if not stack or stack[-1] != c:
                    return False
                # We found a match, close the brackets by removing them from the stack
                stack.pop()
        # Return true if everything has been removed
        return not stack
