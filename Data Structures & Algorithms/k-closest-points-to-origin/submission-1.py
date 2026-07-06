from math import sqrt

class Solution:
    def kClosest(self, points: List[List[int]], k: int) -> List[List[int]]:
        # Create a max heap using points
        max_heap = []
        result = []

        # Push the points into the max heap and maintain k size so we can return the kClosest
        for point in points:
            dist = sqrt(point[0] * point[0] + point[1] * point[1])
            heapq.heappush(max_heap, (-dist, point))

            if len(max_heap) > k:
                heapq.heappop(max_heap)

        for dist, point in max_heap:
            result.append(point)
        return result
