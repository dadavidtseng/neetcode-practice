class Solution:
    def checkInclusion(self, s1: str, s2: str) -> bool:
        s1_size = len(s1)
        s2_size = len(s2)

        if s1_size > s2_size:
            return False
        
        freq = [0] * 26

        for c in s1:
            freq[ord(c) - ord('a')] += 1

        matched = 0
        needed = sum(1 for f in freq if f > 0)

        for i, c in enumerate(s2):
            idx = ord(c) - ord('a')
            freq[idx] -= 1
            if freq[idx] == 0:
                matched += 1
            
            if i >= s1_size:
                left_idx = ord(s2[i - s1_size]) - ord('a')
                if freq[left_idx] == 0:
                    matched -= 1
                freq[left_idx] += 1

            if matched == needed:
                return True
                                
        return False
