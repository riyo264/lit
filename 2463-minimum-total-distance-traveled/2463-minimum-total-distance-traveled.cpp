class Solution {
public:
    long long minimumTotalDistance(vector<int>& robot, vector<vector<int>>& factory) {
        sort(robot.begin(), robot.end());
        sort(factory.begin(), factory.end());
        const long long INF = 1e18;
        int l = robot.size();
        int n = factory.size();
        vector<vector<long long>> dp(l + 1, vector<long long>(n + 1, INF));
        for (int j = 0; j <= n; j++)
            dp[0][j] = 0;
        for (int j = 1; j <= n; j++) {
            int pos = factory[j-1][0];
            int limit = factory[j-1][1];

            for (int i = 0; i <= l; i++) {
                dp[i][j] = dp[i][j-1];

                long long dist = 0;
                for (int k = 1; k <= limit && i - k >= 0; k++) {
                    dist += abs(robot[i-k] - pos);
                    dp[i][j] = min(dp[i][j], dp[i-k][j-1] + dist);
                }
            }
        }
        return dp[l][n];
    }
};