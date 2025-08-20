class Solution {
public:
    int minimumEffortPath(vector<vector<int>>& heights) {
        priority_queue<pair<int, pair<int, int>>, vector<pair<int, pair<int, int>> >, greater<pair<int, pair<int, int>>>> pq;

        int n = heights.size();
        int m = heights[0].size();
        vector<vector<int>> dist(n , vector<int>(m, 1e9));
        dist[0][0] = 0;
        vector<int> dr = {-1, 0, 1, 0};
        vector<int> dc = {0, -1, 0, 1};
        pq.push({0, {0, 0}});
        while(!pq.empty())
        {
            auto it = pq.top();
            pq.pop();
            int diff = it.first;
            int r = it.second.first;
            int c = it.second.second;
            if(r == n-1 && c == m-1) {
                return diff;
            }
            for(int i = 0; i < 4; i++) 
            {
                int new_r = r + dr[i];
                int new_c = c + dc[i];
                if(new_r >= 0 && new_c >= 0 && new_r < n && new_c < m) {
                    int new_effort = max(abs(heights[r][c] - heights[new_r][new_c]), diff);
                        if(new_effort < dist[new_r][new_c]) {
                        dist[new_r][new_c] = new_effort;
                        pq.push({new_effort,{new_r, new_c}});
                    }
                }
            }
        }
        return 0;
    }
};