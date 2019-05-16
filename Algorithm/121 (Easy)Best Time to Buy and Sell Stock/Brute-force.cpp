class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int maxprofit = 0;
        for(int i = 0; i < prices.size(); i++)
        {
            int maxafter = INT_MIN;
            for(int j = i + 1; j < prices.size(); j++)
                maxafter = max(maxafter, prices[j]);
            if(maxafter != INT_MIN)
                maxprofit = max(maxprofit, maxafter - prices[i]);
        }
            
        return maxprofit;
    }
};
