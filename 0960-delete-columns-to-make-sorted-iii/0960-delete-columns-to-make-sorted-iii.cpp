class Solution {
public:

    int minDeletionSize(vector<string>& strs) {
        int n = strs.size();
        int m = strs[0].size();
        vector<int> dp(m, 1);
        int keep = 1;
        for(int i = m-2; i >= 0; i--)
        {
            for(int j = i+1; j < m; j++)
            {
                bool ok = true;
                for(int k = 0; k < n; k++)
                {
                    if(strs[k][i] > strs[k][j]) {
                        ok = false;
                        break;
                    }
                }
                if(ok) {
                    dp[i] = max(dp[i], 1 + dp[j]);
                }
            }
            keep = max(keep, dp[i]);
        }
        return m - keep;
    }
};