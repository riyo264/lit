class Solution {
public:
    void solve(int n, int i, vector<vector<int>>& ans) {
        if(i > n) {
            return;
        }
        if(i == 1) {
            ans.push_back({1});
            solve(n, i+1, ans);
            return;
        }
        else if(i == 2) {
            ans.push_back({1,1});
            solve(n, i+1, ans);
            return;
        }
        vector<int> row(i, 1);
        for(int j = 1; j < i-1; j++)
        {
            row[j] = (ans[ans.size()-1][j-1] + ans[ans.size()-1][j]);
        }
        ans.push_back(row);
        solve(n, i+1, ans);
    }
    vector<vector<int>> generate(int numRows) {
        vector<vector<int>> ans;
        solve(numRows, 1, ans);
        return ans;
    }
};