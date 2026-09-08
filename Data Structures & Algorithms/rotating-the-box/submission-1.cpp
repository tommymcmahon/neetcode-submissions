class Solution {
public:
     vector<vector<char>> rotateTheBox(vector<vector<char>>& boxGrid) {

        int m = boxGrid.size();
        int n = boxGrid[0].size();

        // drop stones
        for (int i=0; i < m; ++i)   
        {
            int left  = n-1;
            int right = n-1;
            while (right >= left && left >= 0 && right >= 0)
            {
                cout << right << ":" << left << "\n";

                while (left >= 0 && boxGrid[i][left] == '.')
                {
                    --left;
                }

                if (left >= 0 && boxGrid[i][left] == '*')
                {
                    --left;
                    right = left;
                }

                while (left >= 0 && boxGrid[i][left] == '#')
                {
                    std::swap(boxGrid[i][left], 
                              boxGrid[i][right]);
                    --left;
                    --right;
                }
            }
        }

        // rotate
        vector<vector<char>> newGrid;
        for (int c=0; c < n; ++c)
        {
            vector<char> newRow;
            for (int r = m-1; r >= 0; --r)
            {
                newRow.push_back(boxGrid[r][c]);
            }
            newGrid.push_back(newRow);
        }  

        return newGrid;
    }

    void printGrid(auto& grid) 
    {
        for (int i=0; i < grid.size(); ++i)   
        {
            std::cout << "[";
            for (int j=0; j < grid[0].size(); ++j)   
            {
                std::cout << grid[i][j] << " ";
            }
            std::cout << "]" << std::endl;
        } 
        std::cout << "=======================" << std::endl;
    }
};