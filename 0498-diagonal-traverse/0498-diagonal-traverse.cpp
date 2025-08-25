class Solution {
public:
    vector<int> findDiagonalOrder(vector<vector<int>>& mat) {
        int n = mat.size();
        int m = mat[0].size();
        vector<int> dia;
        bool flag = false;

        for (int i = 0; i < n; i++) {
            int r = i, c = 0;
            vector<int> temp;
            while (r >= 0 && c < m) { temp.push_back(mat[r][c]); r--; c++; }
            if (flag) reverse(temp.begin(), temp.end());
            dia.insert(dia.end(), temp.begin(), temp.end());
            flag = !flag;
        }

        for (int j = 1; j < m; j++) {
            int r = n - 1, c = j;
            vector<int> temp;
            while (r >= 0 && c < m) { temp.push_back(mat[r][c]); r--; c++; }
            if (flag) reverse(temp.begin(), temp.end());
            dia.insert(dia.end(), temp.begin(), temp.end());
            flag = !flag;
        }

        return dia;
    }
};
