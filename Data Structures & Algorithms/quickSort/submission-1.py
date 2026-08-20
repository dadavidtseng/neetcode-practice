# Definition for a pair.
# class Pair:
#     def __init__(self, key: int, value: str):
#         self.key = key
#         self.value = value
class Solution:
    def quickSort(self, pairs: List[Pair]) -> List[Pair]:
        def dfs(s: int, e: int) -> List[Pair]:
            if s >= e:
                return pairs
            
            L = s
            pivot = e

            for i in range(s, e + 1):
                if pairs[i].key < pairs[pivot].key:
                    pairs[L], pairs[i] = pairs[i], pairs[L]
                    L += 1

            pairs[L], pairs[pivot] = pairs[pivot], pairs[L]

            dfs(s, L - 1)
            dfs(L + 1, e)
            return pairs

        return dfs(0, len(pairs) - 1)
