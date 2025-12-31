class Solution {
public:
    long long solve(int i, int j, vector<int>& cuts, vector<vector<long long>>& dp) {
        if(i > j) {
            return 0;
        }
        if(dp[i][j] != -1) {
            return dp[i][j];
        }
        long long mini = LLONG_MAX;
        for(int k = i; k <= j; k++) 
        {
            long long cost = cuts[j+1] - cuts[i-1] + solve(i, k-1, cuts, dp) + solve(k+1, j, cuts, dp);
            mini = min(mini, cost);
        }
        return dp[i][j] = mini;
    }
    int minCost(int n, vector<int>& cuts) {
        int m = cuts.size();
        cuts.push_back(n);
        cuts.insert(cuts.begin(), 0);
        sort(cuts.begin(), cuts.end());
        vector<vector<long long>> dp(m+2, vector<long long>(m+2, -1));
        return (int)solve(1, m, cuts, dp);
    }
};