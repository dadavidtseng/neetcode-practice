class Solution:
    def isValidSudoku(self, board: List[List[str]]) -> bool:
        row_set = [set() for _ in range(9)]
        col_set = [set() for _ in range(9)]
        box_set = [set() for _ in range(9)]

        for row in range(9):
            for col in range(9):
                c = board[row][col]

                if c == ".":
                    continue
                box_idx = (row // 3) * 3 + col // 3

                if c in row_set[row] or c in col_set[col] or c in box_set[box_idx]:
                    return False

                row_set[row].add(c)
                col_set[col].add(c)
                box_set[box_idx].add(c)

        return True
