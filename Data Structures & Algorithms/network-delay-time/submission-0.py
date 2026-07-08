class Solution:
    def networkDelayTime(self, times: List[List[int]], n: int, k: int) -> int:
        dist = [float("inf")] * (n + 1)
        dist[k] = 0
        min_heap = []
        heapq.heappush(min_heap, (0, k))  # node k is reachable in time 0
        adj_list = defaultdict(list)

        for u, v, w in times:
            adj_list[u].append((v, w))  # From node u, we can reach node v with w time

        while min_heap:
            (curr_time, node) = heapq.heappop(min_heap)

            if curr_time > dist[node]:
                continue

            for neighbor, neighbor_time in adj_list[node]:
                new_time = curr_time + neighbor_time

                if new_time < dist[neighbor]:
                    dist[neighbor] = new_time
                    heapq.heappush(min_heap, (new_time, neighbor))

        result = 0
        for i in range(1, n + 1):
            if dist[i] == float("inf"):
                return -1
            result = max(result, dist[i])
        return int(result)
