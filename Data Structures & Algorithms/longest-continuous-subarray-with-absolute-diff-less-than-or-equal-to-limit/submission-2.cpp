#include <algorithm>
#include <bits/stdc++.h>

class Solution {
public:
    int longestSubarray(vector<int>& nums, int limit) {


        std::deque<int> minQ; // increasing
        std::deque<int> maxQ; // decreasing

        int left   {0};
        int length {0};

        for (int right=0; right < nums.size(); ++right)
        {
            int val = nums[right];

            while (!minQ.empty() && val < minQ.back())
                minQ.pop_back();
                
            while (!maxQ.empty() && val > maxQ.back())
                maxQ.pop_back();

            minQ.push_back(val);
            maxQ.push_back(val);

            while (maxQ.front() - minQ.front() > limit)
            {
                if (nums[left] == minQ.front())
                    minQ.pop_front();
                if (nums[left] == maxQ.front())
                    maxQ.pop_front();

                ++left;
            }
            
            length = std::max(length, right - left + 1);
        }

        return length;
    }

};