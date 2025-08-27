class Solution {
public:
    int findTheCity(int n, vector<vector<int>>& edges, int distanceThreshold) {
        vector<vector<int>> dist(n, vector<int>(n, INT_MAX));
        for(auto it : edges) 
        {
            dist[it[0]][it[1]] = it[2];
            dist[it[1]][it[0]] = it[2];
        }
        for(int i = 0; i < n; i++)
        {
            dist[i][i] = 0;
        }
        for(int k = 0; k < n; k++) 
        {
            for(int j = 0; j < n; j++) 
            {
                for(int i = 0; i < n; i++)
                {
                    if(dist[j][k] == INT_MAX || dist[k][i] == INT_MAX) continue;
                    dist[j][i] = min(dist[j][i], dist[j][k] + dist[k][i]);
                }
            }
        }
        int cityMin = n;
        int city = -1;
        for(int i = 0; i < n; i++)
        {
            int neighbours = 0;
            for(int j = 0; j < n; j++)
            {
                if(dist[i][j] <= distanceThreshold) {
                    neighbours++;
                }
            }
            if(cityMin >= neighbours) {
                cityMin = neighbours;
                city = i;
            }
        } 
        return city;
    }
};