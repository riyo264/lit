class Solution {
public:
    int orangesRotting(vector<vector<int>>& grid) {
        int row = grid.size();
        int col = grid[0].size();
        int t = 0;
        int cnt = 0;
        vector<vector<int>> vis = grid;
        vector<int> delrow = {-1, 0, +1, 0};
        vector<int> delcol = {0, +1, 0, -1};
        queue<pair<pair<int, int>, int>> Q;
        for(int i = 0; i < row; i++)
        {
            for(int j = 0; j < col; j++) 
            {
                if(vis[i][j] == 2) {
                    Q.push({{i, j}, 0});
                }
                else if(vis[i][j] == 1) {
                    cnt++;
                }
            }
        }
        if(cnt == 0) {
            return t;
        }
        while(!Q.empty()) 
        {
            int n = Q.front().first.first;
            int m = Q.front().first.second;
            t = Q.front().second;
            Q.pop();
            for(int i = 0; i < 4; i++) 
            {
                int nrow = n + delrow[i];
                int ncol = m + delcol[i];
                if(nrow >= 0 && nrow < row && ncol > -1 && ncol < col) {
                    if(vis[nrow][ncol] == 1) {
                        vis[nrow][ncol] = 2;
                        Q.push({{nrow, ncol}, t+1});
                    } 
                }
            }
        }
        for(int i = 0; i < row; i++)
        {
            for(int j = 0; j < col; j++) 
            {
                if(vis[i][j] == 1) {
                    t = -1;
                    break;
                }
            }
            if(t == -1) {
                break;
            }
        }
        return t;

    }
};