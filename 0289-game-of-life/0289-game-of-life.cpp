class Solution {
public:
    void gameOfLife(vector<vector<int>>& board) {
        int r = board.size();
        int c = board[0].size();
        int dirs[8][2] = {{-1,-1},{-1,0},{-1,1},
                          {0,-1},        {0,1},
                          {1,-1},{1,0},{1,1}};
        
        for (int i = 0; i < r; ++i) {
            for (int j = 0; j < c; ++j) {
                int live = 0;
                for (auto &d : dirs) {
                    int x = i + d[0], y = j + d[1];
                    if (x >= 0 && x < r && y >= 0 && y < c)
                        live += board[x][y] & 1;
                }
                if ((board[i][j] & 1) == 1) {
                    if (live == 2 || live == 3)
                        board[i][j] |= 2;
                } else {
                    if (live == 3)
                        board[i][j] |= 2;
                }
            }
        }

        for (int i = 0; i < r; ++i)
            for (int j = 0; j < c; ++j)
                board[i][j] >>= 1;
    }
};
