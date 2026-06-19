class Solution:
    def groupAnagrams(self, strs: List[str]) -> List[List[str]]:
        result: defaultdict[str, list[str]] = defaultdict(list)

        # Iterate through strs and store the sorted_s as key with s as value in the map
        for s in strs:
            sorted_s = "".join(sorted(s))
            result[sorted_s].append(s)

        # Convert result from defaultdict[str, list[str]] to List[List[str]]
        return list(result.values())
