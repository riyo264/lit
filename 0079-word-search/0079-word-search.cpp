class Solution {
public:
    vector<int> dr = {-1, 0, 1, 0};
    vector<int> dc = {0, -1, 0, 1};

    bool solve(vector<vector<char>>& board, string& word, int i, int j, int k, vector<vector<bool>>& vis) {
        if(k == word.size()) return true;
        int n = board.size(), m = board[0].size();
        if(i < 0 || i >= n || j < 0 || j >= m || vis[i][j] || board[i][j] != word[k])
            return false;
        if(k == word.size() - 1)
            return true;
        vis[i][j] = true;

        for(int d = 0; d < 4; d++) {
            int nr = i + dr[d];
            int nc = j + dc[d];
            if(solve(board, word, nr, nc, k + 1, vis)) {
                vis[i][j] = false;
                return true;
            }
        }
        vis[i][j] = false; 
        return false;
    }

    bool exist(vector<vector<char>>& board, string word) {
        int n = board.size(), m = board[0].size();

        vector<vector<bool>> vis(n, vector<bool>(m, false));

        for(int i = 0; i < n; i++) {
            for(int j = 0; j < m; j++) {
                if(board[i][j] == word[0]) {
                    if(solve(board, word, i, j, 0, vis))
                        return true;
                }
            }
        }
        return false;
    }
};