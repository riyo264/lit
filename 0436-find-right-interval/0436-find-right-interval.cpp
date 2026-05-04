class Solution {
public:
    vector<int> findRightInterval(vector<vector<int>>& intervals) {
        int n = intervals.size();
        vector<pair<int, int>> st;
        for(int i = 0; i < n; i++) {
            st.push_back({intervals[i][0], i});
        }
        sort(st.begin(), st.end(), [](auto a, auto b) {
            return a.first < b.first;
        });
        vector<int> ans;
        for(int i = 0; i < n; i++) {
            int end = intervals[i][1];
            int l = 0, h = n-1;
            int right = -1;
            while(l <= h) {
                int m = (l+h)/2;
                if(st[m].first < end) {
                    l = m+1;
                }
                else if(st[m].first > end) {
                    right = st[m].second;
                    h = m-1;
                }
                else {
                    right = st[m].second;
                    break;
                }
            }
            ans.push_back(right);
        }
        return ans;
    }
};