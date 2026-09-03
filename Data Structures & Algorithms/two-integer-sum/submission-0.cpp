class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {

        // Key: index / Value: complement
        std::unordered_map<int, int> complements;
        complements[nums[0]] = 0;

        for(int i=1; i < nums.size(); ++i)
        {
            int complement = target - nums[i];
            if (complements.contains(complement))
            {
                int index = complements[complement];
                if (i > index) {
                    return { index, i };
                }
                else {
                    return { i, index };
                }
            }
            else
            {
                complements[nums[i]] = i;
            }
        }
        return { };
    }
};
