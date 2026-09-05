#include <iostream>

class Solution {
public:

    using Image_t = vector<vector<int>> ;

    vector<vector<int>> floodFill(vector<vector<int>>& image, int sr, int sc, int color) {

        this->old_color = image[sr][sc];
        this->color   = color;

        if (old_color != color)
        {
            m = image.size();
            n = image[0].size();
            dfs(image, sr, sc);
        }
        
        return image;
    }

    private:

        int m; // row size
        int n; // column size

        int color;
        int old_color;

    void dfs(Image_t &image, int r, int c)
    {

        if (r < 0 || r >= m || c < 0 || c >= n) { return; }
        if (image[r][c] != old_color)           { return; }

        image[r][c] = color;
        std::cout << "image[" << r << "," << c << "]=" << image[r][c] << std::endl;

        dfs(image, r-1, c);
        dfs(image, r+1, c);
        dfs(image, r, c-1);
        dfs(image, r, c+1);
    }
};