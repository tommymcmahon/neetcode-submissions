class Solution {
public:
    int maxSatisfied(vector<int>& customers, vector<int>& grumpy, int minutes) {

        int left = 0;
        int window = 0; 
        int maxWindow = 0;
        int satisfied = 0;

        for (int right=0; right < customers.size(); ++right)
        {
            if (grumpy[right])
            {
                window += customers[right];
            }
            else
            {
                satisfied += customers[right];
            }

            if ((right - left + 1) > minutes)
            {
                if (grumpy[left] == 1)
                {
                    window -= customers[left];
                }
                ++left; 
            }
            maxWindow = std::max(maxWindow, window);
        }

        return satisfied + maxWindow;

    }
};