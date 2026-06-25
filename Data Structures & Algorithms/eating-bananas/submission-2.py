class Solution:
    def minEatingSpeed(self, piles: List[int], h: int) -> int:
        l = 1
        r = max(piles)
        total_hours = 0

        while l <= r:
            mid = l + (r - l) // 2

            total_hours = 0

            for i in piles:
                total_hours += math.ceil(i / mid)

            if total_hours <= h:
                r = mid - 1
            else:
                l = mid + 1

        return l
