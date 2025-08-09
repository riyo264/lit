class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int n = prices.size();
        int l = 0;
        int r = 0;
        int max_profit = INT_MIN;
        while(r < n)
        {
            max_profit = max(max_profit, (prices[r] - prices[l]));
            if(prices[r] < prices[l]) {
                l = r;
            }
            r++;
        }
        return max_profit;
    }
};