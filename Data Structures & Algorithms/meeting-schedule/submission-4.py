"""
Definition of Interval:
class Interval(object):
    def __init__(self, start, end):
        self.start = start
        self.end = end
"""


class Solution:
    def canAttendMeetings(self, intervals: List[Interval]) -> bool:
        size = len(intervals)

        for i in range(size):
            x = intervals[i]
            for j in range(i + 1, size):
                y = intervals[j]

                # Return false if x and y overlap
                # min(x.end, y.end) -> leftmost of right edges
                # max(x.start, y.start) -> rightmost of left edges
                if min(x.end, y.end) > max(x.start, y.start):
                    return False
        return True
