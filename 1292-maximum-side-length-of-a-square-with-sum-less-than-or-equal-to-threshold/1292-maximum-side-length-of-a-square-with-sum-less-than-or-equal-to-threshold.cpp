class Solution {
public:
    bool isValid(vector<vector<int>>& pref, int len, int threshold) {
        int n = pref.size();
        int m = pref[0].size(); 
        for(int i = len-1; i < n; i++)
        {
            for(int j = len-1; j < m; j++)
            {
                int x = i - len + 1;
                int y = j - len + 1;
                int sum = pref[i][j] - (x > 0 ? pref[x - 1][j] : 0) - (y > 0 ? pref[i][y - 1] : 0) + (x > 0 && y > 0 ? pref[x - 1][y - 1] : 0);
                if(sum <= threshold) {
                    return true;
                }
            }
        }
        return false;
    }
    int maxSideLength(vector<vector<int>>& mat, int threshold) {
        int n = mat.size();
        int m = mat[0].size();
        bool flag = false;
        for(int i = 0; i < n; i++)
        {
            for(int j = 0; j < m; j++)
            {
                if(mat[i][j] <= threshold) {
                    flag = true;
                }
            }
        }
        if(flag == false) {
            return 0;
        }
        vector<vector<int>> pref = mat;
        for(int i = 0; i < n; i++)
        {
            for(int j = 1; j < m; j++)
            {
                pref[i][j] += pref[i][j-1];
            }
        }
        for(int j = 0; j < m; j++)
        {
            for(int i = 1; i < n; i++)
            {
                pref[i][j] += pref[i-1][j];
            }
        }
        int l = 1;
        int h = min(n, m);
        int ans = 0;
        while(l <= h) 
        {
            int m = (l+h)/2;
            if(isValid(pref, m, threshold)) {
                ans = m;
                l = m + 1;
            }
            else {
                h = m - 1;
            }
        }
        return ans;
    }
};