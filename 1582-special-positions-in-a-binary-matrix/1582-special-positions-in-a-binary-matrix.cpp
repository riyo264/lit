class Solution {
public:
    int numSpecial(vector<vector<int>>& mat) {
        int n = mat.size();
        int m = mat[0].size();
        int sp = 0;
        for(int i = 0; i < n; i++)
        {
            for(int j = 0; j < m; j++)
            {
                if(mat[i][j] == 1) {
                    bool flag = false;
                    for(int k = 0; k < n; k++) {
                        if(k != i && mat[k][j] == 1) {
                            flag = true;
                            break;
                        }
                    }
                    for(int l = 0; l < m; l++) {
                        if(l != j && mat[i][l] == 1) {
                            flag = true;
                            break;
                        }
                    }
                    if(!flag) {
                        sp++;
                    }
                }
            }
        }
        return sp;
    }
};