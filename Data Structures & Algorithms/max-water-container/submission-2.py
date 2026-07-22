class Solution:
    def maxArea(self, heights: List[int]) -> int:
        heights_size = len(heights)
        result = 0

        # Iterate through every possible pairs for area,
        # find the maximumresult as we go
        for i in range(heights_size):
            for j in range(i + 1, heights_size):
                H = min(heights[i], heights[j])
                W = j - i
                result = max(result, H * W)
        return result
