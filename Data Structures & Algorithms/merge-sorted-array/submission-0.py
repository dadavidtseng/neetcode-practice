class Solution:
    def merge(self, nums1: List[int], m: int, nums2: List[int], n: int) -> None:
        for i in range(n):
            nums1[m + i] = nums2[i]

        def mergeTwo(s, m, e) -> None:
            L = nums1[s : m + 1]
            R = nums1[m + 1 : e + 1]

            i = 0
            j = 0
            k = s

            while i < len(L) and j < len(R):
                if L[i] <= R[j]:
                    nums1[k] = L[i]
                    i += 1
                else:
                    nums1[k] = R[j]
                    j += 1
                k += 1
            while i < len(L):
                nums1[k] = L[i]
                i += 1
                k += 1
            while j < len(R):
                nums1[k] = R[j]
                j += 1
                k += 1

        def mergeSort(s, e) -> None:
            if e - s + 1 <= 1:
                return
            m = (s + e) // 2

            mergeSort(s, m)
            mergeSort(m + 1, e)

            mergeTwo(s, m, e)

        mergeSort(0, m + n - 1)
