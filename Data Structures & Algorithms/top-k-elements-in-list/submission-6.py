class Solution:
    def topKFrequent(self, nums: List[int], k: int) -> List[int]:
        m = defaultdict(int)
        result = []

        for n in nums:
            m[n] += 1

        m = sorted(m, key=lambda x: m[x], reverse=True)

        return m[:k]