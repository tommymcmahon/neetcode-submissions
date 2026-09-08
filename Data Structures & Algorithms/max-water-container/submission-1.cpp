class Solution {
public:
    int maxArea(vector<int>& heights) {

        int left=0;
        int right=heights.size()-1;

        int maxArea = 0;
        while (left < right)
        {
            int h = std::min(heights[right], heights[left]);
            int w = right - left;
            int a = h * w;
            maxArea = std::max(maxArea, a);

            if (heights[right] < heights[left])
            {
                right--;    
            }
            else
            {
                left++;
            } 


        }

        return maxArea;

    }
};
