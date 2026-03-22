class Solution {
public:
    bool findRotation(vector<vector<int>>& mat, vector<vector<int>>& target) {
        int n = mat.size();
        int m = mat[0].size();
        vector<vector<int>> temp(n, vector<int>(m));
        if(mat == target) {
            return true;
        } 
        for(int k = 0; k < 3; k++)
        {
            for(int i = 0; i < n; i++)
            {
                for(int j = 0; j < m; j++)
                {
                    temp[j][(m-1)-i] = mat[i][j];
                }
            }
            if(temp == target) {
                return true;
            }
            mat = temp;
        }
        return false;
    }
};