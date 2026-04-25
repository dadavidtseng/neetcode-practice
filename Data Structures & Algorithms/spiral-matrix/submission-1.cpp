class Solution {
   public:
    vector<int> spiralOrder(vector<vector<int>>& matrix) {
        // m -> row
        // n -> column
        int m = matrix.size();
        int n = matrix[0].size();

        // m=2, n=2
        // 1,2 -> 1,2,4,3
        // 3,4

        // m=3, n=3
        // 1,2,3 -> 1,2,3,6,9,8,7,4,5
        // 4,5,6
        // 7,8,9

        // m=2, n=4
        // 1,2,3,4 -> 1,2,3,4,8,7,6,5
        // 5,6,7,8

        

        vector<int> spiral{};
        int left = 0;
        int right = n - 1;
        int top = 0;
        int bottom = m - 1;

        while (left <= right && top <= bottom) {
            // Single row remaining: just traverse it left to right
            if (top == bottom) {
                for (int i = left; i <= right; i++) {
                    spiral.push_back(matrix[top][i]);
                }
                break;
            }
            // Single column remaining: just traverse it top to bottom
            if (left == right) {
                for (int j = top; j <= bottom; j++) {
                    spiral.push_back(matrix[j][left]);
                }
                break;
            }

            // Top row: left to right-1
            for (int i = left; i < right; i++) {
                spiral.push_back(matrix[top][i]);
            }
            // Right column: top to bottom-1
            for (int j = top; j < bottom; j++) {
                spiral.push_back(matrix[j][right]);
            }
            // Bottom row: right to left+1
            for (int k = right; k > left; k--) {
                spiral.push_back(matrix[bottom][k]);
            }
            // Left column: bottom to top+1
            for (int r = bottom; r > top; r--) {
                spiral.push_back(matrix[r][left]);
            }

            left++;
            right--;
            top++;
            bottom--;
        }

        return spiral;
    }
};
