class Solution {
public:
    int maxProfit(vector<int>& prices) {

        int profit {0};
        int buy    {0};
        for (int sell=1; sell < prices.size(); ++sell)
        {
            if (prices[buy]  > prices[sell])
            {
                buy = sell;
                continue;
            }
            
            profit = std::max(profit, prices[sell] - prices[buy]);
        }

        return profit;
    }
};
