class Solution:
    def islandsAndTreasure(self, grid: List[List[int]]) -> None:
        row_size = len(grid)
        col_size = len(grid[0])
        directions = [[-1, 0], [1, 0], [0, -1], [0, 1]]  # up, down, left, right
        q = deque()

        # Iterate through every grid
        for row in range(row_size):
            for col in range(col_size):
                # Push every treasure's row/col index into the queue
                # so that we can start the bfs call from each of them
                if grid[row][col] == 0:
                    q.append((row, col))

        # Exit the while loop when there's nothing to process
        # Note that "while q:" is short for "while len(q) != 0"
        while q:
            (row, col) = q.popleft()

            # Spread the bfs call in four directions
            for r, c in directions:
                next_row = row + r
                next_col = col + c

                # Continue if next grid is out of bound
                if next_row < 0 or next_col < 0 or next_row >= row_size or next_col >= col_size:
                    continue
                # Continue if next grid is not land
                if grid[next_row][next_col] != 2147483647:
                    continue

                # Propagate distance from nearest gate
                grid[next_row][next_col] = grid[row][col] + 1

                # Push next grid's row/col index in the queue
                q.append((next_row, next_col))
