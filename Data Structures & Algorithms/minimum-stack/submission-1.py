class MinStack:
    def __init__(self):
        self.v = []
        self.cache_min = []

    def push(self, value: int) -> None:
        if len(self.cache_min) == 0 or value <= self.cache_min[-1]:
            self.cache_min.append(value)
        self.v.append(value)

    def pop(self) -> None:
        if self.v[-1] == self.cache_min[-1]:
            self.cache_min.pop()
        self.v.pop()

    def top(self) -> int:
        return self.v[-1]

    def getMin(self) -> int:
        return self.cache_min[-1]
