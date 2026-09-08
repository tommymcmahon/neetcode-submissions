class Solution {
public:

    void rotate(vector<vector<int>>& matrix) 
    {
        int n = matrix.size();
        int rotations = n-1;

        int left  =0;
        int right = rotations;

        while (left < right)
        {
            for (int i=0; i < right - left; ++i)
            {
                int top    = left;
                int bottom = right;

                // save initial value
                int topLeft = matrix[top][left+i];

                // TL = BL
                matrix[top][left+i] = matrix[bottom-i][left];

                // BL = BR
                matrix[bottom-i][left] = matrix[bottom][right-i];

                // BR = TR
                matrix[bottom][right-i] = matrix[top+i][right];

                // TR = TL
                matrix[top+i][right] = topLeft;
            }

            right--;
            left++;
        }
    }
};
