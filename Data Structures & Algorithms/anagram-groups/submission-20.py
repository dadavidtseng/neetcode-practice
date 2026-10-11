class Solution:
    def groupAnagrams(self, strs: List[str]) -> List[List[str]]:
        result: defaultdict[str, list[str]] = defaultdict(list)

        # Iterate through strs
        for s in strs:
            count = [0] * 26

            # For every c in s, count the frequency of the c
            for c in s:
                count[ord(c) - ord("a")] += 1

            # At concatenated string from count, push s into the map
            result[",".join(str(c) for c in count)].append(s)

        # Convert result from defaultdict[str, list[str]] to List[List[str]]
        return list(result.values())
