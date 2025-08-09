class Solution {
public:
    void setZeroes(vector<vector<int>>& matrix) {
        int row= -1;
        int col = -1;
        queue<pair<int, int>> Q;
        for(int i = 0; i < matrix.size(); i++)
        {
            for(int j = 0; j < matrix[0].size(); j++)
            {
                if(matrix[i][j] == 0) {
                    Q.push({i, j});
                }
            }
        }
        while(!Q.empty())
        {
            row = Q.front().first;
            col = Q.front().second;
            Q.pop();
            for(int i = 0; i < matrix.size(); i++)
            {
                matrix[i][col] = 0;
            }
            for(int i = 0; i < matrix[0].size(); i++)
            {
                matrix[row][i] = 0;
            }
        }
        return;
    }
};