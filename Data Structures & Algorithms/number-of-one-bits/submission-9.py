class Solution:
    def hammingWeight(self, n: int) -> int:
        result = 0

        # Exit the while loop when n isn't 0
        while n != 0:
            # Flip the rightmost 1 bit to 0
            # Note that n | (n + 1) can flip the rightmost 0 bit to 1
            n = n & (n - 1)
            result += 1
        return result
