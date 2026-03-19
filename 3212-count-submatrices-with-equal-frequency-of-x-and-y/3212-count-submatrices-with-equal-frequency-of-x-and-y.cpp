class Solution {
public:
    int numberOfSubmatrices(vector<vector<char>>& grid) {
        int n = grid.size();
        int m = grid[0].size();
        int x = 0, y = 0;
        vector<vector<pair<int, int>>> pref(n, vector<pair<int, int>>(m));
        for(int i = 0; i < n; i++)
        {
            for(int j = 0; j < m; j++)
            {
                if(grid[i][j] == 'X') {
                    x++;
                    pref[i][j] = {x, y};
                }
                else if(grid[i][j] == 'Y') {
                    y++;
                    pref[i][j] = {x, y};
                }
                else {
                    pref[i][j] = {x, y};
                }
            }
            x = 0;
            y = 0;
        }
        for(int j = 0; j < m; j++)
        {
            for(int i = 1; i < n; i++)
            {
                pref[i][j].first += pref[i-1][j].first;
                pref[i][j].second += pref[i-1][j].second;
            }
        }
        int ans = 0;
        for(int i = 0; i < n; i++)
        {
            for(auto x : pref[i]) {
                if(x.first == x.second && x.first != 0) {
                    ans++;
                }
            }
        }
        return ans;
    }
};