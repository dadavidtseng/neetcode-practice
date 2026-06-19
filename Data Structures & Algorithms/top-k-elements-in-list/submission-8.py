class Solution:
    def topKFrequent(self, nums: List[int], k: int) -> List[int]:
        m = defaultdict(int)
        result = []
        heapq.heapify(nums)

        for num in nums:
            m[num] += 1

        heap = []
        
        for key, freq in m.items():
            heapq.heappush(heap, (freq, key))
            
            if len(heap) > k:
                heapq.heappop(heap)

        for i in heap:
            result.append(i[1])

        return result