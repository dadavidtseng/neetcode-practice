class Solution:
    def largestRectangleArea(self, heights: List[int]) -> int:
        result = 0
        stack = []

        for i, h in enumerate(heights):
            while stack and h < stack[-1][1]:
                height = stack.pop()[1]
                if not stack:
                    left = 0
                else:
                    left = stack[-1][0] + 1
                right = i
                result = max(result, (right - left) * height)

            stack.append((i, h))

        while stack:
            height = stack.pop()[1]
            if not stack:
                left = 0
            else:
                left = stack[-1][0] + 1

            right = len(heights)
            result = max(result, (right - left) * height)

        return result
