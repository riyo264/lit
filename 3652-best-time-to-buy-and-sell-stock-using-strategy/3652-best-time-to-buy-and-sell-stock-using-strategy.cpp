class Solution {
public:
    long long maxProfit(vector<int>& prices, vector<int>& strategy, int k) {
        int n = strategy.size();
        long long profit = 0;
        vector<long long> margin(n), og(n);
        for(int i = 0; i < n; i++)
        {
            margin[i] = (strategy[i] * prices[i]);
            og[i] = prices[i];
            profit += margin[i];
        }
        vector<long long> pref0(n+1, 0), pref1(n+1, 0);
        for(int i = 0; i < n; i++)
        {
            pref0[i+1] = pref0[i] + margin[i];
            pref1[i+1] = pref1[i] + og[i];
        }
        long long ans = profit;
        for(int l = 0; l+k <= n; l++)
        {
            int r = l + k - 1;
            int mid = l + k/2;
            long long zero_strat_half = pref0[mid] - pref0[l];
            long long right_strat_half = pref0[r+1] - pref0[mid];
            long long new_right_strat_half = pref1[r+1] - pref1[mid];
            long long temp = profit - zero_strat_half - right_strat_half + new_right_strat_half;
            ans = max(ans, temp);
        }
        return ans;






        // TLE O(N*K)

        // for(int i = 0; i < n; i++)
        // {
        //     profit += (strategy[i] * prices[i]);
        // }
        // int l = 0;
        // int r = l + k - 1;
        // long long temp = profit;
        // long long temp1 = profit;
        // vector<int> temp_strat = strategy;
        // while(r < n) 
        // {
        //     for(int i = l; i <= l + k/2 - 1; i++)
        //     {
        //         temp -= (strategy[i] * prices[i]);
        //     }
        //     for(int i = l + k/2; i <= r; i++)
        //     {
        //         temp -= (strategy[i] * prices[i]);
        //         temp_strat[i] = 1;
        //         temp += (temp_strat[i] * prices[i]);
        //     }
        //     profit = max(temp, profit);
        //     temp = temp1;
        //     temp_strat = strategy;
        //     l++;
        //     r++;
        // }
        // return profit;
    }
};