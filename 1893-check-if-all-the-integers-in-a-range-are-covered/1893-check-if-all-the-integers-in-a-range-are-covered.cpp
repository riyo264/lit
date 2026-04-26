class Solution {
public:
    bool isCovered(vector<vector<int>>& ranges, int left, int right) {
        for(int i = left; i <= right; i++) {
            bool flag = false;
            for(auto x : ranges) {
                int s = x[0];
                int e = x[1];
                if(i >= s && i <= e) {
                    flag = true;
                    break;
                }
            }
            if(!flag) {
                return false;
            }
        }
        return true;
    }
};