class Solution:
    def hammingWeight(self, n: int) -> int:
        result = 0

        # Exit the while loop when n isn't 0
        while n != 0:
            # Increment result when the least significant bit is 1
            # and shift the bit by 1
            result += n & 1
            n >>= 1

        return result
