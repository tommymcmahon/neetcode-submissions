#include <assert.h>
class Solution {
public:
    vector<int> findMissingAndRepeatedValues(vector<vector<int>>& grid) {

        int numElements = grid.size() * grid.size();

        std::vector<int> seen(numElements, 0);
        std::vector<int> result(2, 0);

        std::cout << numElements << std::endl;

        for (int i=0; i < grid.size(); ++i) {
            for (int j=0; j < grid.size(); ++j) {
                int value = grid[i][j];
                seen[value-1]++;
            }
        }

        int duplicate = 0;
        int missing   = 0;

        for (int i=0; i < numElements && (result[0] ==0 && result[1] == 0); ++i)
        {
            if (seen[i] == 0)
            {
                missing = i+1;   
            }
            else if (seen[i] == 2)
            {
                duplicate = i+1;
            }
        }

        return { duplicate, missing };
    }
};