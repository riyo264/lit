class Solution {
public:
    vector<vector<char>> rotateTheBox(vector<vector<char>>& boxGrid) {
        int n = boxGrid.size();
        int m = boxGrid[0].size();
        vector<vector<char>> ans(m, vector<char>(n));
        for(int i = 0; i < n; i++)
        {
            int k = m-1;
            int l = -1;
            int r = -1;
            while(k > 0) 
            {
                if(boxGrid[i][k] == '.' && -1 == l && -1 == r) {
                    l = k;
                    r = k;
                }
                if(boxGrid[i][k] == '.' && boxGrid[i][k-1] == '.') {
                    l--;
                }
                else if(boxGrid[i][k] == '.' && boxGrid[i][k-1] == '*') {
                    l = -1;
                    r = -1;
                }
                else if(boxGrid[i][k] == '.' && boxGrid[i][k-1] == '#') {
                    swap(boxGrid[i][k-1], boxGrid[i][r]);
                    l--;
                    r--;
                }
                k--;
            }
        }
        for(int i = 0; i < n; i++) 
        {
            for(int j = 0; j < m; j++)
            {
                ans[j][n-1-i] = boxGrid[i][j];
            }
        }
        return ans;
    }
};