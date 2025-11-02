class Solution {
public:
    int countUnguarded(int m, int n, vector<vector<int>>& guards, vector<vector<int>>& walls) {
        vector<vector<int>> final(m, vector<int>(n, 1));
        for(int i = 0; i < guards.size(); i++)
        {
            int r = guards[i][0];
            int c = guards[i][1];
            final[r][c] = 0;
        }
        for(int i = 0; i < walls.size(); i++)
        {
            int r = walls[i][0];
            int c = walls[i][1];
            final[r][c] = -1;
        }
        vector<pair<int, int>> dirs = {{-1,0},{1,0},{0,-1},{0,1}};
        for(int i = 0; i < guards.size(); i++)
        {
            int r = guards[i][0];
            int c = guards[i][1];
            for(int j = 0; j < dirs.size(); j++)
            {
                int nr = r + dirs[j].first;
                int nc = c + dirs[j].second;
                while (nr >= 0 && nr < m && nc >= 0 && nc < n && final[nr][nc] != -1 && final[nr][nc] != 0) {
                    final[nr][nc] = -2;
                    nr += dirs[j].first;
                    nc += dirs[j].second;
                }
            }
        }
        int cnt = 0;
        for(int i = 0; i < m; i++)
        {
            for(int j = 0; j < n; j++)
            {
                if(final[i][j] == 1) {
                    cnt++;
                }
            }
        }
        return cnt;
    }
};