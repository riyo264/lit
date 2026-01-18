class Solution {
    bool check(vector<vector<int>>& a, int r, int c, int len) {
        int target = 0;
        for (int y = c; y < c + len; y++) target += a[r][y];
        for (int x = r; x < r + len; x++) {
            int cur = 0;
            for (int y = c; y < c + len; y++) cur += a[x][y];
            if (cur != target) return false;
        }
        for (int y = c; y < c + len; y++) {
            int cur = 0;
            for (int x = r; x < r + len; x++) cur += a[x][y];
            if (cur != target) return false;
        }
        int cur = 0;
        for (int d = 0; d < len; d++) cur += a[r + d][c + d];
        if (cur != target) return false;
        cur = 0;
        for (int d = 0; d < len; d++) cur += a[r + d][c + len - 1 - d];
        if (cur != target) return false;
        return true;
    }

public:
    int largestMagicSquare(vector<vector<int>>& grid) {
        int rows = grid.size(), cols = grid[0].size();
        int best = 1;
        for (int len = 2; len <= min(rows, cols); len++) {
            for (int r = 0; r + len <= rows; r++) {
                for (int c = 0; c + len <= cols; c++) {
                    if (check(grid, r, c, len)) best = len;
                }
            }
        }
        return best;
    }
};
