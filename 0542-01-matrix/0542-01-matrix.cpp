class Solution {
public:
    vector<vector<int>> updateMatrix(vector<vector<int>>& mat) {
        vector<vector<int>> result = mat;
        int n = mat.size();
        int m = mat[0].size();
        vector<vector<int>> vis(n, vector<int>(m, 0));
        queue<pair<pair<int, int>, int>> Q;
        vector<int> delrow = {-1, 0, 1, 0};
        vector<int> delcol = {0, 1, 0, -1};
        for(int i = 0; i < n; i++)
        {
            for(int j = 0; j < m; j++) 
            {
                if(mat[i][j] == 0) {
                    Q.push({{i, j}, 0});
                    vis[i][j] = 1;
                }
            }
        }
        while(!Q.empty())
        {
            int row = Q.front().first.first;
            int col = Q.front().first.second;
            int dis = Q.front().second;
            Q.pop();
            result[row][col] = dis;
            for(int i = 0; i < 4; i++)
            {
                int nrow = row + delrow[i];
                int ncol = col + delcol[i];
                if(nrow > -1 && ncol > -1 && nrow < n && ncol < m && vis[nrow][ncol] == 0) {
                    vis[nrow][ncol] = 1;
                    Q.push({{nrow, ncol}, dis+1});
                }
            }
        }
        return result;
    }
};