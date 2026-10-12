class Solution:
    def merge(self, intervals: List[List[int]]) -> List[List[int]]:
        # Find the end value in intervals
        max_value = max(end for _, end in intervals)

        # Create a mapping to store what the current start's furtherest end is
        # Note that we're using -1 as invalid to avoid [0, 0] case
        m = [-1] * (max_value + 1)
        for start, end in intervals:
            m[start] = max(m[start], end)

        # Keep track of interval start and what's the current end
        interval_start = -1
        current_end = -1
        result = []

        # Iterate/Scan through m
        for i in range(len(m)):
            if m[i] != -1:
                if interval_start == -1:
                    interval_start = i
                current_end = max(current_end, m[i])

            if i == current_end:
                result.append([interval_start, current_end])
                interval_start = -1
                current_end = -1

        # if interval_start != -1:
        #     result.append([interval_start, current_end])

        return result