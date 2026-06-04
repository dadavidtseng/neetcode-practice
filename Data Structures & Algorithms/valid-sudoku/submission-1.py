class Solution:
    def isValidSudoku(self, board: List[List[str]]) -> bool:
        s=set()

        for i in range(9):
            for j in range(9):
                if board[i][j]=='.':
                    continue
                if board[i][j] not in s:
                    s.add(board[i][j])
                    continue
                return False
            s.clear()

        for i in range(9):
            for j in range(9):
                if board[j][i]=='.':
                    continue
                if board[j][i] not in s:
                    s.add(board[j][i])
                    continue
                return False
            s.clear()

        for i in range(0, 9, 3):
            for j in range(0, 9, 3):
                for x in range(i, i+3):
                    for y in range(j, j+3):
                        if board[x][y] == '.':
                            continue
                        if board[x][y] not in s:
                            s.add(board[x][y])
                            continue
                        return False
                s.clear()
                    
        return True