class Solution {

private:    
    int nrows;
    int ncols;
    int islands {0};
public:
    int numIslands(vector<vector<char>>& grid) {

        nrows = grid.size();
        ncols = grid[0].size();

        std::vector<int> seen(nrows * ncols, 0);

        for (int row=0; row < nrows; ++row)
        {
            for (int col=0; col < ncols; ++col)
            {
                int seenIndex = row * ncols + col;
                if (seen[seenIndex] == 0)
                {
                    if (grid[row][col] == '1') { ++islands; }
#if defined(DEBUG)
                    std::cout << row << ":"  << col
                    << "/seen[" << (seenIndex )
                    << "]="    << (seen[seenIndex]) 
                    << "->"    << (grid[row][col] == '1' ? "land" : "water")
                    << std::endl;
#endif
                    dfs(grid, row, col, seen);
                }
            }
        }
        return islands;
    }

    void dfs(auto &grid, int row, int col,  std::vector<int> &seen)
    {
        if (row < 0 || col < 0 || row >= nrows || col >= ncols)
        {
            return;    
        }

        int seenIndex = row * ncols + col;
        if (seen[seenIndex] == 0) 
        {
            seen[seenIndex] = 1;
            if (grid[row][col] == '1')
            {
#if defined(DEBUG)
                std::cout << "\t" << row << ":"  << col
                    << "/seen[" << (seenIndex )
                    << "]="    << (seen[seenIndex]) 
                    << "->"    << (grid[row][col] == '1' ? "land" : "water")
                    << std::endl;
#endif
                dfs(grid, row+1, col,   seen);
                dfs(grid, row-1, col,   seen);
                dfs(grid, row,   col+1, seen);
                dfs(grid, row,   col-1, seen);
            }
        }
    }
};
