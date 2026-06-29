class Solution:
    def maxSlidingWindow(self, nums: List[int], k: int) -> List[int]:
        result = []
        left = 0
        heap = []

        for idx, val in enumerate(nums):
            heapq.heappush(heap, (-val, idx))

            if len(heap) >= k:
                while heap[0][1] < left:
                    heapq.heappop(heap)
                result.append(-heap[0][0])
                left += 1

        return result
