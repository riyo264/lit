class Solution {
public:
    vector<vector<int>> minAbsDiff(vector<vector<int>>& grid, int k) {
        int n = grid.size();
        int m = grid[0].size();
        vector<vector<int>> ans(n-k+1, vector<int>(m-k+1, 0));
        for(int i = 0; i <= n-k; i++)
        {
            for(int j = 0; j <= m-k; j++)
            {
                vector<int> temp;
                for(int r = i; r < i+k; r++)
                {
                    for(int c = j; c < j+k; c++)
                    {
                        temp.push_back(grid[r][c]);
                    }
                }
                sort(temp.begin(), temp.end());
                int mini = INT_MAX;
                if(temp.size() == 1) {
                    ans[i][j] = 0;
                    continue;
                }
                for(int i = 1; i < temp.size(); i++) {
                    if(temp[i] != temp[i-1]) {
                        mini = min(mini, abs(temp[i]-temp[i-1]));
                    }
                }
                if(mini != INT_MAX) {
                    ans[i][j] = mini;   
                }
            }
        }
        return ans;
    }
};