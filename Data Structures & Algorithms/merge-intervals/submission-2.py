class Solution:
    def merge(self, intervals: List[List[int]]) -> List[List[int]]:
        max_value = max(interval[0] for interval in intervals)

        m = [-1] * (max_value + 1)

        for start, end in intervals:
            m[start] = max(m[start], end)

        result = []
        have = -1
        interval_start = -1

        for i in range(len(m)):
            if m[i] != -1:
                if interval_start == -1:
                    interval_start = i
                have = max(have, m[i])

            if have == i:
                result.append([interval_start, have])
                have = -1
                interval_start = -1

        if interval_start != -1:
            result.append([interval_start, have])

        return result