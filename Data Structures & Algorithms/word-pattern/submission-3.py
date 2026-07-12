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

        # Iterate through pattern and s to store the word and its index
        for i in range(len(pattern)):
            if pattern[i] not in pattern_map:
                pattern_map[pattern[i]] = []
            pattern_map[pattern[i]].append(i)
        
        # For s, everytime we encounter a space, mean it's a new word
        for i in range(len(word)):
            if word[i] not in word_map:
                word_map[word[i]] = []
            word_map[word[i]].append(i)
            
        # Return true if they match, return false otherwise 
        return list(pattern_map.values()) == list(word_map.values())
        