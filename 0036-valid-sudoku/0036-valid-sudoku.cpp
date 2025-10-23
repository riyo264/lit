class Solution {
public:
    bool isValidSudoku(vector<vector<char>>& board) {
        int row = board.size();
        int col = board[0].size();
        for(int i = 0; i < row; i++)
        {
            unordered_map<int, int> mpp;
            for(int j = 0; j < col; j++)
            {
                if(mpp[board[i][j]] > 0) {
                    return false;
                }
                if(board[i][j] != '.') {
                    mpp[board[i][j]]++;
                }
            }
        }
        for(int i = 0; i < col; i++)
        {
            unordered_map<int, int> mpp;
            for(int j = 0; j < row; j++)
            {
                if(mpp[board[j][i]] > 0) {
                    return false;
                }
                if(board[j][i] != '.') {
                    mpp[board[j][i]]++;
                }
            }
        }
        for(int i = 0; i < 3; i++)
        {
            for(int j = 0; j < 3; j++)
            {
                unordered_map<int, int> mpp;
                for(int k = 0; k < 3; k++) {
                    for(int l = 0; l < 3; l++) {
                        if(mpp[board[3 * i + k][3 * j + l]] > 0) {
                            return false;
                        }
                        if(board[3 * i + k][3 * j + l] != '.') {
                            mpp[board[3 * i + k][3 * j + l]]++;
                        }
                    }
                }
            }
        }
        return true;
    }
};