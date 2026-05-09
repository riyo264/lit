class Solution {
public:
    vector<vector<int>> rotateGrid(vector<vector<int>>& grid, int k) {
        int top = 0, left = 0, bottom = grid.size()-1, right = grid[0].size()-1;
        while(top < bottom && left < right) {
            int len = bottom - top;
            int width = right - left;
            int peri = 2*(len+width);
            int rot = k % peri;
            while(rot > 0) {
                int temp = grid[top][left];
                for(int i = left; i < right; i++) {
                    grid[top][i] = grid[top][i+1];
                }
                for(int i = top; i < bottom; i++) {
                    grid[i][right] = grid[i+1][right];
                }
                for(int i = right; i > left; i--) {
                    grid[bottom][i] = grid[bottom][i-1];
                }
                for(int i = bottom; i > top; i--) {
                    grid[i][left] = grid[i-1][left];
                }
                grid[top+1][left] = temp;
                rot--;
            }
            top++;
            left++;
            right--;
            bottom--;
        }
        return grid;
    }
};