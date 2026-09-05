class Solution {
public:
    bool isMonotonic(vector<int>& nums) {

        auto n = nums.size(); 
        if (n <= 1) return true;

        // skip duplicates at the start 
        int i=0;
        for (i=0; i < n-1; i++)  
        {
            if (nums[i] != nums[i+1]) break;
        }

        bool isAscending = (nums[i] < nums[i+1]);
        for (i=i+1; i < n-1; ++i)  
        {
            if (isAscending)
            {
                // Return false is not ascending
                if (nums[i] > nums[i+1])
                {
                    std::cout << nums[i] << ">" << nums[i+1] << std::endl;
                    return false;
                }
            }
            else
            {
                // Return false is not ascending
                if (nums[i] < nums[i+1])
                {
                    std::cout << nums[i] << "<" << nums[i+1] << std::endl;
                    return false;
                }
            }
        }
        
        return true;
    }

};