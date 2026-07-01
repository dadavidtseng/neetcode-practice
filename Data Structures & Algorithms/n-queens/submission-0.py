class Solution:
    def solveNQueens(self, n: int) -> List[List[str]]:
        result = []
        row = 0
        cols_available = set(range(n))
        self.backtrack(n, row, cols_available, [], result)
        return result

    def backtrack(self, n: int, row, cols_available, curr: List[str], result: List[List[str]]):
        if row == n:
            # convert curr to string format, add to result
            board = []
            for col in curr:
                board.append("." * int(col) + "Q" + "." * (n - 1 - int(col)))
            result.append(board)
            return

        for col in cols_available.copy():
            diagonal_conflict = False

            for i in range(len(curr)):
                if abs(row - i) == abs(col - curr[i]):
                    diagonal_conflict = True
                    break

            if not diagonal_conflict:  # check against previous queens
                curr.append(col)
                # remove col from available
                cols_available.remove(col)
                self.backtrack(n, row + 1, cols_available, curr, result)
                # add col back to available
                cols_available.add(col)
                curr.pop()
