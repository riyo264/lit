class Solution {
public:
    int minDeletionSize(vector<string>& strs) {
        int n = strs.size();
        int m = strs[0].size();
        int ans = 0;
        vector<bool> good(n - 1, false);
        for (int c = 0; c < m; c++) {
            bool bad = false;
            for (int r = 0; r < n - 1; r++) {
                if (!good[r] && strs[r][c] > strs[r + 1][c]) {
                    bad = true;
                    break;
                }
            }
            if (bad) {
                ans++;
                continue;
            }
            for (int r = 0; r < n - 1; r++) {
                if (!good[r] && strs[r][c] < strs[r + 1][c]) {
                    good[r] = true;
                }
            }
        }
        return ans;
    }
};
