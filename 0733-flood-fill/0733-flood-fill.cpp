class Solution {
private:
    void dfs(int sr, int sc, vector<vector<int>>& result, int color, vector<int> delrow, vector<int> delcol) {
        int ini_color = result[sr][sc];
        result[sr][sc] = color;
        for(int i = 0; i < delrow.size(); i++)
        {
            int nrow = sr + delrow[i];
            int ncol = sc + delcol[i];
            if(nrow >= 0 && ncol >= 0 && nrow < result.size() && ncol < result[0].size() && result[nrow][ncol] != color && result[nrow][ncol] == ini_color) {
                dfs(nrow, ncol, result, color, delrow, delcol);
            }
        }
    }
public:
    vector<vector<int>> floodFill(vector<vector<int>>& image, int sr, int sc, int color) {
        int row = image.size();
        int col = image[0].size();
        vector<vector<int>> result = image;
        vector<int> delrow = {-1, 0, +1, 0};
        vector<int> delcol = {0, -1, 0, +1};
        dfs(sr, sc, result, color, delrow, delcol);
        return result;
    }
};