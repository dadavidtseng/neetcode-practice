class Solution:
    def minEatingSpeed(self, piles: List[int], h: int) -> int:
        l = 1
        r = max(piles)
        result = 0

        while l <= r:
            mid = l + (r - l) // 2
            result = 0

            for i in piles:
                result += math.ceil(i / mid)

            if result <= h:
                r = mid - 1
            else:
                l = mid + 1

        return l
