class Solution:
    def findMedianSortedArrays(self, nums1: List[int], nums2: List[int]) -> float:
        m = len(nums1)
        n = len(nums2)

        if m > n:
            temp = m
            m = n
            n = temp
            temp = nums1
            nums1 = nums2
            nums2 = temp

        low = 0
        high = m

        while low <= high:
            i = (low + high) // 2
            j = (m + n + 1) // 2 - i

            a = nums1[i - 1] if i > 0 else float("-inf")
            b = nums1[i] if i < m else float("inf")
            c = nums2[j - 1] if j > 0 else float("-inf")
            d = nums2[j] if j < n else float("inf")

            if a > d:
                high = i - 1
            elif c > b:
                low = i + 1
            else:
                if (m + n) % 2 == 0:
                    return (max(a, c) + min(b, d)) / 2
                else:
                    return max(a, c)
