class Solution:
    def checkInclusion(self, s1: str, s2: str) -> bool:
        if len(s1) > len(s2):
            return False

        freq = {}

        for c in s1:
            freq[c] = freq.get(c, 0) + 1

        matched = 0
        needed = len(freq)

        for i, c in enumerate(s2):
            if c in freq:
                freq[c] -= 1
                if freq[c] == 0:
                    matched += 1

            if i >= len(s1):
                left = s2[i - len(s1)]
                if left in freq:
                    if freq[left] == 0:
                        matched -= 1
                    freq[left] += 1

            if matched == needed:
                return True

        return False
