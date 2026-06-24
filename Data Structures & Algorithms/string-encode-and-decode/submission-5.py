class Solution:
    def encode(self, strs: List[str]) -> str:
        # Return empty string if strs is empty
        if not strs:
            return ""

        result = []

        # Iterate through strs and store each s's size and "." in result
        for s in strs:
            result.append(str(len(s)))
            result.append(".")

        result.append("#")

        # Iterate through strs and store each s in result
        for s in strs:
            result.append(s)

        # Return result(list) as a string
        return "".join(result)

    def decode(self, s: str) -> List[str]:
        # Return empty if s is empty
        if not s:
            return []

        strs_sizes = []
        i = 0

        # Exist the loop when finding "#"
        while s[i] != "#":
            # Sync j to i
            j = i

            # Advance j until hitting "."
            while s[j] != ".":
                j += 1

            # i = start index for strs_sizes
            # j = end index + 1 for strs_sizes
            # Push strs_sizes into strs_sizes
            strs_sizes.append(int(s[i:j]))

            # Advance i to j + 1, which is the index after "."
            i = j + 1

        # Advance one for "#"
        i += 1

        result = []

        # Iterate through strs_sizes and push s[i:i+size] into result as we advance i
        for size in strs_sizes:
            result.append(s[i : i + size])
            i += size

        return result
