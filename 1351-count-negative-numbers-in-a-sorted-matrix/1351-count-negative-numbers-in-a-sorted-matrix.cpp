class Solution {
public:
    int countNegatives(vector<vector<int>>& grid) {
        int n = grid.size();
        int m = grid[0].size();
        if(grid[n-1][m-1] > -1) {
            return 0;
        }
        int ans = 0;
        int till = 0;
        for(int i = n-1; i >= 0; i--)
        {
            int j = m-1;
            while(j >= till) {
                if(grid[i][j] < 0) {
                    ans++;
                }
                else {
                    till = j+1;
                    break;
                }
                j--;
            }
        }
        return ans;
    }
};