class Solution:
    def searchMatrix(self, matrix: List[List[int]], target: int) -> bool:
        row_size = len(matrix)
        col_size = len(matrix[0])
        left = 0
        right = (row_size * col_size) - 1

        while left <= right:
            mid = left + (right - left) // 2
            row = mid // col_size
            col = mid % col_size
            m = matrix[row][col]

            if m == target:
                return True
            if m < target:
                left = mid + 1
            elif m > target:
                right = mid - 1

        return False
