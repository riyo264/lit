class Solution {
public:
    int countSubmatrices(vector<vector<int>>& grid, int k) {
        int n = grid.size();
        int m = grid[0].size();
        int ans = 0;
        int sum = grid[0][0];
        if(sum > k) {
            return 0;
        }

        for(int i = 0; i < n; i++)
        {
            for(int j = 1; j < m; j++)
            {
                grid[i][j] += grid[i][j-1];
            }
        }

        for(int j = 1; j < n; j++) 
        {
            for(int i = 0; i < m; i++)
            {
                grid[j][i] += grid[j-1][i];
            }
        }

        for(int i = 0; i < n; i++)
        {
            for(int j = 0; j < m; j++)
            {
                if(grid[i][j] <= k) {
                    ans++;
                }
            }
        }
        
        return ans;
    }
};