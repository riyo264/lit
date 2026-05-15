class Solution {
public:
    long long solve(int n, vector<int>& cost, vector<long long>& dp) {
        if(n <= 1) {
            return cost[n]; 
        }
        if(dp[n] != -1) {
            return dp[n];
        }
        long long one = 0, two = 0;
        if(n == cost.size()) {
            one = solve(n-1, cost, dp);
            two = solve(n-2, cost, dp); 
        }
        else {
            one = cost[n] + solve(n-1, cost, dp);
            two = cost[n] + solve(n-2, cost, dp);
        }
        return dp[n] = min(one, two);
    }
    int minCostClimbingStairs(vector<int>& cost) {
        int n = cost.size();
        vector<long long> dp(n+1, -1);
        return (int)solve(n, cost, dp);
    }
};