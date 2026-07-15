class Solution:
    def hammingWeight(self, n: int) -> int:
        result = 0

        # Iterate through all 32 bits in an integer
        for i in range(32):
            # Increment the result if ith bit in an integer is 1
            if (n >> i) & 1:
                result += 1
        return result
