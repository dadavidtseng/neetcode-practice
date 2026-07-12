"""
Understanding:
Given "pattern" and "s", find out if s follows the same pattern as pattern
pattern: "abba", s: "dog cat cat dog", return true
pattern: "abba", s: "dog cat cat fish", return false
pattern: "abbc", s: "dog cat cat fish", return true

Planning:
pattern: 0110, s: 0 1 1 0
Hash map to store word and index and compare if the value is the same
pattern: {
    a: {0, 3},
    b: {1, 2}
}
s: {
    dog: {0, 3}, 
    cat: {1, 2}
}
"""

class Solution:
    def wordPattern(self, pattern: str, s: str) -> bool:
        # Create hash map for pattern and s
        pattern_map = {}
        word_map = {}
        word = s.split()

        if len(word)!=len(pattern):
            return False

        # Iterate through pattern and s to store the word and its index
        for idx, value in enumerate(zip(pattern, word)):
            if value[0] not in pattern_map:
                pattern_map[value[0]] = []
            pattern_map[value[0]].append(idx)

            if value[1] not in word_map:
                word_map[value[1]] = []
            word_map[value[1]].append(idx)
            
        # Return true if they match, return false otherwise 
        return list(pattern_map.values()) == list(word_map.values())
        