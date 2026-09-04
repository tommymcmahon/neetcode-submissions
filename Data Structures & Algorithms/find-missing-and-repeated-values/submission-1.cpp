class Solution {
public:
    vector<int> findMissingAndRepeatedValues(vector<vector<int>>& grid) {

        int length = grid.size();
        int dup    = 0;

        std::unordered_set<int> range;
        for (int i=1; i <= length * length; ++i ) {
            range.insert(i);
        }

        for (const auto &num: range) {
            std::cout << num << " ";
        }
        std::cout << std::endl;
    
    
        for (int i=0; i < length; ++i) {
            for (int j=0; j < length; ++j)     {
                int value = grid[i][j];
                if (!range.contains(value)) {
                    dup = value;
                }
                range.erase(value);
            }
        }


        return { dup, *range.begin() };
    }
};