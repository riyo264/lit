class Solution {
public:
    int minCost(vector<vector<int>>& grid) {
        int m = grid.size(), n = grid[0].size();
        vector<vector<int>> dist(m, vector<int>(n, INT_MAX));
        deque<pair<int,int>> dq;
        vector<vector<int>> dir = {{0,1}, {0,-1}, {1,0}, {-1,0}};
        dq.push_front({0,0});
        dist[0][0] = 0;
        while(!dq.empty()) {
            auto [x,y] = dq.front();
            dq.pop_front();
            for(int i = 0; i < 4; i++) {
                int nx = x + dir[i][0];
                int ny = y + dir[i][1];
                if(nx < 0 || ny < 0 || nx >= m || ny >= n) continue;
                int cost;
                if(grid[x][y] == i+1){  //This if condition shows when "i == 0 dir gives {0,1} i.e. moving right costs 0 so if grid[x][y]==1 i.e. i+1 cost=0"
                    cost = 0;
                }
                else {
                    cost = 1;
                }
                if(dist[x][y] + cost < dist[nx][ny]) {
                    dist[nx][ny] = dist[x][y] + cost;
                    if(cost == 0)
                        dq.push_front({nx, ny});
                    else
                        dq.push_back({nx, ny});
                }
            }
        }
        return dist[m-1][n-1];
    }
};