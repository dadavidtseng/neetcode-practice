"""
Understand:
Provided a string(could have leading zeros) containing "0" and "1",
return the maximum odd binary number as a string

Match:
Bit manipulation, String, Hashmap

Plan:
Create a frequency map to record provided string's "0" and "1"
and construct the string backward, this will end up with time/space
complexity O(n).

Provided string contains at least one, so what we can get is at least
000...00001, we can just iterate through the provided string and count
the amount of "1" it has and construct the returning string with 1 on
the very right and all the remaining 1s on the left.

"0110"
"   1"
"""


class Solution:
    def maximumOddBinaryNumber(self, s: str) -> str:
        count = 0
        result = []

        for c in s:
            if c == "1":
                count += 1

        count -= 1

        for _ in range(len(s) - 1):
            if count > 0:
                result.append("1")
                count -= 1
            else:
                result.append("0")
        result.append("1")
        return "".join(result)
