class Solution {
   public:
    void rotate(vector<vector<int>>& matrix) {
        int l = 0;
        int r = matrix.size()-1;

        while(l<r)
        {
            for(int i= 0; i<r-l; i++)
            {
                int top = l;
                int bottom = r;

                int topLeft = matrix[top][l+i];             // store TL
                matrix[top][l+i]=matrix[bottom-i][l];       // BL -> TL
                matrix[bottom-i][l]=matrix[bottom][r-i];    // BR -> BL
                matrix[bottom][r-i]=matrix[top+i][r];       // TR -> BR
                matrix[top+i][r] = topLeft;                 // TL -> TR
            }
            l++;
            r--;
        }
    }
};
