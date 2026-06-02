class Solution {
public:
    int earliestFinishTime(vector<int>& lst, vector<int>& ld, vector<int>& wst, vector<int>& wd) {
        int n = lst.size();
        int m = wst.size();
        int i = 0, j = 0;
        int ans = INT_MAX;
        for(int i = 0; i < n; i++)
        {
            for(int j = 0; j < m; j++)
            {
                int timel = 0;
                int timew = 0;
                if(lst[i]+ld[i] >= wst[j]) {
                    timel += lst[i]+ld[i]+wd[j];
                }
                else if(lst[i]+ld[i] < wst[j]) {
                    timel += wd[j]+wst[j];
                }
                if(wst[j]+wd[j] >= lst[i]) {
                    timew += wst[j]+wd[j]+ld[i];
                }
                else if(wst[j]+wd[j] < lst[i]) {
                    timew += ld[i]+lst[i];
                }
                ans = min(ans, min(timel, timew));
            }
        }
        return ans;
    }
};