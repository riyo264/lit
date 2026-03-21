class Solution {
public:
    vector<vector<int>> reverseSubmatrix(vector<vector<int>>& grid, int x, int y, int k) {
        int f = x;
        int b = x+k-1;
        while(b > f) {
            for(int j = y; j < y+k; j++)
            {
                swap(grid[f][j], grid[b][j]);
            }
            f++;
            b--;
        }
        return grid;
    }
};