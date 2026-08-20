# Definition for a pair.
# class Pair:
#     def __init__(self, key: int, value: str):
#         self.key = key
#         self.value = value
class Solution:
    def mergeSort(self, pairs: List[Pair]) -> List[Pair]:
        def dfs(s: int, e: int) -> List[Pair]:
            if e == s or e == -1:
                return pairs
            m = (s + e) // 2

            dfs(s, m)
            dfs(m + 1, e)
            merge(s, m, e)
            return pairs

        def merge(s: int, m: int, e: int) -> List[Pair]:
            L = pairs[s : m + 1]
            R = pairs[m + 1 : e + 1]
            i = 0
            j = 0
            k = s

            while i < len(L) and j < len(R):
                if L[i].key <= R[j].key:
                    pairs[k] = L[i]
                    i += 1
                else:
                    pairs[k] = R[j]
                    j += 1
                k += 1

            while i < len(L):
                pairs[k] = L[i]
                i += 1
                k += 1

            while j < len(R):
                pairs[k] = R[j]
                j += 1
                k += 1
            return pairs

        return dfs(0, len(pairs) - 1)
