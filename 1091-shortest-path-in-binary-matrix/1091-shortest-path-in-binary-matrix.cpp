class Solution {
public:
    int shortestPathBinaryMatrix(vector<vector<int>>& grid) {
        int n = grid.size();
        int m = grid[0].size();
        vector<vector<int>> copy(n, vector<int>(m, 1e9));
        if(grid[0][0] == 1 || grid[n-1][m-1] == 1) {
            return -1;
        }
        if(n == 1 && m == 1) {
            return 1;
        }
        copy[0][0] = 1;
        queue<pair<int, pair<int, int>>> q;
        q.push({1, {0, 0}});
        while(!q.empty()) 
        {
            int x = q.front().second.first;
            int y = q.front().second.second;
            int dist = q.front().first;
            q.pop();
            for(int i = -1; i <= 1; i++)
            {
                for(int j = -1; j <= 1; j++)
                {
                    int new_x = x + i;
                    int new_y = y + j;
                    int new_dist = dist + 1;
                    if(new_x == n-1 && new_y == m-1) {
                        return new_dist;
                    }
                    else if(new_x > -1 && new_x < n && new_y > -1 && new_y < m && grid[new_x][new_y] == 0) {
                        if(new_dist < copy[new_x][new_y]) {
                            copy[new_x][new_y] = new_dist;
                            q.push({new_dist, {new_x, new_y}});
                        }
                    }
                }
            }
        }
        return -1;
    }
};