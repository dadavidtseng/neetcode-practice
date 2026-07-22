class Solution:
    def maxArea(self, heights: List[int]) -> int:
        height_size = len(heights)
        result = 0
        L = 0
        R = height_size - 1

        # Exit the while loop when left/right pointers cross
        # 1. Pick whichever is smaller between height[L] and height[R] as H
        # 2. Calculate W
        # 3. Assign the maximum between result and area(W*H) to result
        while L < R:
            H = 0
            W = R - L

            if heights[L] < heights[R]:
                H = heights[L]
                L += 1
            elif heights[L] > heights[R]:
                H = heights[R]
                R -= 1
            else:
                H = heights[L]
                L += 1
                R -= 1
            result = max(result, H * W)
        return result
