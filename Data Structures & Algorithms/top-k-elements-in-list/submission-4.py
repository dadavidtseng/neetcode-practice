class Solution:
    def topKFrequent(self, nums: List[int], k: int) -> List[int]:
        m = defaultdict(int)
        result = []

        for n in nums:
            m[n] += 1

        m = sorted(m, key=lambda x: m[x])

        for i in range(len(m) - 1, -1, -1):
            if k == 0:
                return result
            result.append(m[i])
            k -= 1
        return result