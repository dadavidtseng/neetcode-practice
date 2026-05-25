class Solution {
   public:
    int maxArea(vector<int>& heights) {
        int const size = static_cast<int>(heights.size());
        int result = 0;
        int left = 0;
        int right = size - 1;

        while (left < right) {
            int area = 0;

            if (heights[left] < heights[right]) {
                area = (right - left) * heights[left];
                left++;
            } else if (heights[left] > heights[right]) {
                area = (right - left) * heights[right];
                right--;
            } else {
                area = (right - left) * heights[left];
                left++;
                right--;
            }

            result = max(result, area);
        }

        return result;
    }
};
