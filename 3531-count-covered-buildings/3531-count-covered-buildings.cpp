class Solution {
public:
    int countCoveredBuildings(int n, vector<vector<int>>& buildings) {
        unordered_map<int, vector<int>> col;
        unordered_map<int, vector<int>> row;
        for (auto &b : buildings) {
            col[b[0]].push_back(b[1]);
            row[b[1]].push_back(b[0]);
        }
        for (auto &p : col) sort(p.second.begin(), p.second.end());
        for (auto &p : row) sort(p.second.begin(), p.second.end());
        int count = 0;
        for (auto &b : buildings) {
            int x = b[0], y = b[1];
            auto &ys = col[x];
            auto &xs = row[y];
            if (y != ys.front() && y != ys.back() && x != xs.front() && x != xs.back())
                count++;
        }
        return count;
    }
};
