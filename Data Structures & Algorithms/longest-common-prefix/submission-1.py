"""
Understand:
Provided a list of string, return their longest common prefix.
strs[i] is made up of lowercase English letters if it is non-empty.

Ex1: ["bat", "bag", "bank", "band"], return "ba"

Match:
Tires, Array, String

Plan:
A brutal force solution would be trying out everything, starting from
"b", "ba" to "baXXX" to see how far we could go. But this would result
in a very bad time/space complexity...
"""


class Solution:
    def longestCommonPrefix(self, strs: List[str]) -> str:
        prefix = strs[0]

        for i in range(1, len(strs)):
            j = 0
            while j < min(len(prefix), len(strs[i])):
                if prefix[j] != strs[i][j]:
                    break
                j += 1
            prefix = prefix[:j]
        return prefix
