class Solution {
public:
    vector<int> dfs(int node, int discount_check, vector<int>& present, vector<int>& future, unordered_map<int, vector<int>>& tree, vector<vector<vector<int>>>& dp, int budget) {
        if(!dp[node][discount_check].empty()) {
            return dp[node][discount_check];
        }
        vector<int> profit_dp(budget+1, 0);

        vector<int> notBuy(budget+1, 0);
        for(auto& x : tree[node]) 
        {
            vector<int> employee_prof = dfs(x, 0, present, future, tree, dp, budget);
            vector<int> temp(budget+1, 0);
            for(int i = 0; i <= budget; i++)
            {
                for(int allo = 0; allo <= i; allo++)
                {
                    temp[i] = max(temp[i], notBuy[allo] + employee_prof[i - allo]);
                }
            }
            notBuy = temp;
        }

        int cost = present[node];
        if(discount_check == 1) {
            cost = present[node]/2;
        }
        int cur_profit = future[node] - cost;
        vector<int> final_Buy(budget+1, INT_MIN);
        if(cost >= 0 && cost <= budget) {
            vector<int> Buy(budget + 1, 0);
            for(auto& x : tree[node])
            {
                vector<int> employee_prof = dfs(x, 1, present, future, tree, dp, budget);
                vector<int> temp(budget+1, 0);
                for(int i = 0; i <= budget; i++)
                {
                    for(int allo = 0; allo <= i; allo++)
                    {
                        temp[i] = max(temp[i], Buy[allo] + employee_prof[i - allo]);
                    }
                }
                Buy = temp;
            }
            for(int i = cost; i <= budget; i++)
            {
                final_Buy[i] = cur_profit + Buy[i - cost];
            }
        }

        for(int i = 0; i <= budget; i++)
        {
            profit_dp[i] = max(notBuy[i], max(final_Buy[i], 0));
        }

        return dp[node][discount_check] = profit_dp;
    }

    int maxProfit(int n, vector<int>& present, vector<int>& future, vector<vector<int>>& hierarchy, int budget) {
        unordered_map<int, vector<int>> tree;
        for(auto& h : hierarchy)
        {
            int u = h[0] - 1;
            int v = h[1] - 1;
            tree[u].push_back(v);
        }
        vector<vector<vector<int>>> dp(n, vector<vector<int>>(2));
        vector<int> profit = dfs(0, 0, present, future, tree, dp, budget);
        int max_profit = 0;
        for(auto& x : profit) {
            max_profit = max(max_profit, x);
        }
        return max_profit;
    }
};