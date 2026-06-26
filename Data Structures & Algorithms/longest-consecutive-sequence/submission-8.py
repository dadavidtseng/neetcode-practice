class Solution:
    def longestConsecutive(self, nums: List[int]) -> int:
        result = 0
        m = defaultdict(int)

        for num in nums:
            if not m[num]:
                m[num] = m[num-1] + m[num+1] + 1
                m[num-m[num-1]]=m[num]
                m[num+m[num+1]]=m[num]
                result = max(result, m[num])
        return result
