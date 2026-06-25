class TimeMap:
    def __init__(self):
        self.key_store = {}

    def set(self, key: str, value: str, timestamp: int) -> None:
        if key not in self.key_store:
            self.key_store[key] = []
        self.key_store[key].append([value, timestamp])

    def get(self, key: str, timestamp: int) -> str:
        result, value = "", self.key_store.get(key, [])
        l, r = 0, len(value) - 1

        while l <= r:
            mid = l + (r - l) // 2
            
            if value[mid][1] <= timestamp:
                result = value[mid][0]
                l = mid + 1
            else:
                r = mid - 1
        return result
