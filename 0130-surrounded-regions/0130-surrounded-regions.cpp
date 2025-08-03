class Solution {
private:
    void dfs(int row, int col, vector<vector<char>>& board, vector<vector<int>>& vis) {
        vis[row][col] = 1;
        vector<int> delrow = {1, 0, -1, 0};
        vector<int> delcol = {0, 1, 0, -1};
            for(int i = 0; i < 4; i++) 
            {
                int nrow = row + delrow[i];
                int ncol = col + delcol[i];
                if(nrow > -1 && ncol > -1 && nrow < board.size() && ncol < board[0].size() && vis[nrow] [ncol] == 0 && board[nrow][ncol] == 'O') {
                    dfs(nrow, ncol, board, vis);
                }
            }
    }
public:
    void solve(vector<vector<char>>& board) {
        int n = board.size();
        int m = board[0].size();
        vector<vector<int>> vis(n, vector<int>(m, 0));
        for(int i = 0; i < n; i++)
        {
            if(vis[i][0] == 0 && board[i][0] == 'O') {
                dfs(i, 0, board, vis);
            }
            if(vis[i][m-1] == 0 && board[i][m-1] == 'O') {
                dfs(i, m-1, board, vis);
            }
        }
        for(int i = 0; i < m; i++)
        {
            if(vis[0][i] == 0 && board[0][i] == 'O') {
                dfs(0, i, board, vis);
            }
            if(vis[n-1][i] == 0 && board[n-1][i] == 'O') {
                dfs(n-1, i, board, vis);
            }
        }
        for(int i = 1; i < n-1; i++)
        {
            for(int j = 1; j < m-1; j++) 
            {
                if(vis[i][j] == 0 && board[i][j] == 'O') {
                    board[i][j] = 'X';
                }
            }
        }
    }
};