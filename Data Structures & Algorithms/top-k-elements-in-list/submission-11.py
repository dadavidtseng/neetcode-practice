class Solution:
    def topKFrequent(self, nums: List[int], k: int) -> List[int]:
        m: defaultdict[int, int] = defaultdict(int)
        result: List[int] = []

        for num in nums:
            m[num] += 1

        freq: List[List[int]] = [[] for _ in range(len(nums) + 1)]

        for key, value in m.items():
            freq[value].append(key)

        for i in range(len(nums), 0, -1):
            for j in freq[i]:
                result.append(j)
                if len(result) == k:
                    return result