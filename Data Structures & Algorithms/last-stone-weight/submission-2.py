class Solution:
    def lastStoneWeight(self, stones: List[int]) -> int:
        max_heap = []

        for stone in stones:
            heapq.heappush(max_heap, -stone)

        while len(max_heap) > 1:
            a = -heapq.heappop(max_heap)
            b = -heapq.heappop(max_heap)

            if a == b:
                stones.remove(a)
                stones.remove(b)
            else:
                stones.remove(a)
                stones.remove(b)
                stones.append(abs(a - b))
                heapq.heappush(max_heap, -abs(a - b))

            if len(max_heap) == 0:
                return -abs(a - b)

        return -max_heap[0]
