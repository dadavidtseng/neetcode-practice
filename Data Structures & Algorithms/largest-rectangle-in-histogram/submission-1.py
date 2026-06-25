class Solution:
    def largestRectangleArea(self, heights: List[int]) -> int:
        result = 0
        stack = []

        for i, h in enumerate(heights + [-1]):
            while stack and heights[stack[-1]] > h:
                height = heights[stack.pop()]
                if not stack:
                    left = 0
                else:
                    left = stack[-1] + 1
                right = i
                result = max(result, (right - left) * height)

            stack.append(i)

        return result
