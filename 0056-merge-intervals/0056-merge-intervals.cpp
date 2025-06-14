class Solution {
public:
    static bool comp(vector<int>& i1, vector<int>& i2)
    {
        if(i1[0] < i2[0])
        {
            return true;
        }
        else if(i1[0]==i2[0] && i1[1] < i2[1])
        {
            return true;
        }
        return false;
    }

    vector<vector<int>> merge(vector<vector<int>>& intervals) {
        vector<vector<int> > final;
        int n = intervals.size();
        sort(intervals.begin(), intervals.end(), comp);
        if(n == 1)
        {
            final.push_back(intervals[0]);
        }
        else
        {
        for(int i = 1; i < n; i++){
        if(intervals[i][0] > intervals[i-1][1] && i != n-1)
        {
            if(final.empty()==1 || final[final.size()-1][1]<intervals[i-1][0])
            {
                final.push_back(intervals[i-1]);
            }
        }
        else if(intervals[i][0] <= intervals[i-1][1])
        {
            intervals[i][0] = min(intervals[i][0], intervals[i-1][0]);
            intervals[i][1] = max(intervals[i][1], intervals[i-1][1]);
            if(i == n-1 || (intervals[i+1][0] > intervals[i][1] && i!=n-2))
            {
                final.push_back(intervals[i]);
            }
        }
        else if(intervals[i][0] > intervals[i-1][1] && i == n-1)
        {
            final.push_back(intervals[i-1]);
            final.push_back(intervals[i]);
        }
        }
        }
        return final;
    }
};