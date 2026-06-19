class Solution:
    def topKFrequent(self, nums: List[int], k: int) -> List[int]:
        m = defaultdict(int)
        result = []

        for num in nums:
            m[num] += 1
        
        for key, freq in m.items():
            heapq.heappush(result, (freq, key))
            
            if len(result) > k:
                heapq.heappop(result)

        return [item[1] for item in result]