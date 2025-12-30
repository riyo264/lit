class Solution {
public:
    bool conditionCheck(vector<vector<int>>& grid, int row, int col) {
        unordered_map<int, int> cnt;
        int sum = grid[row][col] + grid[row][col+1] + grid[row][col+2];
        int d1 = grid[row][col] + grid[row+1][col+1] + grid[row+2][col+2];
        int d2 = grid[row][col+2] + grid[row+1][col+1] + grid[row+2][col];
        for(int i = row; i < row+3; i++)
        {
            for(int j = col; j < col+3; j++)
            {
                if(grid[i][j] < 1 || grid[i][j] > 9 || cnt[grid[i][j]] == 1) {
                    return false;
                }
                cnt[grid[i][j]]++;
            }
        }
        if(d1 != sum || d2 != sum) {
            return false;
        }
        for(int i = 0; i < 3; i++)
        {
            if(grid[row][col+i] + grid[row+1][col+i] + grid[row+2][col+i] != sum) {
                return false;
            }
            if(grid[row+i][col] + grid[row+i][col+1] + grid[row+i][col+2] != sum) {
                return false;
            }
        }
        return true;
    }
    int numMagicSquaresInside(vector<vector<int>>& grid) {
        int n = grid.size();
        int m = grid[0].size();
        int ans = 0;
        for(int i = 0; i < n-2; i++)
        {
            for(int j = 0; j < m-2; j++)
            {
                if(conditionCheck(grid, i, j)) {
                    ans++;
                }
            }
        }
        return ans;
    }
};