class Solution {
public:
    void rotate(vector<vector<int>>& matrix) {
        int n = matrix.size()-1;
        int m = matrix[0].size()-1;
        for(int i = 0; i < matrix.size()-1; i++)
        {
            for(int j = i+1; j < matrix[0].size(); j++)
            {
                    matrix[i][j] = matrix[j][i] ^ matrix[i][j];
                    matrix[j][i] = matrix[j][i] ^ matrix[i][j];
                    matrix[i][j] = matrix[j][i] ^ matrix[i][j];
            }
        }
        for(int i = 0; i < matrix.size(); i++)
        {
            reverse(matrix[i].begin(), matrix[i].end());
        }
        return;
    }
};