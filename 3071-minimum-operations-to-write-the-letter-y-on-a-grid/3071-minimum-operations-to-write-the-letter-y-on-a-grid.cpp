class Solution {
public:
    int minimumOperationsToWriteY(vector<vector<int>>& grid) {
        int n = grid.size();
        vector<int> freqY(3, 0), freqN(3, 0);

        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                bool isY = false;

                if (i <= n/2) {
                    if (j == i || j == n - 1 - i) isY = true;
                } else {
                    if (j == n/2) isY = true;
                }

                if (isY) freqY[grid[i][j]]++;
                else freqN[grid[i][j]]++;
            }
        }

        int yCount = 0, nCount = 0;
        for (int i = 0; i < 3; i++) {
            yCount += freqY[i];
            nCount += freqN[i];
        }

        int ans = INT_MAX;

        for (int a = 0; a < 3; a++) {
            for (int b = 0; b < 3; b++) {
                if (a == b) continue;
                int changes = (yCount - freqY[a]) + (nCount - freqN[b]);
                ans = min(ans, changes);
            }
        }

        return ans;
    }
};