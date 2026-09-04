class Solution {
public:
    int search(vector<int>& nums, int target) {

        int left  = 0;
        int right = nums.size() - 1;
        int mid   = nums.size() / 2;

        while (left <= right)
        {
            mid = left + ((right - left) / 2);
#define DEBUG
#if defined(DEBUG)
            cout << left << ":" << right << ":" << mid << endl;
#endif
            if      (nums[mid] == target){ return mid;  }
            else if (target > nums[mid]) { left  = mid+1; }
            else if (target < nums[mid]) { right = mid-1; } 

        }

        return -1;
    }
};
