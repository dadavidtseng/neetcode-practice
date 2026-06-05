class Solution:
    def trap(self, height: List[int]) -> int:
        result = 0
        prefix: List[int] = []
        suffix: List[int] = []
        prefix_max = 0
        suffix_max = 0

        for i in range(len(height)):
            prefix_max = max(prefix_max, height[i])
            suffix_max = max(suffix_max, height[len(height) - 1 - i])
            prefix.append(prefix_max)
            suffix.append(suffix_max)

        for i in range(len(height)):
            result += min(prefix[i], suffix[len(height) - 1 - i]) - height[i]

        return result
