class Solution {
public:
    unordered_map<string, vector<char>> mpp;
    bool dfs(string bottom) {
        if (bottom.size() == 1) return true;
        vector<string> nextRows;
        buildNextRows(bottom, 0, "", nextRows);
        for (auto &row : nextRows) {
            if (dfs(row)) return true;
        }
        return false;
    }
    void buildNextRows(string &bottom, int idx, string cur, vector<string> &res) {
        if (idx == bottom.size() - 1) {
            res.push_back(cur);
            return;
        }
        string key = bottom.substr(idx, 2);
        if (!mpp.count(key)) return;
        for (char c : mpp[key]) {
            buildNextRows(bottom, idx + 1, cur + c, res);
        }
    }
    bool pyramidTransition(string bottom, vector<string>& allowed) {
        for (auto &s : allowed) {
            mpp[s.substr(0, 2)].push_back(s[2]);
        }
        return dfs(bottom);
    }
};
