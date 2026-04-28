class Solution {
public:
    int minOperations(vector<vector<int>>& grid, int x) {
        int n = grid.size();
        int m = grid[0].size();
        int op = 0;
        int temp = grid[0][0] % x;
        vector<int> flatten;

        for(int i = 0; i < n; i++) {
            for(int j = 0; j < m; j++) {
                if(temp != grid[i][j]%x) {
                    return -1;
                }
                flatten.push_back(grid[i][j]);
            }
        }

        sort(flatten.begin(), flatten.end());
        int uni = flatten[((m*n)-1)/2];
        for(int i = 0; i < m*n; i++) {
            op += (abs(uni - flatten[i]) / x);
        }

        return op;
    }
};