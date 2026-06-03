class Solution {
public:
    int earliestFinishTime(vector<int>& lst, vector<int>& ld, vector<int>& wst, vector<int>& wd) {
        int l = INT_MAX, w = INT_MAX, minL = INT_MAX, minW = INT_MAX;
        int n = lst.size(), m = wst.size();

        for (int i = 0; i < n; i++)
            l = min(l, lst[i] + ld[i]);

        for (int i = 0; i < m; i++) {
            w = min(w, wst[i] + wd[i]);
            minL = min(minL, max(wst[i], l) + wd[i]);
        }

        for (int i = 0; i < n; i++)
            minW = min(minW, max(lst[i], w) + ld[i]);

        return min(minW, minL);
    }
};