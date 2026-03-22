class Solution {
public:
    bool findRotation(vector<vector<int>>& mat, vector<vector<int>>& target) {
        int n = mat.size();
        int m = mat[0].size();
        vector<vector<int>> temp(n, vector<int>(m));
        for(int k = 0; k < 4; k++)
        {
            temp = mat;
            bool match = true;
            for(int i = 0; i < n; i++)
            {
                bool flag = true;
                for(int j = 0; j < m; j++)
                {
                    if(temp[i][j] != target[i][j]) {
                        flag = false;
                        break;
                    }
                }
                if(!flag) {
                    match = false;
                    break;
                }
            }
            if(match) {
                return true;
            }
            for(int i = 0; i < n; i++)
            {
                for(int j = 0; j < m; j++)
                {
                    temp[j][(m-1)-i] = mat[i][j];
                }
            }
            mat = temp;
        }
        return false;
    }
};