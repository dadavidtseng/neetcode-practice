class Solution:
    def checkInclusion(self, s1: str, s2: str) -> bool:
        s1_size = len(s1)
        s2_size = len(s2)

        if s1_size > s2_size:
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

            if i >= s1_size:
                left = s2[i - s1_size]
                if left in freq:
                    if freq[left] == 0:
                        matched -= 1
                    freq[left] += 1

            if matched == needed:
                return True

        return False
