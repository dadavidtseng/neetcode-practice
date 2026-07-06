"""
Definition of Interval:
class Interval(object):
    def __init__(self, start, end):
        self.start = start
        self.end = end
"""


class Solution:
    def canAttendMeetings(self, intervals: List[Interval]) -> bool:
        # Sort intervals in ascending order using interval.start
        intervals.sort(key=lambda x: x.start)

        # Iterate through intervals
        # Return false if adjancent intervals overlap
        # Note that we don't need to check anything besides the adjancent interval because if
        # intervals[i - 2] overlaps with intervals[i], it's definitely overlapping with
        # intervals[i - 1] as well
        for i in range(1, len(intervals)):
            if intervals[i].start < intervals[i - 1].end:
                return False
        return True
